/**
 * @file	mail.h
 * @author	helder
 * @date	2022-02-21
 * @brief	Header file of the RTOS mail box.
 */

#ifndef MAIL_H
#define MAIL_H

#include <stdint.h>

#define MAIL_EMPTY      0
#define MAIL_NOT_EMPTY -1
#define MAIL_SENT       0
#define MAIL_NOT_SENT  -1
#define MAIL_READ       0
#define MAIL_NOT_READ  -1

typedef struct MAIL_box {
    int32_t message;
    int8_t  state;
} MAIL_box_t;

void MAIL_Init(MAIL_box_t* mail_box);
int8_t MAIL_Write(MAIL_box_t* mail_box, int32_t message);
int8_t MAIL_Read(MAIL_box_t* mail_box, int32_t* message);
void MAIL_Empty(MAIL_box_t* mail_box);

#endif

/**** end of file ****/
