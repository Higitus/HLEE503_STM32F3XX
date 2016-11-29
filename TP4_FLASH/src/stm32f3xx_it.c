/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32f3xx_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */


char nb_dbl_clic = 0;

int intervalcnt = 0;
int interval30 =0;
char firstclick = 0;


void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

	if (interval30<30000){
		BSP_LED_On(LED4);
			if (intervalcnt >= 1000) {
				firstclick = 0;
				intervalcnt = 0;
			}
			else
				intervalcnt++;
		}
	else{
		if(nb_dbl_clic<5){
			BSP_LED_On(LED3);
			BSP_LED_Off(LED7);
		}
		else{
			BSP_LED_On(LED7);
			BSP_LED_Off(LED4);
		}

}

#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}



void EXTI0_IRQHandler(void) {


	if (firstclick == 0) {

		firstclick = 1;

	}
	else  {
		if (intervalcnt < 1000) { // counts until 1s at maximum
			// second click
			nb_dbl_clic = (nb_dbl_clic + 1) /*% 2*/;
		}
		intervalcnt = 0;
		firstclick = 0;

	}

	LL_EXTI_ClearFlag_0_31 (LL_EXTI_LINE_0);
	/* mandatory function to clear the Interrupt request */
}

