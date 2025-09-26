/*
 * exercise678.h
 *
 *  Created on: Sep 25, 2025
 *      Author: ASUS
 */

#ifndef INC_EXERCISE678_H_
#define INC_EXERCISE678_H_

/* Includes */
#include "main.h"
#include "led_7seg.h"

/* Variables */
extern int index_led;
extern int hour;
extern int minute;
extern int second;

/* Functions */
extern void displayDot(void);
extern void update7SEG(int index);
extern void updateClockBuffer(void);
extern void clockRun(int hour, int minute, int second);

#endif /* INC_EXERCISE678_H_ */
