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
static void main_thread_0(void);
static void main_thread_1(void);
static void main_thread_2(void);
static void periodic_thread_0(void);
static void periodic_thread_1(void);
static void periodic_thread_2(void);

int main( void ) {

    for(int i = 0; i < 10; i++) {
        isAlive();
    }

    //TRXOS_test();
    TRXOS_add_main_thread(&main_thread_0, 0);
    TRXOS_add_periodic_thread(&periodic_thread_0, 1000, 0);
    TRXOS_add_periodic_thread(&periodic_thread_1, 60000, 0);    
    TRXOS_add_main_thread(&main_thread_1, 0);
    TRXOS_add_main_thread(&main_thread_2, 0);
    TRXOS_add_periodic_thread(&periodic_thread_2, 3600000, 0);
    TRXOS_start();

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

uint32_t main_thread_0_cnt = 0;
static void main_thread_0(void){
    for(;;){
        main_thread_0_cnt++;
    }
}

uint32_t main_thread_1_cnt = 0;
static void main_thread_1(void){    
    for(;;){
        main_thread_1_cnt++;
    }
}

uint32_t main_thread_2_cnt = 0;
static void main_thread_2(void){    
    for(;;){
        main_thread_2_cnt++;
    }
}

uint32_t periodic_thread_0_cnt = 0;
static void periodic_thread_0(void){
    periodic_thread_0_cnt++;
    uint8_t led_status = P1->OUT;
    P1->OUT = ~led_status;
    if(periodic_thread_0_cnt >= 60){
        periodic_thread_0_cnt = 0;
    }
}

uint32_t periodic_thread_1_cnt = 0;
static void periodic_thread_1(void){
    periodic_thread_1_cnt++;
    if(periodic_thread_1_cnt >= 60){
        periodic_thread_1_cnt = 0;
    }    
}

uint32_t periodic_thread_2_cnt = 0;
static void periodic_thread_2(void){
    periodic_thread_2_cnt++;
    if(periodic_thread_2_cnt >= 24){
        periodic_thread_2_cnt = 0;
    }    
}

/**** end of file ****/
