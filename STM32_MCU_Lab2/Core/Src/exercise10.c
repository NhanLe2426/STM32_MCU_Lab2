/*
 * exercise10.c
 *
 *  Created on: Sep 26, 2025
 *      Author: ASUS
 */

/* Includes */
#include "exercise10.h"

/* Variables */
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {
		0x18,	// 0-0-0-x-x-0-0-0
		0x3C,	// 0-0-x-x-x-x-0-0
		0x66,	// 0-x-x-0-0-x-x-0
		0x66,	// 0-x-x-0-0-x-x-0
		0x7E,	// 0-x-x-x-x-x-x-0
		0x7E,	// 0-x-x-x-x-x-x-0
		0x66,	// 0-x-x-0-0-x-x-0
		0x66	// 0-x-x-0-0-x-x-0
};

uint8_t window_buffer[8][16] = {
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x18 - 0x00
		{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x3C - 0x00
		{0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x66 - 0x00
		{0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x66 - 0x00
		{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x7E - 0x00
		{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x7E - 0x00
		{0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},		// 0x66 - 0x00
		{0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}		// 0x66 - 0x00
};

int offset_L = 0;
int offset_R = 0;

/* Functions */

/**
 * @brief	Update the LED Matrix 8x8 based on the matrix buffer array to display result
 * @param	index : the index of the columns displayed
 * @retval	None
 */
void updateLEDMatrix(int index) {
	// Turn off all the columns
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);

	// Get the data of the current column
/*
 * 	This code displays the character in horizontal
 *
	uint8_t data = matrix_buffer[index];

	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (data & 0x01) ? RESET : SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (data & 0x02) ? RESET : SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (data & 0x04) ? RESET : SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (data & 0x08) ? RESET : SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (data & 0x10) ? RESET : SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (data & 0x20) ? RESET : SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (data & 0x40) ? RESET : SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (data & 0x80) ? RESET : SET);
 *
 *
 */

/*
 * 	This code displays the character in vertical
 */
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (matrix_buffer[0] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (matrix_buffer[1] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (matrix_buffer[2] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (matrix_buffer[3] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (matrix_buffer[4] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (matrix_buffer[5] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (matrix_buffer[6] >> index) & 0x01 ? RESET : SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (matrix_buffer[7] >> index) & 0x01 ? RESET : SET);

	// Display the column at the index position
	switch (index) {
	case 0:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
		break;

	case 1:
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
		break;

	case 2:
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
		break;

	case 3:
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
		break;

	case 4:
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
		break;

	case 5:
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
		break;

	case 6:
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
		break;

	case 7:
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
		break;

	default:
		break;
	}
}

/**
 * @brief	Clear the LED Matrix 8x8
 * @param	None
 * @retval	None
 */
void clearLEDMatrix(void) {
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
}

/**
 * @brief	Shift the character to the left
 * @param	None
 * @retval	None
 */
void shiftLeft(void) {
	// Shift each row to the left 1 unit
	matrix_buffer[0] = (window_buffer[0][offset_L + 0] << 0) |
					   (window_buffer[0][offset_L + 1] << 1) |
					   (window_buffer[0][offset_L + 2] << 2) |
					   (window_buffer[0][offset_L + 3] << 3) |
					   (window_buffer[0][offset_L + 4] << 4) |
					   (window_buffer[0][offset_L + 5] << 5) |
					   (window_buffer[0][offset_L + 6] << 6) |
					   (window_buffer[0][offset_L + 7] << 7);
	matrix_buffer[1] = (window_buffer[1][offset_L + 0] << 0) |
			   	   	   (window_buffer[1][offset_L + 1] << 1) |
					   (window_buffer[1][offset_L + 2] << 2) |
					   (window_buffer[1][offset_L + 3] << 3) |
					   (window_buffer[1][offset_L + 4] << 4) |
					   (window_buffer[1][offset_L + 5] << 5) |
					   (window_buffer[1][offset_L + 6] << 6) |
					   (window_buffer[1][offset_L + 7] << 7);
	matrix_buffer[2] = (window_buffer[2][offset_L + 0] << 0) |
			   	   	   (window_buffer[2][offset_L + 1] << 1) |
					   (window_buffer[2][offset_L + 2] << 2) |
					   (window_buffer[2][offset_L + 3] << 3) |
					   (window_buffer[2][offset_L + 4] << 4) |
					   (window_buffer[2][offset_L + 5] << 5) |
					   (window_buffer[2][offset_L + 6] << 6) |
					   (window_buffer[2][offset_L + 7] << 7);
	matrix_buffer[3] = (window_buffer[3][offset_L + 0] << 0) |
			   	   	   (window_buffer[3][offset_L + 1] << 1) |
					   (window_buffer[3][offset_L + 2] << 2) |
					   (window_buffer[3][offset_L + 3] << 3) |
					   (window_buffer[3][offset_L + 4] << 4) |
					   (window_buffer[3][offset_L + 5] << 5) |
					   (window_buffer[3][offset_L + 6] << 6) |
					   (window_buffer[3][offset_L + 7] << 7);
	matrix_buffer[4] = (window_buffer[4][offset_L + 0] << 0) |
			   	   	   (window_buffer[4][offset_L + 1] << 1) |
					   (window_buffer[4][offset_L + 2] << 2) |
					   (window_buffer[4][offset_L + 3] << 3) |
					   (window_buffer[4][offset_L + 4] << 4) |
					   (window_buffer[4][offset_L + 5] << 5) |
					   (window_buffer[4][offset_L + 6] << 6) |
					   (window_buffer[4][offset_L + 7] << 7);
	matrix_buffer[5] = (window_buffer[5][offset_L + 0] << 0) |
			   	   	   (window_buffer[5][offset_L + 1] << 1) |
					   (window_buffer[5][offset_L + 2] << 2) |
					   (window_buffer[5][offset_L + 3] << 3) |
					   (window_buffer[5][offset_L + 4] << 4) |
					   (window_buffer[5][offset_L + 5] << 5) |
					   (window_buffer[5][offset_L + 6] << 6) |
					   (window_buffer[5][offset_L + 7] << 7);
	matrix_buffer[6] = (window_buffer[6][offset_L + 0] << 0) |
			   	   	   (window_buffer[6][offset_L + 1] << 1) |
					   (window_buffer[6][offset_L + 2] << 2) |
					   (window_buffer[6][offset_L + 3] << 3) |
					   (window_buffer[6][offset_L + 4] << 4) |
					   (window_buffer[6][offset_L + 5] << 5) |
					   (window_buffer[6][offset_L + 6] << 6) |
					   (window_buffer[6][offset_L + 7] << 7);
	matrix_buffer[7] = (window_buffer[7][offset_L + 0] << 0) |
			   	   	   (window_buffer[7][offset_L + 1] << 1) |
					   (window_buffer[7][offset_L + 2] << 2) |
					   (window_buffer[7][offset_L + 3] << 3) |
					   (window_buffer[7][offset_L + 4] << 4) |
					   (window_buffer[7][offset_L + 5] << 5) |
					   (window_buffer[7][offset_L + 6] << 6) |
					   (window_buffer[7][offset_L + 7] << 7);

	// Increase the offset
	offset_L++;
	if (offset_L > 8) offset_L = 0;		// reset the offset
}

void shiftRight(void) {
	// Shift each row to the right 1 unit
	matrix_buffer[0] = (window_buffer[0][offset_R + 0] >> 0) |
					   (window_buffer[0][offset_R + 1] >> 1) |
					   (window_buffer[0][offset_R + 2] >> 2) |
					   (window_buffer[0][offset_R + 3] >> 3) |
					   (window_buffer[0][offset_R + 4] >> 4) |
					   (window_buffer[0][offset_R + 5] >> 5) |
					   (window_buffer[0][offset_R + 6] >> 6) |
					   (window_buffer[0][offset_R + 7] >> 7);
	matrix_buffer[1] = (window_buffer[1][offset_R + 0] >> 0) |
				   	   (window_buffer[1][offset_R + 1] >> 1) |
					   (window_buffer[1][offset_R + 2] >> 2) |
					   (window_buffer[1][offset_R + 3] >> 3) |
					   (window_buffer[1][offset_R + 4] >> 4) |
					   (window_buffer[1][offset_R + 5] >> 5) |
					   (window_buffer[1][offset_R + 6] >> 6) |
					   (window_buffer[1][offset_R + 7] >> 7);
	matrix_buffer[2] = (window_buffer[2][offset_R + 0] >> 0) |
				   	   (window_buffer[2][offset_R + 1] >> 1) |
					   (window_buffer[2][offset_R + 2] >> 2) |
					   (window_buffer[2][offset_R + 3] >> 3) |
					   (window_buffer[2][offset_R + 4] >> 4) |
					   (window_buffer[2][offset_R + 5] >> 5) |
					   (window_buffer[2][offset_R + 6] >> 6) |
					   (window_buffer[2][offset_R + 7] >> 7);
	matrix_buffer[3] = (window_buffer[3][offset_R + 0] >> 0) |
				   	   (window_buffer[3][offset_R + 1] >> 1) |
					   (window_buffer[3][offset_R + 2] >> 2) |
					   (window_buffer[3][offset_R + 3] >> 3) |
					   (window_buffer[3][offset_R + 4] >> 4) |
					   (window_buffer[3][offset_R + 5] >> 5) |
					   (window_buffer[3][offset_R + 6] >> 6) |
					   (window_buffer[3][offset_R + 7] >> 7);
	matrix_buffer[4] = (window_buffer[4][offset_R + 0] >> 0) |
				   	   (window_buffer[4][offset_R + 1] >> 1) |
					   (window_buffer[4][offset_R + 2] >> 2) |
					   (window_buffer[4][offset_R + 3] >> 3) |
					   (window_buffer[4][offset_R + 4] >> 4) |
					   (window_buffer[4][offset_R + 5] >> 5) |
					   (window_buffer[4][offset_R + 6] >> 6) |
					   (window_buffer[4][offset_R + 7] >> 7);
	matrix_buffer[5] = (window_buffer[5][offset_R + 0] >> 0) |
				   	   (window_buffer[5][offset_R + 1] >> 1) |
					   (window_buffer[5][offset_R + 2] >> 2) |
					   (window_buffer[5][offset_R + 3] >> 3) |
					   (window_buffer[5][offset_R + 4] >> 4) |
					   (window_buffer[5][offset_R + 5] >> 5) |
					   (window_buffer[5][offset_R + 6] >> 6) |
					   (window_buffer[5][offset_R + 7] >> 7);
	matrix_buffer[6] = (window_buffer[6][offset_R + 0] >> 0) |
				   	   (window_buffer[6][offset_R + 1] >> 1) |
					   (window_buffer[6][offset_R + 2] >> 2) |
					   (window_buffer[6][offset_R + 3] >> 3) |
					   (window_buffer[6][offset_R + 4] >> 4) |
					   (window_buffer[6][offset_R + 5] >> 5) |
					   (window_buffer[6][offset_R + 6] >> 6) |
					   (window_buffer[6][offset_R + 7] >> 7);
	matrix_buffer[7] = (window_buffer[7][offset_R + 0] >> 0) |
				   	   (window_buffer[7][offset_R + 1] >> 1) |
					   (window_buffer[7][offset_R + 2] >> 2) |
					   (window_buffer[7][offset_R + 3] >> 3) |
					   (window_buffer[7][offset_R + 4] >> 4) |
					   (window_buffer[7][offset_R + 5] >> 5) |
					   (window_buffer[7][offset_R + 6] >> 6) |
					   (window_buffer[7][offset_R + 7] >> 7);

	// Increase the offset
	offset_R++;
	if (offset_R > 8) offset_R = 0;		// reset the offset
}
