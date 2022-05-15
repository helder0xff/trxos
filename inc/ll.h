/**
 * @file	ll.h
 * @author	helder
 * @date	2022-02-13
 * @brief	Header file of the RTOS linked list.
 */

#ifndef LL_H
#define LL_H

#include <stdint.h>

typedef struct LL_node LL_node_t;
typedef struct LL_node {
    LL_node_t* next;
    LL_node_t* prev;
    uint32_t id;
    int32_t data;
} LL_node_t;

typedef struct LL_list {
    LL_node_t* head;
    LL_node_t* current;
    LL_node_t* tail;
    uint32_t length;
    uint32_t id_cnt;
} LL_list_t;

void LL_Init(LL_list_t* list, LL_node_t* head);
void LL_Next(LL_list_t* list);
void LL_Add(LL_list_t* list, LL_node_t* node);
void LL_InitNode(LL_node_t* node, int32_t data);
LL_node_t* LL_Remove(LL_list_t* list, uint32_t node_id);
int32_t LL_GetLength(LL_list_t* list);
LL_node_t* LL_GetCurrent(LL_list_t* list);

#endif /* TRXOS_H */

//*** end of file ***//
