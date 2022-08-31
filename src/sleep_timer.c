#include <trxos.h>

#ifdef MSP432

#include <sleep_timer.h>
#include <msp432p401r_b.h>

extern uint32_t g_system_clk_Hz;

void SLEEP_TIMER_init(uint32_t period_uS){
    uint32_t reload = ((g_system_clk_Hz / 1000000) * period_uS) - 1;

    __asm("CPSIE  I");  /* Disable interrupts. */
    TA0CTL &= ~0x0030;  /* Disable timer.           */
    /* bits15-10=XXXXXX, reserved.                  */
    /* bits9-8=10,       clock source to SMCLK.     */
    /* bits7-6=00,       input clock divider /1.    */
    /* bits5-4=00,       stop mode.                 */
    /* bit3=X,           reserved.                  */
    /* bit2=0,           set this bit to clear.     */
    /* bit1=0,           disable interrupts.        */
    /* bit0=0,           clear interrupt pending.   */
    TA0CTL      = 0x0280;
    TA0EX0      = 0x0000;  /* Prescaler = 1.           */
    TA0CCTL0    = 0x0010;  /* Enable caputre/compare intrrupt. */
    TA0CCR0     = reload;
    TA0CTL      |= 0x0014; /* reset and start Timer A0 in up mode. */
    
    NVIC_IPR2 = (NVIC_IPR2&0xFFFFFF00)|0x00000040; // priority 2
    NVIC_ISER0 = 0x00000100;         // enable interrupt 8 in NVIC
    __asm("CPSID  I");      /* Enable interrupts. */
}

void TA0_0_IRQHandler(void){
    TA0CCTL0 &= ~0x0001;    /* Acknowledge interruption. */
    TRXOS_decrement_asleep_threads_counter();
}

#endif /* MSP432 */

/* end of file */
