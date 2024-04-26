/**************************************************************************************************
 * File: blink.h
 * Author: Jacob Clarey
 * Date: 4/25/2024
 * Description: This header is an example for where to place header files in this programming
 * environment. It contains function prototypes to blink LD2 on the NUCLEO-F446RE board.
 *************************************************************************************************/

/* HEADER GUARD */
#ifndef __BLINK_H__
#define __BLINK_H__

/**************************************************************************************************
 * INCLUDED HEADERS
 *************************************************************************************************/

#include <stm32f446xx.h>

/**************************************************************************************************
 *************************************************************************************************/

/**************************************************************************************************
 * PREPROCESSOR DIRECTIVES
 *************************************************************************************************/

#define BLINK_DELAY 500 // blink period in milliseconds

#define LD2_PORT GPIOA
#define LD2_PIN 5

/**************************************************************************************************
 *************************************************************************************************/

/**************************************************************************************************
 * FUNCTION PROTOTYPES
 *************************************************************************************************/
/// @brief This function initializes LD2_PORT LD2_PIN as an output
void initLD2(void);

/// @brief This function toggles an output on LD2PORT LD2PIN
void toggleLD2(void);

/// @brief This function creates a brute force delay by counting down an integer
/// @param n is the value to count down from
void bruteDelay(uint32_t n);

/// @brief This functions initializes the Systick timer for basic delays
void systickInit(void);

/// @brief This functions delays for a specified amount of milliseconds
/// @param n is the number of milliseconds to delay
void systickDelayMS(uint32_t n);

/// @brief This functions delays for a specified amount of microseconds
/// @param n is the number of milliseconds to delay
void systickDelayUS(uint32_t n);

/**************************************************************************************************
 *************************************************************************************************/

/* HEADER GUARD */
#endif // __BLINK_H__

/* EOF */
