/*
 * exercise2.c
 *
 *  Created on: Sep 24, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise2.h"
#include "led_7seg.h"

/* Variables */
int currentState = LED_7SEG_1;

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
 * @brief	Display 4 7-segment LEDs (switching time for each LED is half of second)
 * @param	None
 * @retval	None
 */
void display4LEDs(void) {
	switch (currentState) {
	case LED_7SEG_1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(1);
		currentState = LED_7SEG_2;
		break;

	case LED_7SEG_2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		display7SEG(2);
		currentState = LED_7SEG_3;
		break;

	case LED_7SEG_3:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

		display7SEG(3);
		currentState = LED_7SEG_4;
		break;

	case LED_7SEG_4:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

		display7SEG(0);
		currentState = LED_7SEG_1;
		break;

	default:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

		break;
	}
}
