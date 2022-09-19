/**
 * @file	trxos.c
 * @author	helder
 * @brief	Light RTOS source file.
 */

/* Includes go here.	*/
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#include <trxos.h>
#include <systick.h>
#include <sleep_timer.h>
#include <clk.h>
#include <CortexM.h>


/* typedefs go here.	*/

/* Consts go here.	*/

/* #defines go here.	*/
#define TRXOS_NUMBER_OF_THREADS     10
#define TRXOS_STACK_SIZE            100
#define TRXOS_PERIOD_uS             10000 /* Period in uS at wich we trigger the
                                           * scheduller. */
#define TRXOS_SLEEP_TIMER_PERIOD_uS 1000

/* static vars go here.	*/
/** Linked List for the main threads. */
LL_list_t g_main_thread_list        = { NULL,   /* head     */
                                        NULL,   /* current  */
                                        NULL,   /* tail     */
                                        0,      /* length   */
                                        0};     /* id_cnt   */

/** Linked list for the periodic threads. */
LL_list_t g_periodic_thread_list    = { NULL,   /* head     */
                                        NULL,   /* current  */
                                        NULL,   /* tail     */
                                        0,      /* length   */
                                        0};     /* id_cnt   */

/** Linked list for the blocked threads. */
LL_list_t g_blocked_thread_list     = { NULL,   /* head     */
                                        NULL,   /* current  */
                                        NULL,   /* tail     */
                                        0,      /* length   */
                                        0};     /* id_cnt   */

/** Linked list for the blocked threads. */
LL_list_t g_asleep_thread_list      = { NULL,   /* head     */
                                        NULL,   /* current  */
                                        NULL,   /* tail     */
                                        0,      /* length   */
                                        0};     /* id_cnt   */

/** Local variable holding the TCBs of the threads. */                                        
TCB_T _tcbs[TRXOS_NUMBER_OF_THREADS];

/** Allocating memory for the threads stacks. */
uint32_t _stacks[TRXOS_NUMBER_OF_THREADS][TRXOS_STACK_SIZE];

/** Current running thread. */
TCB_T *_runPt;

/** 
 *  This variable informs about an OS suspend command.
 *  It is used to only allow main threads to be triggered when the SysTick is
 *  being interrupted by SW (OS_suspend).
 *  This trick will keep the timing right.
 */
static uint8_t _suspend_flag    = false;
static uint8_t _blocked_flag    = false;
static uint8_t _sleep_flag      = false;

/** System clock. */
uint32_t g_system_clk_Hz        = 3000000;
uint32_t g_subsystem_clk_Hz     = 3000000;

/* static function declarations go here.	*/
/**
 * @brief Initialize the stack.
 * 
 * This function intialize the stack *SP (SP of a given TCB) and set its PC
 * to the given *PC (pointer to the init of the TCB code.).
 * 
 * @param SP Pointer to the memory that will be used as stack of the TCB.
 * @param PC Pointer to the function associated to the TCB.
 * @return
 */
static void _Init_TCB_stack(uint32_t *SP, void(*PC)(void));

/**
 * @brief Initialze TCB.
 * 
 * @param tcb_pt Pointer to the TCB.
 * @param SP Associated Stack Pointer.
 * @param period_ticks Period IN THE CASE of a periodic thread in OS ticks.
 * @param priority Associated priority within the OS.
 * @param thread Pointer to the assciated function.
 * @return void.
 */ 
static void _Init_TCB(  TCB_T *tcb_pt, 
                        uint32_t* SP, 
                        uint32_t period_ticks, 
                        uint8_t priority,                        
                        void(*thread)(void));

/**
 * @brief Run next periodic thread if there is any due to run.
 * 
 * @return void.
 */ 
static void _run_periodic_threads(void);

/**
 * @brief This function converts uS into OS ticks.
 * 
 * @param time_uS Time in uS.
 * @reutnr Number of OS ticks. 
 */
static uint32_t _time_uS_to_OS_ticks(uint32_t time_uS);

/** 
 * @brief Dummy thread to keep the OS running.
 * 
 * This thread must never been removed. If the OS run out of main threads,
 * it is over.
 * 
 * @return void.
 */
static void _main_dummy_thread(void);

/**
 * @brief Boot Up OS and triggers it.
 * 
 * @return void.
 */ 
void TRXOS_start_OS(void);

