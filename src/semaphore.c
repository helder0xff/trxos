/**
 * @file    semaphore.c
 * @author  helder
 * @brief   Semaphores source file.
 */
#include <semaphore.h>
#include <CortexM.h>
#include <trxos.h>

void SEMAPHORE_wait(SEMAPHORE_semaphore_t* semaphore){
	TRXOS_disable_interrupts();
		/* The OS will loop here waiting for the semaphore to be free. */
		TRXOS_enable_interrupts();
		TRXOS_suspend();
		TRXOS_disable_interrupts();
	}	
	semaphore->counter--;
	TRXOS_enable_interrupts();
}

void SEMAPHORE_signal(SEMAPHORE_semaphore_t* semaphore){
	TRXOS_disable_interrupts();
	semaphore->counter++;
	TRXOS_enable_interrupts();
}

void SEMAPHORE_init(SEMAPHORE_semaphore_t* semaphore, uint8_t initial_counter){
	semaphore->counter = initial_counter;
}

void SEMAPHORE_mutex_init(SEMAPHORE_semaphore_t* semaphore){
	SEMAPHORE_init(semaphore, 1);
}

/* end of file */
