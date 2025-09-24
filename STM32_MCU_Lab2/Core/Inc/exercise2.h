/*
 * exercise2.h
 *
 *  Created on: Sep 24, 2025
 *      Author: ASUS
 */

#ifndef INC_EXERCISE2_H_
#define INC_EXERCISE2_H_

/* Includes */
#include "main.h"
#include "led_7seg.h"

/* Define */
#define LED_7SEG_1	1
#define LED_7SEG_2	2
#define LED_7SEG_3	3
#define LED_7SEG_4	4

/* Variables */
extern int currentState;

/* Functions */
extern void displayDot(void);
extern void display4LEDs(void);


#endif /* INC_EXERCISE2_H_ */
