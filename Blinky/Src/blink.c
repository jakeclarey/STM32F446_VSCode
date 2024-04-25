/**************************************************************************************************
 * File: blink.c
 * Author: Jacob Clarey
 * Date: 4/25/2024
 * Description: This source is an example for where to place source files in this programming
 * environment. It contains function definitions to blink LD2 on the NUCLEO-F446RE board.
 *************************************************************************************************/

#include "blink.h"

/// @brief This function initializes LD2_PORT LD2_PIN as an output
void gpioInit(void)
{
  RCC->AHB1ENR |= 1;
  LD2_PORT->MODER &= ~(3 << (2 * LD2_PIN));
  LD2_PORT->MODER |= 1U << (2 * LD2_PIN);
}

/// @brief This function toggles an output on LD2PORT LD2PIN
void toggleLD2(void)
{
  LD2_PORT->ODR ^= 1U << LD2_PIN; // toggle LD2 output
}

/// @brief This function creates a brute force delay by counting down an integer
/// @param n is the value to count down from
void bruteDelay(uint32_t n)
{
  for (; n > 0; n--)
  {
    n--; // optimizes out if the loop does nothing, so count down 2nd time
  }
}

/* EOF */
