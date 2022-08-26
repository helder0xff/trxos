#include <assert.h>
#include <fifo.h>
#include <string.h>

void FIFO_init(
	FIFO_fifo_t* p_fifo, 
	void* p_buffer, 
	uint32_t length, 
	size_t item_size){
	assert(NULL != p_fifo);
	assert(NULL != p_buffer);
	assert(0 < length);
	assert(0 < item_size);	

	SEMAPHORE_init(&p_fifo->semaphore, 0);
	p_fifo->p_buffer_head 	= p_buffer;
	p_fifo->put_p 			= p_fifo->p_buffer_head;
	p_fifo->get_p 			= p_fifo->p_buffer_head;
	p_fifo->length 			= length;
	p_fifo->item_size 		= item_size;
	p_fifo->p_buffer_tail 	= 
		p_fifo->p_buffer_head + ((p_fifo->length - 1) * p_fifo->item_size);
}

int8_t FIFO_put(FIFO_fifo_t* p_fifo, void* p_item){
	assert(NULL != p_fifo);
	assert(NULL != p_item);

	int8_t ret = FIFO_ERROR;

	if(SEMAPHORE_get_value(&p_fifo->semaphore) >= (int32_t)p_fifo->length){
		ret = FIFO_FULL;
	}
	else{
		memcpy(p_fifo->put_p, p_item, p_fifo->item_size);
		/* Update put pointer. */
		(p_fifo->put_p < p_fifo->p_buffer_tail) ?
			(p_fifo->put_p += p_fifo->item_size) : 
			(p_fifo->put_p = p_fifo->p_buffer_head);
		SEMAPHORE_signal(&p_fifo->semaphore);
		ret = FIFO_OK;
	}

	return ret;
}

void FIFO_get(FIFO_fifo_t* p_fifo, void* p_item){
	assert(NULL != p_fifo);
	assert(NULL != p_item);

	SEMAPHORE_wait(&p_fifo->semaphore);
	memcpy(p_item, p_fifo->get_p, p_fifo->item_size);
	/* Update get buffer. */
	(p_fifo->get_p < p_fifo->p_buffer_tail) ?
		(p_fifo->get_p += p_fifo->item_size) : 
		(p_fifo->get_p = p_fifo->p_buffer_head);
}
