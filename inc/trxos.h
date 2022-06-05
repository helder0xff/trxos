/**
 * @file	trxos.h
 * @author	helder
 * @date	2021-08-19
 * @brief	??
 */

#ifndef TRXOS_H
#define TRXOS_H

#include <stdint.h>

void TRXOS_init(void);
void TRXOS_add_main_thread(void(*thread)(void), uint8_t priority);
void TRXOS_add_periodic_thread( void(*thread)(void), 
                                uint32_t period_ms, 
                                uint8_t priority);
void TRXOS_test(void);

#endif /* TRXOS_H */

//*** end of file ***//
