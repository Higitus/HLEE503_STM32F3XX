/**
  ******************************************************************************
  * @file    main.c
  * @author  SIRANGAMA
  * @version V1.2
  * @date    15-November-2016
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f3xx.h"
#include "stm32f3_discovery.h"

int main(void)
{
	int indice=0;
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED6);
	BSP_LED_Init(LED7);
	BSP_LED_Init(LED8);
	BSP_LED_Init(LED9);
	BSP_LED_Init(LED10);

	//BSP_LED_On(LED3);
	//BSP_LED_Off(LED7);

	if (SysTick_Config(SystemCoreClock / 9)) {
		indice=9;
		while (1);
	}
	while (1);
	return 1;
}
