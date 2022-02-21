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

/* typedefs go here.	*/

/* Consts go here.	*/

/* #defines go here.	*/

/* static vars go here.	*/

/* static function declarations go here.	*/

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
/* static function implementation go here.	*/

//*** end of file ***//
