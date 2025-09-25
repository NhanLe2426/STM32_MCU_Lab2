/*
 * led_7seg.c
 *
 *  Created on: Sep 25, 2025
 *      Author: ASUS
 */

/* Includes */
#include "led_7seg.h"

/* Functions */

/**
 * @brief	Display number on 7-segment LED
 * @param	num : number displayed on LED
 * @retval	None
 */
void display7SEG(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);

		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 1:
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);

		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 2:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		break;

	case 3:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		break;

	case 4:
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, SET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	case 5:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	case 6:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, SET);
		break;

	case 7:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);

		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, SET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, SET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, SET);
		break;

	case 8:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);
		break;

	case 9:
		HAL_GPIO_WritePin(LED7_a_GPIO_Port, LED7_a_Pin, RESET);
		HAL_GPIO_WritePin(LED7_b_GPIO_Port, LED7_b_Pin, RESET);
		HAL_GPIO_WritePin(LED7_c_GPIO_Port, LED7_c_Pin, RESET);
		HAL_GPIO_WritePin(LED7_d_GPIO_Port, LED7_d_Pin, RESET);
		HAL_GPIO_WritePin(LED7_f_GPIO_Port, LED7_f_Pin, RESET);
		HAL_GPIO_WritePin(LED7_g_GPIO_Port, LED7_g_Pin, RESET);

		HAL_GPIO_WritePin(LED7_e_GPIO_Port, LED7_e_Pin, SET);
		break;

	default:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, SET);
		break;
	}
}

/**
 * @brief	Clear number on 7-segment LED
 * @param	None
 * @retval	None
 */
void clear7SEG(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, SET);
}
