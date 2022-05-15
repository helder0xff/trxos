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
static uint32_t _cnt = 0;

/* static function declarations go here.	*/
static void isAlive(void);
static void main_thread_0(void);
static void main_thread_1(void);
static void main_thread_2(void);

int main( void ) {

    for(int i = 0; i < 10; i++) {
        isAlive();
    }

    //TRXOS_test();
    TRXOS_add_main_thread(&main_thread_0);
    TRXOS_add_main_thread(&main_thread_1);
    TRXOS_add_main_thread(&main_thread_2);
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

uint32_t thread_0_cnt = 0;
static void main_thread_0(void){
    

    for(;;){
        thread_0_cnt++;
        _cnt++;
    }
}

uint32_t thread_1_cnt = 0;
static void main_thread_1(void){
    

    for(;;){
        thread_1_cnt++;
        _cnt++;
    }
}

uint32_t thread_2_cnt = 0;
static void main_thread_2(void){
    

    for(;;){
        thread_2_cnt++;
        _cnt++;
    }
}
/**** end of file ****/
