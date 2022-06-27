/**
 * @file	systick.c
 * @author	helder
 * @brief	Source file of the SysTick module.
 */

#include <systick.h>
#include <ll.h>

extern LL_list_t g_main_thread_list;

#define SYS_FREQ 	(3000000)

#define MSP432P401R
#ifdef MSP432P401R
#define STCTRL          (*((volatile uint32_t *)0xE000E010))
#define STRELOAD        (*((volatile uint32_t *)0xE000E014))
#define STCURRENT       (*((volatile uint32_t *)0xE000E018))
#define SYSPRI3         (*((volatile uint32_t *)0xE000ED20))
#endif

void SYSTICK_init(uint32_t period_ms) {
	STCTRL 		= 0; 									/* Disable. */
	STRELOAD 	= ((SYS_FREQ * period_ms)/1000) - 1;	/* Set reload val. */	
	STCURRENT 	= 0; 									/* Reset counter. */
	SYSPRI3 	= (SYSPRI3 & 0x00FFFFFF) | 0xE0000000;	/* Priority = 7. */
	STCTRL 		= 0b111; 								/* 	Src Clk + 
															Tick Init + 
															Enable. */
}

/*
uint32_t xxx = 0;
void SysTick_Handler(void) {
	xxx += 1;
	LL_next(&g_main_thread_list);
}
*/

/* end of file */
