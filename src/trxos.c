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
    /** In the case of periodic threads, period in OS ticks. */
    uint32_t    reload_time_ticks;
    /** In the case of periodic threads, time in OS ticks from the last trigger. */
    uint32_t    current_time_ticks;
    /** Pointer to the code (function) of this thread. */
    void(*thread)(void);
};

/* Consts go here.	*/

/* #defines go here.	*/
#define _NUMBER_OF_THREADS   10
#define _STACK_SIZE          100
#define _PERIOD_uS           10000 /* Period in uS at wich we trigger the
                                    * scheduller. */

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

/** Local variable holding the TCBs of the threads. */                                        
TCB_T _tcbs[_NUMBER_OF_THREADS];

/** Allocating memory for the threads stacks. */
uint32_t _stacks[_NUMBER_OF_THREADS][_STACK_SIZE];

/** Current running thread. */
TCB_T *_runPt;

/** 
 *  This variable informs about an OS suspend command.
 *  It is used to only allow main threads to be triggered when the SysTick is
 *  being interrupted by SW (OS_suspend).
 *  This trick will keep the timing right.
 */
uint8_t _suspend_flag = 0;

/** System clock. */
uint32_t system_clk_Hz = 3000000;

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
 * @brief This function set the clock as fast as possible.
 * 
 * It is a straight copy from the Valmaro BSP library function
 * BSP_Clock_InitFastest.
 */
static void _set_fastest_clk(void);


static void _main_dummy_thread(void);

/**
 * @brief Boot Up OS and triggers it.
 * 
 * @return void.
 */ 
void TRXOS_start_OS(void);

void TRXOS_start(void) {
    TRXOS_add_main_thread(&_main_dummy_thread, 0);
    _set_fastest_clk();
    SYSTICK_init(_PERIOD_uS);
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
    if(0 == _suspend_flag){
        _run_periodic_threads();
    }
    _suspend_flag = 0;
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

    int32_t length =    LL_get_length(&g_main_thread_list) +
                        LL_get_length(&g_periodic_thread_list);

    _Init_TCB_stack(&_stacks[length][0], thread);
    _Init_TCB(  &_tcbs[length], 
                &_stacks[length][_STACK_SIZE - 16], 
                0, 
                priority,
                NULL);
    /* 
     * Check if the length in the if should be just the lenght of the 
     * g_main_thread_list ¡!
     */
    if(0 == length){
        LL_init(&g_main_thread_list, (LL_node_t*)&_tcbs[0]);
        _runPt = (TCB_T*)LL_get_current(&g_main_thread_list);
    }
    else{
        LL_add(&g_main_thread_list, (LL_node_t*)&_tcbs[length]);
    }
}

