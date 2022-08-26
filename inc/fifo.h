#ifndef FIFO_H
#define FIFO_H

#include <stddef.h>
#include <stdint.h>
#include <semaphore.h>

#define FIFO_OK 	(0)
#define FIFO_FULL	(-1)
#define FIFO_ERROR 	(-128)

/**
 * @brief Fifo structure.
 */
typedef struct FIFO_fifo {
	/** Pointer to the head of the buffer. */
	void* p_buffer_head;
	/** Pointer to the tail of the buffer. */
	void* p_buffer_tail;
	/** Length of the buffer in item_size units.. */
    uint32_t length;
    /** Put pointer. */
    void* put_p;
    /** Get pointer. */
    void* get_p;
    /** Semaphore. */
    SEMAPHORE_semaphore_t semaphore;
    /** Size of the items within the buffer, obtained with sizeof(). */
    size_t item_size;
} FIFO_fifo_t;

/**
 * @brief Initialization of the fifo.
 * 
 * @param p_fifo Pointer to the fifo.
 * @param p_buffer Pointer to head of the buffer.
 * @param length Length of the buffer in item_size units.
 * @param item_size Size of items within the buffer, obtained with sizeof() . 
 * @return void.
 */
void FIFO_init(
	FIFO_fifo_t* p_fifo, 
	void* p_buffer, 
	uint32_t length, 
	size_t item_size);

/**
 * @brief Put item function.
 * 
 * @param p_fifo Pointer to the fifo.
 * @param p_item Pointer to the item to be added to the fifo. 
 * @return FIFO_OK if item was added, FIFO_FULL otherwise.
 */
int8_t FIFO_put(FIFO_fifo_t* p_fifo, void* p_item);

/**
 * @brief Get item function.
 * 
 * @param p_fifo Pointer to the fifo.
 * @param p_item Pointer where to save the next item. 
 * @return void
 */
void FIFO_get(FIFO_fifo_t* p_fifo, void* p_item);

#endif /* FIFO_H */

/* end of file */
