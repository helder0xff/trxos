/**
 * @file	ll.h
 * @author	helder
 * @brief	Header file of the RTOS linked list.
 */

#ifndef LL_H
#define LL_H

#include <stdint.h>

/**
 * @brief Node structure.
 */
typedef struct LL_node LL_node_t;
typedef struct LL_node {
    /** Pointer to next node. */
    LL_node_t* next;
    /** Pointer to previous node. */
    LL_node_t* prev;
    /** ID of this node. */
    uint32_t id;
    /** Data that holds this node. */
    int32_t data;
} LL_node_t;

/**
 * @brief Linked List structue.
 */
typedef struct LL_list {
    /** Head node of the linked list. */
    LL_node_t* head;
    /** Current node of the linked list. */
    LL_node_t* current;
    /** Tail node of the linked list. */
    LL_node_t* tail;
    /** Length of the linked list. */
    uint32_t length;
    /** ID counter; used for id assigning. */
    uint32_t id_cnt;
} LL_list_t;

/**
 * @brief Initialization of the LL.
 * 
 * @param list Pointer to linked list.
 * @param head Pointer to the first node, the head.
 * @return void.
 */
void LL_init(LL_list_t* list, LL_node_t* head);

/**
 * @brief Update the 'current' node to the next in the list.
 * 
 * @param list Pointer to linked list.
 * @return void
 */
void LL_next(LL_list_t* list);

/**
 * @brief Add a new node to the LL.
 * 
 * @param list Pointer to linked list.
 * @param node The new node, should be initialized first.
 * @return void.
 */
void LL_add(LL_list_t* list, LL_node_t* node);

/**
 * @brief Initialize node with the giving data.
 * 
 * @param node Pointer to the node.
 * @param data Data that the node holds.
 * @return void.
 */
void LL_init_node(LL_node_t* node, int32_t data);

/**
 * @brief Remove a given node from the LL.
 * 
 * @param list Pointer to the LL.
 * @param node_id ID of the node to be removed.
 * @return Pointer to the removed node, NULL if not found.
 */
LL_node_t* LL_remove(LL_list_t* list, uint32_t node_id);

/**
 * @brief Get length of the list.
 * 
 * @param list Pointer to the LL.
 * @return Length of the LL.
 */
int32_t LL_get_length(LL_list_t* list);

/**
 * @brief Get current node of the LL.
 * 
 * @param list Pointer to the LL.
 * @return Pointer to the current node.
 */
LL_node_t* LL_get_current(LL_list_t* list);

#endif /* TRXOS_H */

/* end of file */