void TRXOS_add_periodic_thread( void(*thread)(void), 
                                uint32_t period_uS, 
                                uint8_t priority){
    assert(NULL != thread);

    int32_t length =    LL_get_length(&g_main_thread_list) +
                        LL_get_length(&g_periodic_thread_list);

    _Init_TCB(  &_tcbs[length], 
                &_stacks[length][_STACK_SIZE - 16], 
                _time_uS_to_OS_ticks(period_uS),
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

void TRXOS_suspend(void){
    _suspend_flag = 1;
    INTCTRL = 0x04000000; // trigger SysTick
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
                        uint32_t period_ticks, 
                        uint8_t priority,
                        void(*thread)(void)){
    tcb_pt->SP                  = SP;
    tcb_pt->reload_time_ticks  = period_ticks;
    tcb_pt->current_time_ticks = tcb_pt->reload_time_ticks;
    tcb_pt->priority            = priority;
    tcb_pt->thread              = thread;
}

static uint32_t _time_uS_to_OS_ticks(uint32_t time_uS){
    return time_uS / _PERIOD_uS;

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

#define MSP432P401R
#ifdef MSP432P401R
#define PCMCTL1                     (*((volatile uint32_t *)0x40010004))
#define PCMCTL0                     (*((volatile uint32_t *)0x40010000))
#define PCMIFG                      (*((volatile uint32_t *)0x4001000C))
#define PCMCLRIFG                   (*((volatile uint32_t *)0x40010010))
#define PJSEL0                      (*((volatile uint16_t *)0x40004D2A))
#define PJSEL1                      (*((volatile uint16_t *)0x40004D2C))
#define CSKEY                       (*((volatile uint32_t *)0x40010400))
#define CSCTL1                      (*((volatile uint32_t *)0x40010408))
#define CSCTL2                      (*((volatile uint32_t *)0x4001040C))
#define FLCTL_BANK0_RDCTL           (*((volatile uint32_t *)0x40011010))
#define FLCTL_BANK1_RDCTL           (*((volatile uint32_t *)0x40011014))
#define CSIFG                       (*((volatile uint32_t *)0x40010448))
#define CSCLRIFG                    (*((volatile uint32_t *)0x40010450))
#define FLCTL_BANK0_RDCTL_WAIT_2    ((uint32_t)0x00002000)
#define FLCTL_BANK1_RDCTL_WAIT_2    ((uint32_t)0x00002000)
#endif

uint32_t SYSTICK_Prewait = 0;                   // loops between BSP_Clock_InitFastest() called and PCM idle (expect 0)
uint32_t SYSTICK_CPMwait = 0;                   // loops between Power Active Mode Request and Current Power Mode matching requested mode (expect small)
uint32_t SYSTICK_Postwait = 0;                  // loops between Current Power Mode matching requested mode and PCM module idle (expect about 0)
uint32_t SYSTICK_IFlags = 0;                    // non-zero if transition is invalid
uint32_t SYSTICK_Crystalstable = 0;             // loops before the crystal stabilizes (expect small)
void _set_fastest_clk(void){
  // wait for the PCMCTL0 and Clock System to be write-able by waiting for Power Control Manager to be idle
  while(PCMCTL1&0x00000100){
    SYSTICK_Crystalstable = SYSTICK_Crystalstable + 1;
    if(SYSTICK_Crystalstable >= 100000){
      return;                           // time out error
    }
  }
  // request power active mode LDO VCORE1 to support the 48 MHz frequency
  PCMCTL0 = (PCMCTL0&~0xFFFF000F) |     // clear PCMKEY bit field and AMR bit field
            0x695A0000 |                // write the proper PCM key to unlock write access
            0x00000001;                 // request power active mode LDO VCORE1
  // check if the transition is invalid (see Figure 7-3 on p344 of datasheet)
  if(PCMIFG&0x00000004){
    SYSTICK_IFlags = PCMIFG;                    // bit 2 set on active mode transition invalid; bits 1-0 are for LPM-related errors; bit 6 is for DC-DC-related error
    PCMCLRIFG = 0x00000004;             // clear the transition invalid flag
    // to do: look at CPM bit field in PCMCTL0, figure out what mode you're in, and step through the chart to transition to the mode you want
    // or be lazy and do nothing; this should work out of reset at least, but it WILL NOT work if Clock_Int32kHz() or Clock_InitLowPower() has been called
    return;
  }
  // wait for the CPM (Current Power Mode) bit field to reflect a change to active mode LDO VCORE1
  while((PCMCTL0&0x00003F00) != 0x00000100){
    SYSTICK_CPMwait = SYSTICK_CPMwait + 1;
    if(SYSTICK_CPMwait >= 500000){
      return;                           // time out error
    }
  }
  // wait for the PCMCTL0 and Clock System to be write-able by waiting for Power Control Manager to be idle
  while(PCMCTL1&0x00000100){
    SYSTICK_Postwait = SYSTICK_Postwait + 1;
    if(SYSTICK_Postwait >= 100000){
      return;                           // time out error
    }
  }
  // initialize PJ.3 and PJ.2 and make them HFXT (PJ.3 built-in 48 MHz crystal out; PJ.2 built-in 48 MHz crystal in)
  PJSEL0 |= 0x0C;
  PJSEL1 &= ~0x0C;                      // configure built-in 48 MHz crystal for HFXT operation
//  PJDIR |= 0x08;                        // make PJ.3 HFXTOUT (unnecessary)
//  PJDIR &= ~0x04;                       // make PJ.2 HFXTIN (unnecessary)
  CSKEY = 0x695A;                       // unlock CS module for register access
  CSCTL2 = (CSCTL2&~0x00700000) |       // clear HFXTFREQ bit field
           0x00600000 |                 // configure for 48 MHz external crystal
           0x00010000 |                 // HFXT oscillator drive selection for crystals >4 MHz
           0x01000000;                  // enable HFXT
  CSCTL2 &= ~0x02000000;                // disable high-frequency crystal bypass
  // wait for the HFXT clock to stabilize
  while(CSIFG&0x00000002){
    CSCLRIFG = 0x00000002;              // clear the HFXT oscillator interrupt flag
    SYSTICK_Crystalstable = SYSTICK_Crystalstable + 1;
    if(SYSTICK_Crystalstable > 100000){
      return;                           // time out error
    }
  }
  // configure for 2 wait states (minimum for 48 MHz operation) for flash Bank 0
  FLCTL_BANK0_RDCTL = (FLCTL_BANK0_RDCTL&~0x0000F000)|FLCTL_BANK0_RDCTL_WAIT_2;
  // configure for 2 wait states (minimum for 48 MHz operation) for flash Bank 1
  FLCTL_BANK1_RDCTL = (FLCTL_BANK1_RDCTL&~0x0000F000)|FLCTL_BANK1_RDCTL_WAIT_2;
  CSCTL1 = 0x20000000 |                 // configure for SMCLK divider /4
           0x00100000 |                 // configure for HSMCLK divider /2
           0x00000200 |                 // configure for ACLK sourced from REFOCLK
           0x00000050 |                 // configure for SMCLK and HSMCLK sourced from HFXTCLK
           0x00000005;                  // configure for MCLK sourced from HFXTCLK
  CSKEY = 0;                            // lock CS module from unintended access
  //ClockFrequency = 48000000;
  //SubsystemFrequency = 12000000;
  system_clk_Hz = 48000000;
}

/* end of file */
