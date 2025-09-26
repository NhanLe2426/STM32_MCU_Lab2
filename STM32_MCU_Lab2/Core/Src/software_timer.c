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

int timer2_flag = 0;
int timer2_counter = 0;

int timer3_flag = 0;
int timer3_counter = 0;

int timer4_flag = 0;
int timer4_counter = 0;

int timer5_flag = 0;
int timer5_counter = 0;

/* Functions */

/**
 * @brief	Set duration of software timer interrupt
 * @param	duration : Duration of software timer interrupt
 * @retval 	None
 */
void timer1_set(int duration) {
	timer1_counter = duration / TIMER_CYCLE_1;
	timer1_flag = 0;
}

void timer2_set(int duration) {
	timer2_counter = duration / TIMER_CYCLE_2;
	timer2_flag = 0;
}

void timer3_set(int duration) {
	timer3_counter = duration / TIMER_CYCLE_3;
	timer3_flag = 0;
}

void timer4_set(int duration) {
	timer4_counter = duration / TIMER_CYCLE_4;
	timer4_flag = 0;
}

void timer5_set(int duration) {
	timer5_counter = duration / TIMER_CYCLE_5;
	timer5_flag = 0;
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

	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}

	if (timer3_counter > 0) {
		timer3_counter--;
		if (timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}

	if (timer4_counter > 0) {
		timer4_counter--;
		if (timer4_counter <= 0) {
			timer4_flag = 1;
		}
	}

	if (timer5_counter > 0) {
		timer5_counter--;
		if (timer5_counter <= 0) {
			timer5_flag = 1;
		}
	}
}
