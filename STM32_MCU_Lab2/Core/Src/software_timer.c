/*
 * software_timer.c
 *
 *  Created on: Sep 24, 2025
 *      Author: ASUS
 */

/* Includes */
#include "software_timer.h"

/* Variables */
int timer1_flag = 0;
int timer1_counter = 0;

/* Functions */

/**
 * @brief	Set duration of software timer interrupt
 * @param	duration : Duration of software timer interrupt
 * @retval 	None
 */
void timer1_set(int ms) {
	timer1_counter = ms;
	timer1_flag = 0;
}

/**
 * @brief	Run the timer
 * @param	None
 * @retval	None
 */
void timerRun(void) {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}
