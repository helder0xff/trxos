/**
 * @file    semaphore.h
 * @author  helder
 * @brief   Semaphores header file.
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdint.h>

#define SEMAPHORE_BUSY  (0)

/**
 * @brief Semaphore structure.
 */
typedef struct SEMAPHORE_semaphore {
    /** Semaphore counter. */
    uint8_t counter;
} SEMAPHORE_semaphore_t;

/**
 * @brief Initialization of the semaphore.
 * 
 * @param semaphore Pointer to the semaphore.
 * @return void.
 */
void SEMAPHORE_init(SEMAPHORE_semaphore_t* semaphore, uint8_t initial_counter);

/**
 * @brief Initialization of a mutex.
 * 
 * @param semaphore Pointer to the semaphore.
 * @return void.
 */
void SEMAPHORE_mutex_init(SEMAPHORE_semaphore_t* semaphore);

/**
 * @brief Wait while the semaphore is not free.
 * 
 * @param semaphore Pointer to the semaphore.
 * @return void.
 */
void SEMAPHORE_wait(SEMAPHORE_semaphore_t* semaphore);

/**
 * @brief Signal the semaphore.
 * 
 * @param semaphore Pointer to the semaphore.
 * @return void.
 */
void SEMAPHORE_signal(SEMAPHORE_semaphore_t* semaphore);

#endif /* SEMAPHORE_H */

/* end of file */
