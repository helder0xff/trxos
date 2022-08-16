/**
 * @file	mail.c
 * @author	helder
 * @brief	Source file of the RTOS mail box.
 */

#include <mail.h>
#include <assert.h>
#include <stddef.h>

void MAIL_init(MAIL_box_t* mail_box) {
	assert(NULL != mail_box);

	mail_box->state = MAIL_EMPTY;
	SEMAPHORE_mutex_init(&mail_box->semaphore);
}

int8_t MAIL_write(MAIL_box_t* mail_box, int32_t message) {
	assert(NULL != mail_box);
	int8_t ret = MAIL_NOT_SENT;

	SEMAPHORE_wait(&mail_box->semaphore);
	if(MAIL_EMPTY == mail_box->state) {
		mail_box->message = message;
		mail_box->state = MAIL_NOT_EMPTY;
		ret = MAIL_SENT;
	}
	SEMAPHORE_signal(&mail_box->semaphore);

	return ret;
}

int8_t MAIL_read(MAIL_box_t* mail_box, int32_t* message) {
	assert(NULL != mail_box);
	assert(NULL != message);
	int8_t ret = MAIL_NOT_READ;

	if(MAIL_NOT_EMPTY == mail_box->state) {
		*message = mail_box->message;
		mail_box->state = MAIL_EMPTY;
		ret = MAIL_READ;
	}

	return ret;
}

void MAIL_empty(MAIL_box_t* mail_box) {
	assert(NULL != mail_box);

	mail_box->state = MAIL_EMPTY;
}