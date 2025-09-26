/*
 * digital_clock.h
 *
 *  Created on: Sep 26, 2025
 *      Author: ASUS
 */

#ifndef INC_DIGITAL_CLOCK_H_
#define INC_DIGITAL_CLOCK_H_

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
extern void clockRun(void);

#endif /* INC_DIGITAL_CLOCK_H_ */
