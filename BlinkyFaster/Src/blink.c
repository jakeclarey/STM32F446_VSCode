/**************************************************************************************************
 * File: blink.c
 * Author: Jacob Clarey
 * Date: 4/25/2024
 * Description: This source is an example for where to place source files in this programming
 * environment. It contains function definitions to blink LD2 on the NUCLEO-F446RE board.
 *************************************************************************************************/

#include "blink.h"

/**************************************************************************************************
 * FUNCTION DEFINITIONS
 *************************************************************************************************/
/// @brief This function initializes LD2_PORT LD2_PIN as an output
void initLD2(void)
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

/// @brief This functions initializes the Systick timer for basic delays
void systickInit(void)
{
  SysTick->CTRL = 0;
  SysTick->LOAD = 0x00FFFFFF;
  SysTick->VAL = 0;
  SysTick->CTRL |= 5;
}

/// @brief This functions delays for a specified amount of milliseconds
/// @param n is the number of milliseconds to delay
void systickDelayMS(uint32_t n)
{
  SysTick->LOAD = 16000 * (n - 1);
  SysTick->VAL = 0;
  while (!(SysTick->CTRL & (1U << 16)))
  {
  }
}

/// @brief This functions delays for a specified amount of microseconds
/// @param n is the number of milliseconds to delay
void systickDelayUS(uint32_t n)
{
  SysTick->LOAD = 16 * (n - 1);
  SysTick->VAL = 0;
  while (!(SysTick->CTRL & (1U << 16)))
  {
  }
}

/**************************************************************************************************
 *************************************************************************************************/

/* EOF */
