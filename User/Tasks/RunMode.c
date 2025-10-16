#include "main.h"
#include "stm32f4xx_it.h"

//Task
#include "TaskInit.h"

//LVGL
#include "gui_guider.h"
#include "custom.h"

//BSP
#include "LCD.h"
#include "CST816.h"
#include "MPU6050.h"
#include "Key.h"
#include "WDOG.h"
#include "Power.h"

//MidFuc
#include "HWDataAccess.h"

uint16_t IdleTimerCount = 0;

/**
	* @brief  Enter Idle state
  * @param  argument: Not used
  * @retval None
  */
void IdleEnterTask(void *argument)	
{
	uint8_t Idlestr = 0;
	uint8_t IdleBreakstr = 0;
	while(1)
	{
		//空闲时间，屏幕变暗
		if(osMessageQueueGet(Idle_MessageQueue,&Idlestr,NULL,1) == osOK)
		{
			LCD_Set_Light(5);
		}
		
		//打破空闲，屏幕按照用户设定
		if(osMessageQueueGet(IdleBreak_MessageQueue,&IdleBreakstr,NULL,1) == osOK)
		{
			IdleTimerCount = 0;
			LCD_Set_Light(ui_LightSliderValue);
		}
		osDelay(10);
	}
}


/**
  * @brief  enter the stop mode and resume
  * @param  argument: Not used
  * @retval None
  */
void StopEnterTask(void *argument)
{
	uint8_t Stopstr;
	uint8_t HomeUpdataStr;
	uint8_t Wrist_Flag = 0;
	while(1)
	{
		if(osMessageQueueGet(Stop_MessageQueue,&Stopstr,NULL,0) == osOK)
		{
			/*************************** 睡眠前预处理 ***************************/
			sleep:
			IdleTimerCount = 0;
			
			//Usart
			HAL_UART_MspDeInit(&huart1);
			//LCD
			LCD_RES_Clr();
			LCD_Close_Light();
			//CST816
			CST816_Sleep();
			
			/***********************************************************************************/

			/****************************** 进入睡眠 *****************************/

			vTaskSuspendAll();
			//关闭看门狗
			WDOG_Disnable();
			//关闭系统时钟
			CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Msk);
			//进入睡眠模式
			HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON,PWR_STOPENTRY_WFI);
			
			/********************* 正在睡眠 *********************/
			
			/***********************************************************************************/

			/****************************** 唤醒预操作 *****************************/

			//resume run mode and reset the sysclk
			SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
			HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
			SystemClock_Config();
			WDOG_Feed();
			xTaskResumeAll();
			
			/***********************************************************************************/

			/****************************** 判断唤醒来源 *****************************/

			//抬腕亮屏的判断
			if(HWInterface.IMU.wrist_is_enabled)
			{
				uint8_t hor;
				hor = MPU_isHorizontal();
				if(hor && HWInterface.IMU.wrist_state == WRIST_DOWN)
				{
					HWInterface.IMU.wrist_state = WRIST_UP;
					Wrist_Flag = 1;
					//resume, go on
				}
				else if(!hor && HWInterface.IMU.wrist_state == WRIST_UP)
				{
					HWInterface.IMU.wrist_state = WRIST_DOWN;
					IdleTimerCount  = 0;
					goto sleep;
				}
			}
			
			//按键按下的判断,或充电中断唤醒，或抬起手腕标志
			if(!KEY1 || KEY2 || HardInt_Charg_flag || Wrist_Flag)
			{
				Wrist_Flag = 0;//恢复
			}
			else //都不是，重新进入睡眠
			{
				IdleTimerCount = 0;
				goto sleep;
			}
			
			/***********************************************************************************/

			/****************************** 彻底唤醒 *****************************/
			//Usart
			HAL_UART_MspInit(&huart1);
			//LCD
			LCD_Init();
			LCD_Set_Light(ui_LightSliderValue);
			//CST816
			CST816_Wakeup();
			//check if is Charging
			if(ChargeCheck())
			{HardInt_Charg_flag = 1;}
			//send the Home Updata message
			osMessageQueuePut(HomeUpdata_MessageQueue, &HomeUpdataStr, 0, 1);
			/**************************************************************************************/
			
		}
		osDelay(100);
	}
}

void IdleTimerCallback(void *argument)
{
	IdleTimerCount += 1;
	if(IdleTimerCount == (ui_LightTimeVale * 10))
	{
		//载体
		uint8_t Idlestr = 0;
		//传递信号量
		osMessageQueuePut(Idle_MessageQueue,&Idlestr,0,1);
	}
	if(IdleTimerCount == (ui_OffTimeVale * 10))
	{
		//载体
		uint8_t Stopstr = 1;
		//更新空闲时间计数
		IdleTimerCount = 0;
		//传递信号量
		osMessageQueuePut(Stop_MessageQueue,&Stopstr,0,1);
		
	}
}

