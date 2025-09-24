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
#define TIMER_CYCLE_1	10
#define TIMER_CYCLE_2	10
#define TIMER_CYCLE_3	10

/* Variables */
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

/* Functions */
extern void timer1_set(int duration);
extern void timer2_set(int duration);
extern void timer3_set(int duration);
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
