/**
 * @file	mail.h
 * @author	helder
 * @brief	Header file of the RTOS mail box.
 */

#ifndef MAIL_H
#define MAIL_H

#include <stdint.h>
#include <semaphore.h>

#define MAIL_EMPTY      0
#define MAIL_NOT_EMPTY -1
#define MAIL_SENT       0
#define MAIL_NOT_SENT  -1
#define MAIL_READ       0
#define MAIL_NOT_READ  -1

/**
 * @brief Mail box structure.
 */
typedef struct MAIL_box {
    /** Message on the mail box. */
    int32_t message;
    /** State of the mail box: EMPTY, SENT, READ. */
    int8_t  state;
    /** Semaphore for resource management. */
    SEMAPHORE_semaphore_t semaphore;
} MAIL_box_t;

/**
 * @brief Initialize the mail box.
 * 
 * This function just set the mail_box state as EMPTY.
 * 
 * @param mail_box Pointer to the mail box.
 * @return void.
 */
void MAIL_init(MAIL_box_t* mail_box);

/**
 * @brief Write a message on the mail box.
 * 
 * This function write a message on the mail box and send it.
 * 
 * @param mail_box Pointer to the mail box.
 * @param message Message to be sent.
 * @return MAIL_SENT if successful, MAIL_NOT_SENT otherwise.
 */
int8_t MAIL_write(MAIL_box_t* mail_box, int32_t message);

/**
 * @brief Read a message from the mail box.
 * 
 * @param mail_box Pointer to the mail box.
 * @param message Pointer to where to save the message.
 * @return MAIL_READ if successfull, MAIL_NOT_READ otherwise.
 */
int8_t MAIL_read(MAIL_box_t* mail_box, int32_t* message);

/**
 * @brief Empty the mail box.
 * 
 * @param mail_box Pointer to the mail box.
 * @return void.
 */
void MAIL_empty(MAIL_box_t* mail_box);

#endif

/**** end of file ****/
