/*
 * software_timer.h
 *
 *  Created on: Sep 24, 2025
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

/* Includes */
#include "main.h"

/* Define */
#define TIMER_CYCLE_1	1

/* Variables */
extern int timer1_flag;

/* Functions */
extern void timer1_set(int ms);
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
