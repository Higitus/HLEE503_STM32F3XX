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
#include "stm32f3_discovery.h"
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
int indiceH=0;

void SysTick_Handler(void)
{
	indiceH++;
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

	BSP_LED_Toggle(LED3);
	if(indiceH%2==0){
	BSP_LED_Toggle(LED7);
	}

#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif

}