void TRXOS_start(void) {
    LL_init(&g_blocked_thread_list, NULL);
    LL_init(&g_asleep_thread_list, NULL);
    TRXOS_add_main_thread(&_main_dummy_thread, 0);    
    CLK_set_clk_speed_level(255, &g_system_clk_Hz, &g_subsystem_clk_Hz);
    SLEEP_TIMER_init(TRXOS_SLEEP_TIMER_PERIOD_uS);
    SYSTICK_init(TRXOS_PERIOD_uS);
    TRXOS_start_OS();
}

/**
 * @brief High-Level part of the OS scheduler.
 * 
 * This function is part of the SysTick_handler.
 * To ease part of the scheduling part of the context switch is done in C here.
 *
 * This function triggers the next periodic thread if needed.
 * If no periodic thread is due to run, next main thread is selected to run.
 * 
 * @return void.
 */
void TRXOS_Scheduler(void){
    if(true == _blocked_flag){
        LL_move_node_to_another_list(
            &g_main_thread_list, 
            &g_blocked_thread_list,
            _runPt->node.id);
        _blocked_flag = false;
    }
    if(true == _sleep_flag){
        LL_move_node_to_another_list(
            &g_main_thread_list,
            &g_asleep_thread_list,
            _runPt->node.id);
        _sleep_flag = false;
    }
    if(false == _suspend_flag){
        _run_periodic_threads();
    }
    _suspend_flag = false;
    LL_next(&g_main_thread_list);
}

static void _run_periodic_threads(void){
    void(*thread)(void) = NULL;

    /* 
     * Go through list decreasing the threads time counter. 
     * If the thread time counter reach 0, run it.
     */
    for(int i = LL_get_length(&g_periodic_thread_list); i > 0; i--){
        TCB_T* current_thread = (TCB_T*)LL_get_current(&g_periodic_thread_list);
        current_thread->current_time_ticks--;
        if(0 == current_thread->current_time_ticks){
            current_thread->current_time_ticks = current_thread->reload_time_ticks;
            thread = current_thread->thread;
            thread();
        }
        LL_next(&g_periodic_thread_list);
    }
}

void TRXOS_add_main_thread(void(*thread)(void), uint8_t priority) {
    assert(NULL != thread);

    int32_t main_thread_number      = LL_get_length(&g_main_thread_list);
    int32_t periodic_thread_number  = LL_get_length(&g_periodic_thread_list);
    int32_t total_thread_number     = main_thread_number +
                                        periodic_thread_number;                        

    _Init_TCB_stack(&_stacks[total_thread_number][0], thread);
    _Init_TCB(  &_tcbs[total_thread_number], 
                &_stacks[total_thread_number][TRXOS_STACK_SIZE - 16], 
                0, 
                priority,
                NULL);
    /* 
     * Check if the length in the if should be just the lenght of the 
     * g_main_thread_list ¡!
     */
    if(0 == main_thread_number){
        LL_init(&g_main_thread_list, (LL_node_t*)&_tcbs[total_thread_number]);
        _runPt = (TCB_T*)LL_get_current(&g_main_thread_list);
    }
    else{
        LL_add_to_tail(&g_main_thread_list, (LL_node_t*)&_tcbs[total_thread_number]);
    }
}

void TRXOS_add_periodic_thread( void(*thread)(void), 
                                uint32_t period_uS, 
                                uint8_t priority){
    assert(NULL != thread);

    int32_t main_thread_number      = LL_get_length(&g_main_thread_list);
    int32_t periodic_thread_number  = LL_get_length(&g_periodic_thread_list);
    int32_t total_thread_number     = main_thread_number +
                                        periodic_thread_number;

    _Init_TCB_stack(&_stacks[total_thread_number][0], thread);
    _Init_TCB(  &_tcbs[total_thread_number], 
                &_stacks[total_thread_number][TRXOS_STACK_SIZE - 16], 
                _time_uS_to_OS_ticks(period_uS),
                priority,
                thread);

    if(0 == periodic_thread_number){
        LL_init(
            &g_periodic_thread_list, 
            (LL_node_t*)&_tcbs[total_thread_number]);
    }
    else{
        LL_add_to_tail(
            &g_periodic_thread_list, 
            (LL_node_t*)&_tcbs[total_thread_number]);
    }
}

void TRXOS_suspend(void){
    _suspend_flag = true;
    INTCTRL = 0x04000000; // trigger SysTick
}

