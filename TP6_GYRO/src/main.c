/**
  ******************************************************************************
  * @file    Demonstrations/Src/main.c
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    01-July-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F3-Discovery_Demo STM32F3-Discovery_Demo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern int inc;
extern int iii;
struct coor vect_sequence[500];
__IO uint8_t UserButtonPressed = 0x00;
__IO uint32_t PressCount = 0;
USBD_HandleTypeDef USBD_Device;
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
/* Private functions ---------------------------------------------------------*/
static void Demo(void);
static void Demo2(void);
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */ 
int main(void)
{ 
  /* STM32F3xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();
  
    /* Initialize LEDs and User_Button on STM32F3-Discovery ------------------*/
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI); 
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED7);
  BSP_LED_Init(LED9);
  BSP_LED_Init(LED10);
  BSP_LED_Init(LED8);
  BSP_LED_Init(LED6);
  
  /* Configure the system clock to 72 Mhz */
  SystemClock_Config();

    /* Init USB Device Library */
 USBD_Init(&USBD_Device, &HID_Desc, 0);
  
  /* Register the USB HID class */
 USBD_RegisterClass(&USBD_Device, &USBD_HID);
  
  /* Start Device Process */
 USBD_Start(&USBD_Device);
  

  /* Infinite loop */
  while (1)
  {
    Demo2();
  }
}

/**
  * @brief  Exercise
  * @param  None
  * @retval None
  */
static void Demo2(void)
{
  	  BSP_LED_On(LED3);BSP_LED_On(LED4);BSP_LED_On(LED5);BSP_LED_On(LED6);BSP_LED_On(LED7);BSP_LED_On(LED8);BSP_LED_On(LED9);BSP_LED_On(LED10);

  	  /*FIRST CLIK ??*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
      {/*Button not pressed*/}/*Button pressed*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
      {/*BUtton pressed*/}/*Button not pressed*/
      /*FIRST CLIK !!*/

      BSP_LED_Off(LED3);BSP_LED_Off(LED4);BSP_LED_Off(LED5);BSP_LED_Off(LED6);BSP_LED_Off(LED7);BSP_LED_Off(LED8);BSP_LED_Off(LED9);BSP_LED_Off(LED10);
      if(BSP_GYRO_Init() != HAL_OK)
      	  {Error_Handler();}/*Initialisation GYRO sans attente*/

      while (inc<500)
      {
    	  GYRO_MEMS_Test();/*Utilisation GYRO*/
    	  inc=inc+1;
      }

      /*SECOND CLIK ??*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
      {/*Button not pressed*/}/*Button pressed*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
      {/*BUtton pressed*/}/*Button not pressed*/
      /*SECOND CLIK !!*/

      BSP_LED_On(LED3);BSP_LED_On(LED4);BSP_LED_On(LED5);BSP_LED_On(LED6);BSP_LED_On(LED7);BSP_LED_On(LED8);BSP_LED_On(LED9);BSP_LED_On(LED10);

      /*THIRD CLIK ??*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
      {/*Button not pressed*/}/*Button pressed*/
      while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
      {/*BUtton pressed*/}/*Button not pressed*/
      /*THIRD CLIK !!*/
      BSP_LED_Off(LED3);BSP_LED_Off(LED4);BSP_LED_Off(LED5);BSP_LED_Off(LED6);BSP_LED_Off(LED7);BSP_LED_Off(LED8);BSP_LED_Off(LED9);BSP_LED_Off(LED10);
  	  for(iii=0;iii<500;iii++)
    	  {
    		  BSP_LED_On(vect_sequence[iii].led_on);
    		  HAL_Delay(100);
    		  BSP_LED_Off(LED3);BSP_LED_Off(LED4);BSP_LED_Off(LED5);BSP_LED_Off(LED6);BSP_LED_Off(LED7);BSP_LED_Off(LED8);BSP_LED_Off(LED9);BSP_LED_Off(LED10);
    	  }

}

