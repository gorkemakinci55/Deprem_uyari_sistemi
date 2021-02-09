/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "at_commands.h"
#include "bc95.h"
#include "bc95_work_functions.h"
#include "bma400.h"
#include "string.h"
#include "data_queue.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
//void HAL_UART_RxCpltCallback(&huart2){
//
//
//
//}
void bc95_init();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
struct bc95_dev *bc95;
int AT_READY_FLAG = 0;
int uartReady = 0;
char  rxBuf[180];
char parsedData[10][50];
int wordIndex = 0;
int charIndex = 0;
queue dataQueue;
char rxBuf_IT;
int  AT_Transmit_FLag = 0;
int AT_Waiting_Flag = 0;
int DATA_READY = 0;
int rx_callback_count = 0;
int timAbortCount = 0;
//char buffer1[14] = "AT+QLEDMODE=1";
char buffer1[4] = "ATI";
int rxIndex = 0;
int count = 0;
int rxcallbackCount = 0;
int abourtCount = 0;
HAL_StatusTypeDef gorkem = HAL_ERROR;



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    /* Init BMA400 */



  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  //bc95_at_start_check(bc95);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  init_queue(&dataQueue);
  /* USER CODE BEGIN 2 */
  //bc95_init();
  //bma400_init();
  //1.Activate SPI line, make CS LOW
  //HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
  //2.Transmit register address

  //3.Read register data
  //HAL_UART_Receive_IT(&huart1,buffer,4);
  //4.Deactiviate SPI line, make CS HIGH
  //HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_UART_Receive_IT(&huart1,(uint8_t*)&rxBuf_IT,1);
  HAL_TIM_Base_Start_IT(&htim2);
//  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
//  HAL_Delay(3000);
//  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
//  HAL_UART_Receive_IT(&huart1,buffer,4);
//  HAL_StatusTypeDef Mustafa = HAL_UART_Transmit(&huart1,buffer1,10,1000);
//  HAL_StatusTypeDef Mustafa = HAL_UART_Transmit(&huart1,buffer1,14,1000);
//  HAL_UART_Receive_IT(&huart1,buffer,4);
//  HAL_StatusTypeDef gORKEM = HAL_UART_Receive(&huart1,buffer,50,10000);
//  if(Mustafa == HAL_OK){
//      HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
//      HAL_Delay(6000);
//      HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
//  }
//HAL_UART_Receive(&huart1,buffer,10,1000);
//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
//HAL_Delay(3000);
//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
//  HAL_UART_RxCpltCallback(&huart1);



//HAL_Delay(3000);
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      if(uartReady == 0){
          gorkem = HAL_UART_Receive_IT(&huart1,(uint8_t*)&rxBuf_IT,1);
      }


          uartReady = 1;
          if(gorkem == HAL_TIMEOUT){

          }

          //parsedData[wordIndex][charIndex] = dequeue(&dataQueue);
          //int temp2 = charIndex - 1;

//          if(parsedData[wordIndex][charIndex] == '\n' && parsedData[wordIndex][temp2] == '\r'){
//              //HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_11);
//              charIndex = 0;
//              if(parsedData[wordIndex][0] == 'N' && parsedData[wordIndex][1] == 'e' && parsedData[wordIndex][2] == 'u' && parsedData[wordIndex][3] == 'l'){
//                  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_11);
//                  AT_READY_FLAG = 1;
//                  DATA_READY = 0;
//                  break;
//              }
//              ++wordIndex;
//              break;
//          }
//          ++charIndex;




  /* USER CODE END 3 */
}
}

  void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

      if(huart->Instance==USART1 ){

           enqueue(&dataQueue, rxBuf_IT);
           gorkem = HAL_UART_Receive_IT(&huart1,(uint8_t*)&rxBuf_IT, 1);
      }
  }


  void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

       // HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_12);
      //gorkem = HAL_UART_GetState(&huart1);
        AT_Transmit_FLag = 0;

        AT_Waiting_Flag = 1;
        HAL_UART_Receive_IT(&huart1,(uint8_t*)&rxBuf_IT,1);
        ++count;
  }

  void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart){

      if(huart->Instance==USART1 ){
          clear_queue(&dataQueue);

          gorkem = HAL_UART_GetState(&huart1);
          ++abourtCount;
          AT_Transmit_FLag = 1;
      }
  }

  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

      if(htim->Instance == TIM2){
          if((gorkem = HAL_UART_GetState(&huart1)) == HAL_UART_STATE_BUSY_RX && (AT_Waiting_Flag == 1 || AT_READY_FLAG == 1)){
              HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_12);
              AT_Waiting_Flag = 0;
              ++timAbortCount;
              HAL_UART_AbortReceive_IT(&huart1);
          }

        //  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_12);
          HAL_TIM_Base_Start_IT(&htim2);
      }
  }
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_HARD_OUTPUT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 31999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 2999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void bma400_init(){

      /* BMA400 INTERFACE */

      bma400_dev* bma400ptr = NULL;

      bma400_sensor_data bma400SensorData = {0};
//      bma400SensorData.sensortime = 0;
//      bma400SensorData.x = 0;
//      bma400SensorData.y = 0;
//      bma400SensorData.z = 0;
      set_bma400_interface(BMA400_SPI_INTF, bma400ptr);
      bma400ptr->intf_ptr = &hspi2;

      fill_bma400_config_params(bma400ptr);



 }




//HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
//
//
//    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
//    HAL_Delay(3000);
//    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
//
//}

void bc95_init(){


    struct bc95_dev * bc95ptr = NULL;

    init_bc95_interface(bc95ptr,huart1);

    bc95_at_start_check(bc95ptr);

}

void init_bc95_interface(struct bc95_dev * bc95, UART_HandleTypeDef intfPointer){

    bc95->intf_ptr = intfPointer;
    bc95->write = uart_register_write;
    bc95->read = &uart_register_read;
//    bc95->read_it = uart_register_read_it;

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
