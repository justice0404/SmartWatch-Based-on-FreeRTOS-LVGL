//System
#include "main.h"
#include "delay.h"
#include "stm32f4xx_it.h"

//USER
#include "TaskInit.h"
#include "HWDataAccess.h"

//BSP
#include "LCD.h"
#include "key.h"
#include "CST816.h"
#include "Power.h"

//UI
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"

extern uint8_t RXbuf[50];

void HardwareInitTask(void *argument)
{
	while(1)
	{
		vTaskSuspendAll();
		
		//RTC Wake
		if(HAL_RTCEx_SetWakeUpTimer_IT(&hrtc,2000,RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
		{
			Error_Handler();
		}
		
		//USART Start
		HAL_UART_Receive_DMA(&huart1,(uint8_t*)HardInt_receive_str,25);
		__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
		
		//PWM Start
		HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
		
		//System delay Start
		delay_init();
		
		//Power Start
		Power_Init();
		
		//Key
		Key_Port_Init();
		
		
		//Sensors
		uint8_t cnt = 3;
		//温湿度AHT21
		while(cnt && HWInterface.AHT21.ConnectionError)
		{
			cnt--;
			//计数次数cnt之后，若初始化完成，则返回0
			HWInterface.AHT21.ConnectionError = HWInterface.AHT21.Init();
		}
		//指南针LSM303
		cnt = 3;
		while(cnt && HWInterface.Ecompass.ConnectionError)
		{
			cnt--;
			HWInterface.Ecompass.ConnectionError = HWInterface.Ecompass.Init();
		}
		//气压计SPL06_001
		cnt = 3;
		while(cnt && HWInterface.Barometer.ConnectionError)
		{
			cnt--;
			HWInterface.Barometer.ConnectionError = HWInterface.Barometer.Init();
		}
		//MPU6050
		cnt = 3;
		while(cnt && HWInterface.IMU.ConnectionError)
		{
			cnt--;
			HWInterface.IMU.ConnectionError = HWInterface.IMU.Init();
		}
		//心率EM70X8
		cnt = 3;
		while(cnt && HWInterface.HR_meter.ConnectionError)
		{
			cnt--;
			HWInterface.HR_meter.ConnectionError = HWInterface.HR_meter.Init();
		}
		if(!HWInterface.HR_meter.ConnectionError)
			HWInterface.HR_meter.Sleep();
		
		//Touch
		CST816_GPIO_Init();
		CST816_RESET();
		
		//LCD
		LCD_Init();
		LCD_Fill(0,0, LCD_W, LCD_H, BLACK);
		delay_ms(10);
		LCD_Set_Light(50);
		LCD_ShowString(72,LCD_H/2,(uint8_t*)"Welcome!", WHITE, BLACK, 24, 0);//12*6,16*8,24*12,32*16
		delay_ms(1500);
		LCD_Fill(0, LCD_H/2-24, LCD_W, LCD_H/2+49, BLACK);
		
		//LVGL
		lv_init();
		lv_port_disp_init();
		lv_port_indev_init();
		
		//GUI Guider的函数入口
		setup_ui(&guider_ui);
		events_init(&guider_ui);
		//释放信号量
		osSemaphoreRelease(ui_sempr);
		xTaskResumeAll();
		vTaskDelete(NULL);
	
		vTaskDelay(pdMS_TO_TICKS(50));
	}
}