/**
* @brief  Demo.
* @param  None
* @retval None
*/
 static void Demo(void)
{
  /* 0. Wait for User button to be pressed -------------------------------------*/
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Toggle LED4 */
    BSP_LED_Toggle(LED4);
    HAL_Delay(20);
    /* Toggle LED3 */
    BSP_LED_Toggle(LED3);
    HAL_Delay(20);
    /* Toggle LED5 */
    BSP_LED_Toggle(LED5);
    HAL_Delay(20);
    /* Toggle LED7 */
    BSP_LED_Toggle(LED7);
    HAL_Delay(20);
    /* Toggle LED9 */
    BSP_LED_Toggle(LED9);
    HAL_Delay(20);
    /* Toggle LED10 */
    BSP_LED_Toggle(LED10);
    HAL_Delay(20);
    /* Toggle LED8 */
    BSP_LED_Toggle(LED8);
    HAL_Delay(20);
    /* Toggle LED6 */
    BSP_LED_Toggle(LED6);
    HAL_Delay(20);
  }
  /* Wait for User button is released */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
  {}
  
  /* 1. Gyroscope Mems Test -----------------------------------------------*/
  if(BSP_GYRO_Init() != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(); 
  }
  
  /* Wait for User button to be pressed */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Move discovery kit to detect negative and positive acceleration values 
    on X, Y axis for GYROSCOPE MEMS*/
    GYRO_MEMS_Test();
  }
  
  /* Wait for User button is released */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
  {}

  /* 2. Wait for User button to be pressed -------------------------------------*/
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Toggle LED4 */
    BSP_LED_Toggle(LED4);
    HAL_Delay(20);
    /* Toggle LED3 */
    BSP_LED_Toggle(LED3);
    HAL_Delay(20);
    /* Toggle LED5 */
    BSP_LED_Toggle(LED5);
    HAL_Delay(20);
    /* Toggle LED7 */
    BSP_LED_Toggle(LED7);
    HAL_Delay(20);
    /* Toggle LED9 */
    BSP_LED_Toggle(LED9);
    HAL_Delay(20);
    /* Toggle LED10 */
    BSP_LED_Toggle(LED10);
    HAL_Delay(20);
    /* Toggle LED8 */
    BSP_LED_Toggle(LED8);
    HAL_Delay(20);
    /* Toggle LED6 */
    BSP_LED_Toggle(LED6);
    HAL_Delay(20);
  }
  /* Wait for User button is released */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
  {}
  
  /* 3. Accelerometer Mems Test --------------------------------------------*/
  if(BSP_ACCELERO_Init() != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(); 
  }
  
  /* Wait for User button to be pressed */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Move discovery kit to detect negative and positive acceleration values 
    on X, Y and Z axis for ACCELERATOR MEMS*/
    ACCELERO_MEMS_Test();
  }
  /* Wait for User button is released */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
  {}
  
  /* 4. Wait for User button to be pressed -------------------------------------*/
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Toggle LED4 */
    BSP_LED_Toggle(LED4);
    HAL_Delay(20);
    /* Toggle LED3 */
    BSP_LED_Toggle(LED3);
    HAL_Delay(20);
    /* Toggle LED5 */
    BSP_LED_Toggle(LED5);
    HAL_Delay(20);
    /* Toggle LED7 */
    BSP_LED_Toggle(LED7);
    HAL_Delay(20);
    /* Toggle LED9 */
    BSP_LED_Toggle(LED9);
    HAL_Delay(20);
    /* Toggle LED10 */
    BSP_LED_Toggle(LED10);
    HAL_Delay(20);
    /* Toggle LED8 */
    BSP_LED_Toggle(LED8);
    HAL_Delay(20);
    /* Toggle LED6 */
    BSP_LED_Toggle(LED6);
    HAL_Delay(20);
  }
  
  /* Force The Leds to be Off before entring to the USB demo  */   
  BSP_LED_Off(LED3);
  BSP_LED_Off(LED5);
  BSP_LED_Off(LED7);
  BSP_LED_Off(LED9);
  BSP_LED_Off(LED10);
  BSP_LED_Off(LED8);
  BSP_LED_Off(LED6);
  
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
   {}

  /* Wait for User button to be pressed */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_PRESSED)
  {
    /* Wait for User button to be pressed to switch to USB demo
    Mouse cursor moving corresponding to board move direction  */
    USB_Demo();
  }
  
  /* Wait for User button is released */
  while (BSP_PB_GetState(BUTTON_USER) != KEY_NOT_PRESSED)
  {}

}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV                     = 1
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef  RCC_PeriphClkInit;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    Error_Handler();
  }
  
  /* Configures the USB clock */
  HAL_RCCEx_GetPeriphCLKConfig(&RCC_PeriphClkInit);
  RCC_PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);
  

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin==USER_BUTTON_PIN)
  {
   UserButtonPressed++;
   if (UserButtonPressed > 0x2)
    {
      UserButtonPressed = 0x0;
    }
  }
}

/**
  * @brief  This function handles the test program fail.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  while(1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
