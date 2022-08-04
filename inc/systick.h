/**
 * @file	systick.h
 * @author	helder
 * @brief	Header file of the SysTick module.
 */

#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

/**
 * @brief Initialize the SysTick
 * 
 * This function intialize the systick with a given frecuency.
 * Then it trigger it.
 * 
 * @param period_uS Period at which the SysTick will be triggered.
 * @return void.
 */ 
void SYSTICK_init(uint32_t period_uS);

#endif

/* end of file */
