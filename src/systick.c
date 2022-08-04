/**
 * @file	systick.c
 * @author	helder
 * @brief	Source file of the SysTick module.
 */

#include <systick.h>

extern uint32_t system_clk_Hz;

#define MSP432P401R
#ifdef MSP432P401R
#define STCTRL          (*((volatile uint32_t *)0xE000E010))
#define STRELOAD        (*((volatile uint32_t *)0xE000E014))
#define STCURRENT       (*((volatile uint32_t *)0xE000E018))
#define SYSPRI3         (*((volatile uint32_t *)0xE000ED20))
#endif

void SYSTICK_init(uint32_t period_uS) {	
	STCTRL 		= 0;                                            /* Disable. */
	STRELOAD 	= ((system_clk_Hz / 1000000) * period_uS) - 1;  /* Set reload val */	
	STCURRENT 	= 0;                                            /* Reset counter. */
	SYSPRI3 	= (SYSPRI3 & 0x00FFFFFF) | 0xE0000000;          /* Priority = 7. */
	STCTRL 		= 0b111; 								     	/* 	Src Clk + 
																	Tick Init + 
																	Enable. */
}

/* end of file */
