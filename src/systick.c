/**
 * @file	systick.c
 * @author	helder
 * @brief	Source file of the SysTick module.
 */
#include <CortexM.h>
#include <systick.h>

extern uint32_t g_system_clk_Hz;

void SYSTICK_init(uint32_t period_uS) {	
	STCTRL 		= 0;                                            /* Disable. */
	STRELOAD 	= (uint32_t)(((g_system_clk_Hz * 1.0 / 1000000) * period_uS) - 1);  /* Set reload val */	
	STCURRENT 	= 0;                                            /* Reset counter. */
	SYSPRI3 	= (SYSPRI3 & 0x00FFFFFF) | 0xE0000000;          /* Priority = 7. */
	STCTRL 		= 0b111; 								     	/* 	Src Clk + 
																	Tick Init + 
																	Enable. */
}

/* end of file */
