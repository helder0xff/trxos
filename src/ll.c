/**
 * @file	ll.c
 * @author	helder
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
void LL_init(LL_list_t* list, LL_node_t* head) {
    assert(NULL != list);

    if(NULL == head){
        list->head      = NULL;
        list->current   = NULL;
        list->tail      = NULL;
        list->id_cnt    = 0;
        list->length    = 0;
    }
    else{
        /* Initialization of the LL. */
        list->id_cnt        = 0;
        list->head          = head;
        list->current       = head;
        list->tail          = head;
        list->head->id      = list->id_cnt;
        list->id_cnt        += 1;
        list->length        = 1;

        // Make it ciruclar.
        /*
        list->head->next    = list->tail;
        list->head->prev    = list->tail;
        list->tail->next    = list->head;
        list->tail->prev    = list->head;
        */
        head->next          = head;
        head->prev          = head;
    }
}

LL_node_t* LL_next(LL_list_t* list) {
    assert(NULL != list);

    if(0 < list->length){
        list->current = list->current->next;
    }

    return list->current;
}
 
 void LL_add(LL_list_t* list, LL_node_t* node) {
    assert(NULL != list);
    assert(NULL != node);

    if(0 >= list->length){
        LL_init(list, node);
    }
    else{
        /* Link new node. */
        node->next      = list->head;
        node->prev      = list->tail;
        node->id        = list->id_cnt;
        list->id_cnt    += 1;

        /* Update head. */
        list->head->prev    = node;

        /* Update tail. */
        list->tail->next    = node;
        list->tail          = node;

        /* Update LL length. */
        list->length        += 1;        
    }    
 }

 void LL_init_node(LL_node_t* node, int32_t data) {
    assert(NULL != node);

    node->data = data;
 }

 LL_node_t* LL_remove(LL_list_t* list, uint32_t node_id) {
    assert(NULL != list);
    assert(0 <= node_id);

    /* Go through the LL searching for the node_id and remove it if found. */
    LL_node_t* cursor   = list->head;
    LL_node_t* prev      = NULL;
    for(int i = 0; i < list->length; i++) {
        if(node_id == cursor->id) {
            list->length        -= 1;
            if(0 == list->length){
                LL_init(list, NULL);
                break;
            }

            cursor->next->prev  = cursor->prev;
            cursor->prev->next  = cursor->next;            
            if(cursor == list->current) {
                list->current = cursor->next;
            }
            if(cursor == list->head){
                list->head = cursor->next;
            }
            if(cursor == list->tail){
                list->tail = cursor->prev;
            }

            /*
            prev            = cursor->prev;
            prev->next       = cursor->next;
            list->length    -= 1;
            */
            break;
        }
        else {
            cursor = cursor->next;
        }
    }

    if(node_id != cursor->id){
        cursor = NULL;
    }

    return cursor;
 }

 int32_t LL_get_length(LL_list_t* list){
    return list->length;
 }

 LL_node_t* LL_get_current(LL_list_t* list){
    return list->current;
 }

LL_node_t* LL_get_head(LL_list_t* list){
    return list->head;
}

void LL_move_node_to_another_list(
    LL_list_t* list_origin, 
    LL_list_t* list_destination,
    uint32_t id){

    assert(NULL != list_origin);
    assert(NULL != list_destination);
    assert(0 <= id);

    LL_node_t* node = LL_remove(list_origin, id);
    if(NULL != node){
        LL_add(list_destination, node);
    }
}

/* static function implementation go here.	*/

/* end of file */
