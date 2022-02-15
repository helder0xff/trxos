/**
 * @file	ll.c
 * @author	helder
 * @date	2022-02-13
 * @brief	Implementation of the RTOS linked list.
 */

/* Includes go here.	*/
#include <ll.h>
#include <assert.h>
#include <stddef.h>

/* typedefs go here.	*/

/* Consts go here.	*/

/* #defines go here.	*/

/* static vars go here.	*/

/* static function declarations go here.	*/

/* non static function implementation go here.	*/
void LL_Init(LL_list_t* list, LL_node_t* head) {
    assert(NULL != list);
    assert(NULL != head);

    list->id_cnt        = 0;            // Node id cnt. Mainly used for node removing.
    list->head          = head;
    list->current       = list->head;
    list->tail          = list->current;
    list->head->id      = list->id_cnt;
    list->id_cnt        += 1;
    list->length        = 1;

    // Make it ciruclar.
    list->head->next    = list->tail;
    list->head->prev    = list->tail;
    list->tail->next    = list->head;
    list->tail->prev    = list->head;
}

void LL_Next(LL_list_t* list) {
    assert(NULL != list);
    assert(NULL != list->current->next);

    list->current = list->current->next;
}
 
 void LL_Add(LL_list_t* list, LL_node_t* node) {
    assert(NULL != list);
    assert(NULL != node);

    // Link new node.
    node->next      = list->head;
    node->prev      = list->tail;
    node->id        = list->id_cnt;
    list->id_cnt    += 1;

    // Update tail;
    list->tail->next    = node;
    list->tail          = node;

    list->length        += 1;
 }

 void LL_InitNode(LL_node_t* node, int32_t data) {
    assert(NULL != node);

    node->data = data;
 }

 LL_node_t* LL_Remove(LL_list_t* list, uint32_t node_id) {
    assert(NULL != list);
    assert(0 <= node_id);

    LL_node_t* cursor   = list->head;
    LL_node_t* prev      = NULL;
    for(int i = 0; i < list->length; i++) {
        if(node_id == cursor->id) {
            if(node_id == list->current->id) {
                list->current = list->current->next;
            }
            prev            = cursor->prev;
            prev->next       = cursor->next;
            list->length    -= 1;
            break;
        }
        else {
            cursor = cursor->next;
        }
    }

    return cursor;
 }

/* static function implementation go here.	*/

//*** end of file ***//
