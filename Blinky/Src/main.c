/**************************************************************************************************
 * File: main.c
 * Author: Jacob Clarey
 * Date: 4/25/2024
 * Description: This program blinks LD2 on a NUCLEO-F446RE board as an example for setting up a
 * VSCode STM32 programming environment using a GNU Makefile. This can be modified for other MCUs.
 *************************************************************************************************/

#include "blink.h"
#include <stm32f446xx.h>

int main(void)
{
  gpioInit();

  while (1)
  {
    bruteDelay(2000000);
    toggleLD2();
  } // while(1)
} // main(void)

/* EOF */
