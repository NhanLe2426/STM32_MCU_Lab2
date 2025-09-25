/*
 * exercise4.c
 *
 *  Created on: Sep 25, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise4.h"
#include "led_7seg.h"

/* Variables */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = { 2, 4, 6, 8 };

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
