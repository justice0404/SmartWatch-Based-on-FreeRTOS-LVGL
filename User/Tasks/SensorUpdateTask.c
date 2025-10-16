//System
#include "main.h"

//Task
#include "TaskInit.h"
#include "ScrRenewTask.h"
#include "SensorUpdateTask.h"

//Sensor
#include "AHT21.h"
#include "LSM303.h"
#include "SPL06_001.h"
#include "em70x8.h"
#include "HrAlgorythm.h"

//MidFuc
#include "HWDataAccess.h"
#include "PageManager.h"

uint32_t user_HR_timecount = 0;


/**
  * @brief  MPU6050 Check the state
  * @param  argument: Not used
  * @retval None
  */
void MPUCheckTask(void *argument)
{
	while(1)
	{
		if(HWInterface.IMU.wrist_is_enabled)
		{
			HWInterface.IMU.wrist_state = WRIST_UP;
		}
		else
		{
			if(WRIST_UP == HWInterface.IMU.wrist_state)
			{
				//手腕垂下，并且处在特定界面则关机
				HWInterface.IMU.wrist_state = WRIST_DOWN;
				if( Page_Get_NowPage()->page_obj == &guider_ui.Home ||
						Page_Get_NowPage()->page_obj == &guider_ui.Menu ||
						Page_Get_NowPage()->page_obj == &guider_ui.Setting )
					{
						uint8_t Stopstr;
						osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);//sleep
					}
				
				HWInterface.IMU.wrist_state = WRIST_DOWN;
			}
		}
		osDelay(300);
	}
}	

/**
  * @brief  HR data renew task
  * @param  argument: Not used
  * @retval None
  */
void HRDataUpdateTask(void *argument)
{
	uint16_t dat = 0;
	uint8_t hr_temp = 0;
	uint8_t IdleBreakstr = 0;
	while(1)
	{
		if(Page_Get_NowPage()->page_obj == &guider_ui.Heart)
		{
			//传递信号量
			 osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
			EM7028_hrs_Enable();
			if(!HWInterface.HR_meter.ConnectionError)
			{
				vTaskSuspendAll();
				hr_temp = HR_Calculate(EM7028_Get_HRS1(),user_HR_timecount);
				xTaskResumeAll();
				if(HWInterface.HR_meter.HrRate != hr_temp && hr_temp>50 && hr_temp<120)
				{
					HWInterface.HR_meter.HrRate = hr_temp;
				}
			}
		}
		osDelay(50);
	}
}

/**
  * @brief  Sensor data update task
  * @param  argument: Not used
  * @retval None
  */
 void SensorDataUpdateTask(void *argument)
 {
	 //传递信号量
	uint8_t IdleBreakstr = 0;
	 while(1)
	 {
		 //Home界面
		 uint8_t HomeUpdateStr;
		 if(osMessageQueueGet(HomeUpdata_MessageQueue,&HomeUpdateStr,NULL,0) == osOK)
		 {
			 //Power
			 HWInterface.Power.power_remain = HWInterface.Power.BatCalculate();
			 if(HWInterface.Power.power_remain>0  &&  HWInterface.Power.power_remain<=100)
			 {
			 }
			 else
			 {
				 HWInterface.Power.power_remain = 0;
			 }
			 
			 //Temp & Humi
			 if(!(HWInterface.AHT21.ConnectionError))
			 {
				 //获取传感器数据
				 float humi,temp;
				 HWInterface.AHT21.GetHumiTemp(&humi,&temp);
				 //检查数据
				 if((temp>-10 && temp<50) && (humi>0 && humi<100))
				 {
					 HWInterface.AHT21.humidity = humi;
					 HWInterface.AHT21.temperature = temp;
				 }
			 }
			 
			 //Step
			 if(!(HWInterface.IMU.ConnectionError))
			 {
				 HWInterface.IMU.Steps = HWInterface.IMU.GetSteps();
			 }
			 //还差一个DateSave的部分
		 }
		 
		 //Env温湿度界面
		 else if(Page_Get_NowPage()->page_obj == &guider_ui.Environment)
		 {
			 //传递信号量
			 osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
			 if(!HWInterface.AHT21.ConnectionError)
			 {
				 //获取传感器数据
				 float humi,temp;
				 HWInterface.AHT21.GetHumiTemp(&humi,&temp);
				 //检查数据
				 if((temp>-10 && temp<50) && (humi>0 && humi<100))
				 {
					 HWInterface.AHT21.humidity = humi;
					 HWInterface.AHT21.temperature = temp;
				 }
			 }
		 }
		 
		 //Compass指南针界面
		 else if(Page_Get_NowPage()->page_obj == &guider_ui.Compass)
		 {
			 //传递信号量
			 osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
			 
			 //LSM303指南针数据更新
			 LSM303DLH_Wakeup();
			 if(!HWInterface.Ecompass.ConnectionError)
			 {
				 //测量
				int16_t Xa,Ya,Za,Xm,Ym,Zm;
				LSM303_ReadAcceleration(&Xa,&Ya,&Za);
				LSM303_ReadMagnetic(&Xm,&Ym,&Zm);
				float temp = Azimuth_Calculate(Xa,Ya,Za,Xm,Ym,Zm)+0;//0 offset
				if(temp<0)
				{temp+=360;}
				//check
				if(temp>=0 && temp<=360)
				{
					HWInterface.Ecompass.direction = (uint16_t)temp;
				}
			 }
			 
			 //SPL06_001海拔数据更新
			 if(!HWInterface.Barometer.ConnectionError)
			 {
				 float alti = Altitude_Calculate();
				 HWInterface.Barometer.altitude = (int16_t)alti;
			 }
		 }
		 osDelay(500);
	 }
 }
