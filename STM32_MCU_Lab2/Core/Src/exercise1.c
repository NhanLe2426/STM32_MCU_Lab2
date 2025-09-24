/*
 * exercise1.c
 *
 *  Created on: Sep 24, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise1.h"
#include "led_7seg.h"

/* Define */
#define LED_7SEG_1	1
#define LED_7SEG_2	2

/* Variables */
int currentState = LED_7SEG_1;

/* Functions */

/**
 * @brief	Display 2 7-segment LEDs
 * @param	None
 * @retval	None
 */
void display(void) {
	switch (currentState) {
	case LED_7SEG_1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

		display7SEG(1);
		currentState = LED_7SEG_2;
		break;

	case LED_7SEG_2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);

		display7SEG(2);
		currentState = LED_7SEG_1;
		break;

	default:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

		break;
	}
}
