/**
 * @file    trxos.h
 * @author  helder
 * @brief   Light RTOS header file.
 */

#ifndef TRXOS_H
#define TRXOS_H

#include <stdint.h>

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
 * @brief Enable interrupts..
 * 
 * @return void
 */ 
void TRXOS_enable_interrupts(void);

/**
 * @brief Disable interrupts..
 * 
 * @return void
 */ 
void TRXOS_disable_interrupts(void);

#endif /* TRXOS_H */

/* end of file */
