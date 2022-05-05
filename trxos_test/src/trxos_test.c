/**
 * @file	trxos_test.c
 * @author	helder
 * @date	2021-08-19
 * @brief	??
 */

/* Includes go here.	*/
#include <trxos_test.h>
#include <trxos.h>
#include <msp432p401r.h>
#include <CortexM.h>

/* typedefs go here.	*/

/* Consts go here.	*/

/* #defines go here.	*/

/* static vars go here.	*/

/* static function declarations go here.	*/
static void isAlive(void);

int main( void ) {

    for(int i = 0; i < 10; i++) {
        isAlive();
    }

    TRXOS_test();
    TRXOS_init();

    while(0 == 0) {
    	;
    }
	
    return 0;
}

/* non static function implementation go here.	*/

/* static function implementation go here.	*/
static void isAlive(void){
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

    // Initialze P1.0 as output
    P1->DIR |= BIT0;
    // Clear secondary functions
    P1->SEL0 &= ~(BIT0);
    P1->SEL1 &= ~(BIT0);

    // Blink
    P1->OUT = 1;
    Clock_Delay1ms(10000);
    P1->OUT = 0;
    Clock_Delay1ms(10000);
}

/**** end of file ****/
