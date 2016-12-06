/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @author  SIRANGAMA Matthieu
  * @version V1.1
  * @date    06-December-2016
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

/*Private include*/
#include "stm32f3xx_ll_exti.h"
#include "main.h"
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
void SysTick_Handler()
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
	gestion_temps();//declaration dans main.h & definition dans main.c
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}

void EXTI0_IRQHandler() {
	gestion_pieton();//declaration dans main.h & definition dans main.c
	LL_EXTI_ClearFlag_0_31 (LL_EXTI_LINE_0);//#define LL_EXTI_LINE_0 EXTI_IMR_IM0
}
