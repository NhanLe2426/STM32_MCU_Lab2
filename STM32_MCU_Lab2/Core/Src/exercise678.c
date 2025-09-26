/*
 * exercise678.c
 *
 *  Created on: Sep 25, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise678.h"
#include "led_7seg.h"

/* Variables */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = { 1, 5, 5, 8 };

int hour;
int minute;
int second;

/* Functions */

/**
 * @brief	Display 2 LEDs as 2 dots
 * @param	None
 * @retval	None
 */
void displayDot(void) {
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}

/**
 * @brief	Update the 7-segment LEDs based on an array of 4 integer numbers
 * @param	index : the index of LED displayed
 * @retval	None
 */
void update7SEG(int index) {
	switch (index) {
	case 0:
		// Display the first 7SEG with led_buffer[0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[0]);
		break;

	case 1:
		// Display the second 7SEG with led_buffer[1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[1]);
		break;

	case 2:
		// Display the third 7SEG with led_buffer[2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(led_buffer[2]);
		break;

	case 3:
		// Display the forth 7SEG with led_buffer[3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

		display7SEG(led_buffer[3]);
		break;

	default:
		break;
	}
}

/**
 * @brief	Generate values for the array led_buffer according to the values of hour and minute
 * @param	None
 * @retval	None
 */
void updateClockBuffer(void) {
	int temp1 = hour / 10;
	int temp2 = minute / 10;
	led_buffer[0] = temp1;
	led_buffer[1] = hour - (temp1 * 10);
	led_buffer[2] = temp2;
	led_buffer[3] = minute - (temp2 * 10);
}

/**
 * @brief	Simulate the clock behavior
 * @param	None
 * @retval	None
 */
void clockRun(void) {
	second++;
	if (second >= 60) {
		second = 0;
		minute++;
	}
	if (minute >= 60) {
		minute = 0;
		hour++;
	}
	if (hour >= 24) {
		hour = 0;
	}
}
