/**************************************************************************************************
 * File: blink.h
 * Author: Jacob Clarey
 * Date: 4/25/2024
 * Description: This header is an example for where to place header files in this programming
 * environment. It contains function prototypes to blink LD2 on the NUCLEO-F446RE board.
 *************************************************************************************************/

#ifndef __BLINK_H__
#define __BLINK_H__

#include <stm32f446xx.h>

#define LD2_PORT GPIOA
#define LD2_PIN 5

void initLD2(void);
void toggleLD2(void);
void bruteDelay(uint32_t n);

void systickInit(void);
void systickDelayMS(uint32_t n);
void systickDelayUS(uint32_t n);

#endif // __BLINK_H__

/* EOF */