/* static function implementation go here.	*/
static void _Init_TCB_stack(uint32_t *SP, void(*PC)(void)){
    SP[TRXOS_STACK_SIZE - 1] = 0x01000000;       /* PSR: set T-bit. */
    SP[TRXOS_STACK_SIZE - 2] = (uint32_t)PC;     /* PC   */
    /* SP[TRXOS_STACK_SIZE - 3] -> R14    */
    /* SP[TRXOS_STACK_SIZE - 4] -> R12    */
    /* SP[TRXOS_STACK_SIZE - 5] -> R3     */
    /* SP[TRXOS_STACK_SIZE - 6] -> R2     */
    /* SP[TRXOS_STACK_SIZE - 7] -> R1     */
    /* SP[TRXOS_STACK_SIZE - 8] -> R0     */
    /* SP[TRXOS_STACK_SIZE - 9] -> R11    */
    /* SP[TRXOS_STACK_SIZE - 10] -> R10   */
    /* SP[TRXOS_STACK_SIZE - 11] -> R9    */
    /* SP[TRXOS_STACK_SIZE - 12] -> R8    */
    /* SP[TRXOS_STACK_SIZE - 13] -> R7    */
    /* SP[TRXOS_STACK_SIZE - 14] -> R6    */
    /* SP[TRXOS_STACK_SIZE - 15] -> R5    */
    /* SP[TRXOS_STACK_SIZE - 16] -> R4    */
}

static void _Init_TCB(  TCB_T *tcb_pt, 
                        uint32_t* SP, 
                        uint32_t period_ticks, 
                        uint8_t priority,
                        void(*thread)(void)){
    tcb_pt->SP                  = SP;
    tcb_pt->reload_time_ticks  = period_ticks;
    tcb_pt->current_time_ticks = tcb_pt->reload_time_ticks;
    tcb_pt->priority            = priority;
    tcb_pt->thread              = thread;
    tcb_pt->blocked             = NULL;
}

static uint32_t _time_uS_to_OS_ticks(uint32_t time_uS){
    return time_uS / TRXOS_PERIOD_uS;
}

static void _main_dummy_thread(void){
    while(0 == 0){
        ;
    }
}

void TRXOS_enable_interrupts(void){
    __asm("CPSIE  I");
}

void TRXOS_disable_interrupts(void){
    __asm("CPSID  I");
}

void TRXOS_block(TCB_T* p_tcb, SEMAPHORE_semaphore_t* p_semaphore){
        p_tcb->blocked  = p_semaphore;
        _blocked_flag   = true;
}

void TRXOS_unblock(SEMAPHORE_semaphore_t* p_semaphore){

    LL_node_t* node = LL_get_head(&g_blocked_thread_list);
    TCB_T* thread   = (TCB_T*)node;
    for(int i = 0; i < LL_get_length(&g_blocked_thread_list); i++){
        if(p_semaphore == thread->blocked){
            LL_move_node_to_another_list(
                &g_blocked_thread_list,
                &g_main_thread_list,
                thread->node.id);
            thread->blocked = NULL;
            break;
        }
        node    = node->next;
        thread  = (TCB_T*)node;
    }
}

void TRXOS_decrement_asleep_threads_counter(void){
    int32_t length = LL_get_length(&g_asleep_thread_list);

    if(0 < length){
        TCB_T* thread = (TCB_T*)LL_get_head(&g_asleep_thread_list);
        for(int i = 0; i < length; i++){
            if(0 == --thread->sleep_counter){
                LL_move_node_to_another_list(
                    &g_asleep_thread_list,
                    &g_main_thread_list,
                    thread->node.id);
            }
            thread = (TCB_T*)thread->node.next;
        }
    } 
}

void TRXOS_sleep(uint32_t time_uS){
    _runPt->sleep_counter = (int32_t)(time_uS / TRXOS_SLEEP_TIMER_PERIOD_uS);
    _sleep_flag = true;
    TRXOS_suspend();
}

void TRX_request_clk_speed_level(uint8_t clk_speed_level){
    CLK_set_clk_speed_level(
        clk_speed_level, 
        &g_system_clk_Hz, 
        &g_subsystem_clk_Hz);
    SYSTICK_init(TRXOS_PERIOD_uS);
    SLEEP_TIMER_init(TRXOS_SLEEP_TIMER_PERIOD_uS);
}

/* end of file */
