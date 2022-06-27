/**
 * @file	trxos.c
 * @author	helder
 * @brief	Light RTOS source file.
 */

/* Includes go here.	*/
#include <trxos.h>
#include <ll.h>
#include <mail.h>
#include <systick.h>
#include <stddef.h>
#include <assert.h>

/* typedefs go here.	*/

/**
 * @brief Trhead Control Block structure.
 * 
 * The TCB forms part of a linked list. To do so, we use the LL module.
 * The first element of the TCB must be a LL_node_t in order to get track of
 * it.
 */
typedef struct TCB TCB_T;
struct TCB{
    /** Node structure to get the TCB on a linked list.*/
    LL_node_t   node;
    /** Stack Pointer of the TCB. */
    uint32_t*   SP;
    /** Priority within the OS. */
    uint8_t     priority;
    /** In the case of periodic threads, period in ms. */
    uint32_t    reload_time_ms;
    /** In the case of periodic threads, time from the last trigger. */
    uint32_t    current_time;
    /** Pointer to the code (function) of this thread. */
    void(*thread)(void);
};

/* Consts go here.	*/

/* #defines go here.	*/
#define _NUMBER_OF_THREADS   10
#define _STACK_SIZE          100
#define _FREQ_MS             1

/* static vars go here.	*/
/** Linked List for the main thread. */
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
/** Local variable holding the TCBs of the threads. */                                        
TCB_T _tcbs[_NUMBER_OF_THREADS];
/** Allocating memory for the threads stacks. */
uint32_t _stacks[_NUMBER_OF_THREADS][_STACK_SIZE];
/** Current running thread. */
TCB_T *_runPt;

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
 * @param period_ms Period IN THE CASE of a periodic thread.
 * @param priority Associated priority within the OS.
 * @param thread Pointer to the assciated function.
 * @return void.
 */ 
static void _Init_TCB(  TCB_T *tcb_pt, 
                        uint32_t* SP, 
                        uint32_t period_ms, 
                        uint8_t priority,
                        void(*thread)(void));

/**
 * @brief Run next periodic thread if there is any due to run.
 * 
 * @return void.
 */ 
static void _run_periodic_threads(void);

/**
 * @brief Boot Up OS and triggers it.
 * 
 * @return void.
 */ 
void TRXOS_start_OS(void);

void TRXOS_start(void) {
    SYSTICK_init(_FREQ_MS);
    TRXOS_start_OS();
}

/**
 * @brief High-Level part of the OS scheduler.
 * 
 * This function is part of the SysTick_handler.
 * To ease part of the scheduling part of the context swithc is done in C here.
 *
 * This function triggers the next periodic thread if needed.
 * If no periodic thread is due to run, next main thread is selected to run.
 * 
 * @return void.
 */
void TRXOS_Scheduler(void){
    _run_periodic_threads();
    LL_next(&g_main_thread_list);
}

static void _run_periodic_threads(void){
    void(*thread)(void) = NULL;

    for(int i = LL_get_length(&g_periodic_thread_list); i > 0; i--){
        TCB_T* current = (TCB_T*)LL_get_current(&g_periodic_thread_list);
        current->current_time--;
        if(0 == current->current_time){
            current->current_time = current->reload_time_ms;
            thread = current->thread;
            thread();
        }
        LL_next(&g_periodic_thread_list);
    }
}

void TRXOS_add_main_thread(void(*thread)(void), uint8_t priority) {
    assert(NULL != thread);

    int32_t length =    LL_get_length(&g_main_thread_list) +
                        LL_get_length(&g_periodic_thread_list);

    _Init_TCB_stack(&_stacks[length][0], thread);
    _Init_TCB(  &_tcbs[length], 
                &_stacks[length][_STACK_SIZE - 16], 
                0, 
                priority,
                NULL);
    if(0 == length){
        LL_init(&g_main_thread_list, (LL_node_t*)&_tcbs[0]);
        _runPt = (TCB_T*)LL_get_current(&g_main_thread_list);
    }
    else{
        LL_add(&g_main_thread_list, (LL_node_t*)&_tcbs[length]);
    }
}

void TRXOS_add_periodic_thread( void(*thread)(void), 
                                uint32_t period_ms, 
                                uint8_t priority){
    assert(NULL != thread);

    int32_t length =    LL_get_length(&g_main_thread_list) +
                        LL_get_length(&g_periodic_thread_list);

    _Init_TCB(  &_tcbs[length], 
                &_stacks[length][_STACK_SIZE - 16], 
                period_ms,
                priority,
                thread);
    if(0 == LL_get_length(&g_periodic_thread_list)){
        LL_init(&g_periodic_thread_list, (LL_node_t*)&_tcbs[length]);
        //_runPt = (TCB_T*)LL_get_current(&g_periodic_thread_list);
    }
    else{
        LL_add(&g_periodic_thread_list, (LL_node_t*)&_tcbs[length]);
    }
}

/* static function implementation go here.	*/
static void _Init_TCB_stack(uint32_t *SP, void(*PC)(void)){
    SP[_STACK_SIZE - 1] = 0x01000000;       /* PSR: set T-bit. */
    SP[_STACK_SIZE - 2] = (uint32_t)PC;     /* PC   */
    /* SP[_STACK_SIZE - 3] -> R14    */
    /* SP[_STACK_SIZE - 4] -> R12    */
    /* SP[_STACK_SIZE - 5] -> R3     */
    /* SP[_STACK_SIZE - 6] -> R2     */
    /* SP[_STACK_SIZE - 7] -> R1     */
    /* SP[_STACK_SIZE - 8] -> R0     */
    /* SP[_STACK_SIZE - 9] -> R11    */
    /* SP[_STACK_SIZE - 10] -> R10   */
    /* SP[_STACK_SIZE - 11] -> R9    */
    /* SP[_STACK_SIZE - 12] -> R8    */
    /* SP[_STACK_SIZE - 13] -> R7    */
    /* SP[_STACK_SIZE - 14] -> R6    */
    /* SP[_STACK_SIZE - 15] -> R5    */
    /* SP[_STACK_SIZE - 16] -> R4    */
}

static void _Init_TCB(  TCB_T *tcb_pt, 
                        uint32_t* SP, 
                        uint32_t period_ms, 
                        uint8_t priority,
                        void(*thread)(void)){
    tcb_pt->SP              = SP;
    tcb_pt->reload_time_ms  = period_ms;
    tcb_pt->current_time    = tcb_pt->reload_time_ms;
    tcb_pt->priority        = priority;
    tcb_pt->thread          = thread;
}
/* end of file */
