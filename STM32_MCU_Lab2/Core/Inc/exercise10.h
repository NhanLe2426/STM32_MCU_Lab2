/*
 * exercise10.h
 *
 *  Created on: Sep 26, 2025
 *      Author: ASUS
 */

#ifndef INC_EXERCISE10_H_
#define INC_EXERCISE10_H_

/* Includes */
#include "main.h"

/* Define */
#define WINDOW_BUFFER	16

/* Variables */
extern int index_led_matrix;

/* Functions */
extern void updateLEDMatrix(int index);
extern void clearLEDMatrix(void);
extern void shiftLeft(void);
extern void shiftRight(void);

#endif /* INC_EXERCISE10_H_ */
