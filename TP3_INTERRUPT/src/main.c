/**
  ******************************************************************************
  * @file    main.c
  * @author  SIRANGAMA Matthieu
  * @version V1.0
  * @date    22-Nov-2016
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f3xx.h"
#include "stm32f3_discovery.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_it.h"

int dblr_clic;
int state;
int cnt;

//EXERCICE 3
int main(void)
{
	dblr_clic = 0;
	state=0;
	cnt=0;
	BSP_LED_Init(LED4);
	BSP_LED_On(LED4);
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
	for(;;) {
		if(dblr_clic==0) {

			if (SysTick_Config(SystemCoreClock/10)) {
				//while(1);
			}
		}
		else {
			if (SysTick_Config(SystemCoreClock/2)) {
				//while(1);
			}
		}
	}
}

//EXERCICE 2
//int main(void)
//{
//	BSP_LED_Init(LED7);BSP_LED_Init(LED4);
//	BSP_LED_On(LED4);
//	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
//		if (SysTick_Config(SystemCoreClock/9)) {
//			while(1);
//		};
//	return 1;
//}

// EXERCICE 1
//int main(void)
//{
//	int press;
//	BSP_LED_Init(LED7);
//	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
//	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
//
//	for(;;)
//	{
//		press=BSP_PB_GetState(BUTTON_USER);
//		if (press==1){
//			BSP_LED_On(LED7);
//		};
//	};
//	return 1;
//}
