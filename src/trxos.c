/**
 * @file	trxos.c
 * @author	helder
 * @date	2021-08-19
 * @brief	Light RTOS.
 */

/* Includes go here.	*/
#include <trxos.h>
#include <ll.h>
#include <mail.h>
#include <systick.h>
#include <stddef.h>
#include <assert.h>

/* typedefs go here.	*/
typedef struct TCB TCB_T;
struct TCB{
    LL_node_t node;
    uint32_t* SP;
};

/* Consts go here.	*/

/* #defines go here.	*/
#define _NUMBER_OF_THREADS   3
#define _STACK_SIZE          100
#define _FREQ_MS             1

/* static vars go here.	*/
LL_list_t g_main_thread_list = {NULL, NULL, NULL, 0, 0};
TCB_T _tcbs[_NUMBER_OF_THREADS];
uint32_t _stacks[_NUMBER_OF_THREADS][_STACK_SIZE];
TCB_T *_runPt;

/* static function declarations go here.	*/
static void _Init_Stack(uint32_t *SP, void(*PC)(void));
static void _Init_TCB(TCB_T *tcb_pt, uint32_t* SP);
void TRXOS_Start_OS(void);

/* non static function implementation go here.	*/
void TRXOS_test(void) {

     LL_node_t  node1;
     LL_node_t  node2;
     LL_node_t  node3;
     LL_node_t  node4;
     LL_list_t  list;

     LL_InitNode(&node1, 101);
     LL_InitNode(&node2, 202);
     LL_InitNode(&node3, 303);
     LL_InitNode(&node4, 404);
     LL_Init(&list, &node1);

     for(int i = 0; i < 5; i++) {
        LL_Next(&list);
     }

     LL_Add(&list, &node2);

     for(int i = 0; i < 5; i++) {
        LL_Next(&list);
     }

     LL_Add(&list, &node3);
     LL_Add(&list, &node4);

    for(int i = 0; i < 12; i++) {
        LL_Next(&list);
     }

     LL_Remove(&list, 1);

    for(int i = 0; i < 5; i++) {
        LL_Next(&list);
     }

    MAIL_box_t mail_box;
    int32_t message;
    
    MAIL_Init(&mail_box);

    MAIL_Write(&mail_box, 101);
    MAIL_Write(&mail_box, 202);
    MAIL_Empty(&mail_box);
    MAIL_Write(&mail_box, 202);
    MAIL_Read(&mail_box, &message);
}

void TRXOS_init(void) {
    SYSTICK_Init(_FREQ_MS);
    TRXOS_Start_OS();
}
/* static function implementation go here.	*/
static void _Init_Stack(uint32_t *SP, void(*PC)(void)){
    SP[_STACK_SIZE - 1] = 0x01000000;   /* PSW  */
    SP[_STACK_SIZE - 2] = (uint32_t)PC;           /* PC   */
    /* SP[_STACK_SIZE - 3] -> R14    */
    /* SP[_STACK_SIZE - 4] -> R12    */
    /* SP[_STACK_SIZE - 5] -> R3     */
    /* SP[_STACK_SIZE - 6] -> R2     */
    /* SP[_STACK_SIZE - 7] -> R1     */
    /* SP[_STACK_SIZE - 8] -> R0     */
    /* SP[_STACK_SIZE - 9] -> R11    */
    /* SP[_STACK_SIZE - 10] -> R10   */
    /* SP[_STACK_SIZE - 11] -> R9    */
    /* SP[_STACK_SIZE - 12] -> R8    */
    /* SP[_STACK_SIZE - 13] -> R7    */
    /* SP[_STACK_SIZE - 14] -> R6    */
    /* SP[_STACK_SIZE - 15] -> R5    */
    /* SP[_STACK_SIZE - 16] -> R4    */
}

static void _Init_TCB(TCB_T *tcb_pt, uint32_t* SP){
    tcb_pt->SP = SP;
}
//*** end of file ***//
