/**
 * @file    trxos.h
 * @author  helder
 * @brief   Light RTOS header file.
 */

#ifndef TRXOS_H
#define TRXOS_H

#include <stdint.h>
#include <ll.h>
#include <semaphore.h>

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
    /** In the case of periodic threads, time in OS ticks from the last 
     * trigger. */
    uint32_t    current_time_ticks;
    /** Pointer to the code (function) of this thread. */
    void(*thread)(void);
    /** Pointer to the semaphore whose is blocking the thread, NULL in case
     * of no one is blocking it. */
    SEMAPHORE_semaphore_t* blocked;
    /** Sleep counter in case of dormant thread. */    
    uint32_t sleep_counter;
};

/**
 * @brief Initialization function.
 * 
 * This function initializes the SysTick and triggers the OS.
 * 
 * @return void
 */
void TRXOS_start(void);

/**
 * @brief Add main thread to the OS.
 * 
 * @param thread Pointer to the associated function.
 * @param priority Priority of the thread within the OS.
 * @return void.
 */
void TRXOS_add_main_thread(void(*thread)(void), uint8_t priority);

/**
 * @brief Add periodic thread to the OS.
 * 
 * @param thread Pointer to the associated function.
 * @param period_ms Period in mS
 * @param priority Priority of the thread within the OS.
 * @return void
 */ 
void TRXOS_add_periodic_thread( void(*thread)(void), 
                                uint32_t period_uS, 
                                uint8_t priority);

/**
 * @brief Suspend current thread.
 * 
 * This function suspend the current thread and force a SysTick interrupt.
 * In order not to reenter a periodic thread, a flag is set therefore we 
 * do not corrupt timing.
 * 
 * @return void
 */ 
void TRXOS_suspend(void);

/**
 * @brief Enable interrupts.
 * 
 * @return void
 */ 
void TRXOS_enable_interrupts(void);

/**
 * @brief Disable interrupts.
 * 
 * @return void
 */ 
void TRXOS_disable_interrupts(void);

/**
 * @brief Block the given thread with the given semaphore.
 * 
 * @param p_tcb Pointer to the thread TCB.
 * @param p_semaphore Pointer to the semaphore.
 * @return void
 */ 
void TRXOS_block(TCB_T* p_tcb, SEMAPHORE_semaphore_t* p_semaphore);

/**
 * @brief Unblock the first thread in the blocked_thread_list being
 * blocked by the given semaphore.
 * 
 * @param p_semaphore Pointer to semaphore.
 * @return void
 */ 
void TRXOS_unblock(SEMAPHORE_semaphore_t* p_semaphore);

/**
 * @brief Decrement the sleep counter for all the threads in the asleep list.
 * 
 * This function goes though all the threads in the sleep list decrementing
 * its sleep counter. If the counter reach 0, the thread is moved back to 
 * the main thread llist.
 * 
 * @return void
 */ 
void TRXOS_decrement_asleep_threads_counter(void);

/**
 * @brief Send current thread to sleep.
 * 
 * This function initialize the sleep counter, notify the shceduller that 
 * the curent running thread is due to set to sleep and suspend.
 * 
 * @param time_uS Time for sleeping in uS.
 * @return void
 */ 
void TRXOS_sleep(uint32_t time_uS);

/**
 * @brief Request a clk speed change at run time.
 * 
 * This function request a change on the system clock and manage all the
 * peripherals depending on the frequency for its configuration (sleep_timer, 
 * and systick for instance.)
 * 
 * The configured frequency is board dependant. The lowest the clk_speed_level
 * the lowest the frequency to be set.
 * 
 * @param clk_speed_level The speed level, from 0 to 255.
 * @return void
 */ 
void TRX_request_clk_speed_level(uint8_t clk_speed_level);

#endif /* TRXOS_H */

/* end of file */
