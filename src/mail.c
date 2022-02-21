#include <mail.h>
#include <assert.h>
#include <stddef.h>

void MAIL_Init(MAIL_box_t* mail_box) {
	assert(NULL != mail_box);

	mail_box->state = MAIL_EMPTY;
}

int8_t MAIL_Write(MAIL_box_t* mail_box, int32_t message) {
	assert(NULL != mail_box);
	int8_t ret = MAIL_NOT_SENT;

	if(MAIL_EMPTY == mail_box->state) {
		mail_box->message = message;
		mail_box->state = MAIL_NOT_EMPTY;
		ret = MAIL_SENT;
	}

	return ret;
}

int8_t MAIL_Read(MAIL_box_t* mail_box, int32_t* message) {
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

void MAIL_Empty(MAIL_box_t* mail_box) {
	assert(NULL != mail_box);

	mail_box->state = MAIL_EMPTY;
}