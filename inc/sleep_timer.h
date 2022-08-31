#ifndef SLEEP_TIMER_H
#define SLEEP_TIMER_H

#include <stdint.h>

/**
 * @brief Initialize the sleep timer to trigger ever given uS.
 * 
 * @param period_uS Period in uS.
 * @return void
 */ 
void SLEEP_TIMER_init(uint32_t period_uS);

#endif /* SLEEP_TIMER_H */

/* end of file */
