//system
#include "TaskInit.h"
#include "stdio.h"
#include "WDOG.h"

//LVGL
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

//Tasks
#include "HardwareInitTask.h"
#include "KeyTask.h"
#include "ScrRenewTask.h"
#include "SensorUpdateTask.h"
#include "RunMode.h"

lv_ui guider_ui;  //gui_guider.h中定义

osTimerId_t IdleTimerHandle;


//------------------------------------------------------------------------
//Hardware Initalization
osThreadId_t HardwareInitTaskHandle;
const osThreadAttr_t HardwareInitTask_attributes =
{
	.name = "HardwareInitTask",
	.stack_size = 128 * 10,
	.priority = (osPriority_t) osPriorityHigh3,
};

//LVGL Handler Task
osThreadId_t LvHandlerTaskHandler;
const osThreadAttr_t LvHandlerTask_attributes = 
{
	.name = "LvHandlerTask",
	.stack_size = 128 * 24,
	.priority = (osPriority_t) osPriorityLow,
};

//WDOG Feed Task
osThreadId_t WDOGFeedTaskHandle;
const osThreadAttr_t WDOGFeedTask_attributes = 
{
	.name = "WDOGFeedTask",
	.stack_size = 128*1,
	.priority = (osPriority_t)osPriorityHigh2,
};

//Key Task
osThreadId_t KeyTaskHandle;
const osThreadAttr_t KeyTask_attributes = {
  .name = "KeyTask",
  .stack_size = 128 * 1,
  .priority = (osPriority_t) osPriorityNormal,
};

//ScrRenew Task
osThreadId_t ScrRenewTaskHandle;
const osThreadAttr_t ScrRenewTask_attributes = {
  .name = "ScrRenewTask",
  .stack_size = 128 * 10,
  .priority = (osPriority_t) osPriorityLow1,
};

//SensorDataRenew task
osThreadId_t SensorDataTaskHandle;
const osThreadAttr_t SensorDataTask_attributes = {
  .name = "SensorDataTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow1,
};

//HRDataRenew task
osThreadId_t HRDataTaskHandle;
const osThreadAttr_t HRDataTask_attributes = {
  .name = "HRDataTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow1,
};

//MPUCheckTask
osThreadId_t MPUCheckTaskHandle;
const osThreadAttr_t MPUCheckTask_attributes = {
  .name = "MPUCheckTask",
  .stack_size = 128 * 3,
  .priority = (osPriority_t) osPriorityLow2,
};

//Idle Enter Task
osThreadId_t IdleEnterTaskHandle;
const osThreadAttr_t IdleEnterTask_attributes = {
  .name = "IdleEnterTask",
  .stack_size = 128 * 1,
  .priority = (osPriority_t) osPriorityHigh,
};

//Stop Enter Task
osThreadId_t StopEnterTaskHandle;
const osThreadAttr_t StopEnterTask_attributes = {
  .name = "StopEnterTask",
  .stack_size = 128 * 16,
  .priority = (osPriority_t) osPriorityHigh1,
};

//------------------------------------------------------------------------
osSemaphoreId_t ui_sempr;  // 信号量ID
const osSemaphoreAttr_t ui_sempr_attributes = 
{
    .name = "ui_sempr",     // 信号量名称（可选）
    .attr_bits = 0,         // 属性位（通常为0）
    .cb_mem = NULL,         // 无自定义控制块内存
    .cb_size = 0            // 自动分配控制块
};

//------------------------------------------------------------------------

//------------------------------------Message Queues--------------------------------
//传递按键的键值
osMessageQueueId_t Key_MessageQueue;
//暂时无用，信号量用法，显示是否需要更新Home
osMessageQueueId_t HomeUpdata_MessageQueue;
//是否需要存储
osMessageQueueId_t DataSave_MessageQueue;


//信号量用法，标志屏幕空闲，需要变暗
osMessageQueueId_t Idle_MessageQueue;
//信号量用法，标志屏幕不空闲，需要按照用户设定亮度
osMessageQueueId_t IdleBreak_MessageQueue;
//信号量用法，标志需要进入睡眠状态
osMessageQueueId_t Stop_MessageQueue;


void LvHandlerTask(void *argument);
void WDOGFeedTask(void *argument);

//------------------------------------------------------------------------
/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void User_Tasks_Init(void)
{
	
	/*********************************** 添加定时器 ***********************************/
	
	IdleTimerHandle = osTimerNew(IdleTimerCallback,osTimerPeriodic,NULL,NULL);
	osTimerStart(IdleTimerHandle,100); //开启100ms的计时
	
	
	
	
	/*********************************** 添加消息队列 ***********************************/
	
	Key_MessageQueue = osMessageQueueNew(1,1,NULL);
	HomeUpdata_MessageQueue = osMessageQueueNew(1,1,NULL);
	DataSave_MessageQueue = osMessageQueueNew(2,1,NULL);
	
	Idle_MessageQueue = osMessageQueueNew(1,1,NULL);
	IdleBreak_MessageQueue = osMessageQueueNew(1,1,NULL);
	Stop_MessageQueue = osMessageQueueNew(1,1,NULL);
	
	
	
	/*********************************** 添加信号量 ***********************************/
	
	ui_sempr = osSemaphoreNew(1,0,&ui_sempr_attributes);
	
	
	
	/*********************************** 添加线程 ***********************************/
	
	//硬件初始化，用完自删
	HardwareInitTaskHandle = osThreadNew(HardwareInitTask,NULL,&HardwareInitTask_attributes);
	//LVGL主函数ui()的入口
	LvHandlerTaskHandler = osThreadNew(LvHandlerTask,NULL,&LvHandlerTask_attributes);
	//定期喂狗函数入口
	WDOGFeedTaskHandle = osThreadNew(WDOGFeedTask,NULL,&WDOGFeedTask_attributes);
	
	//按键侦测任务
	KeyTaskHandle = osThreadNew(KeyTask,NULL,&KeyTask_attributes);
	//屏幕更新任务
	ScrRenewTaskHandle = osThreadNew(ScrRenewTask,NULL,&ScrRenewTask_attributes);
	//传感器数据更新任务
	SensorDataTaskHandle = osThreadNew(SensorDataUpdateTask,NULL,&SensorDataTask_attributes);
	//心率测量更新任务
	HRDataTaskHandle = osThreadNew(HRDataUpdateTask,NULL,&HRDataTask_attributes);
	//MPU6050更新任务
	MPUCheckTaskHandle = osThreadNew(MPUCheckTask,NULL,&MPUCheckTask_attributes);
	
	//空闲熄屏控制线程
	IdleEnterTaskHandle = osThreadNew(IdleEnterTask,NULL,&IdleEnterTask_attributes);
	//进入睡眠模式控制线程
	StopEnterTaskHandle = osThreadNew(StopEnterTask,NULL,&StopEnterTask_attributes);
	
	uint8_t HomeUpdateStr;
	osMessageQueuePut(HomeUpdata_MessageQueue,&HomeUpdateStr,0,1);
}

/**
  * @brief  FreeRTOS Tick Hook, to increase the LVGL tick
  * @param  None
  * @retval None
  */
void TaskTickHook(void)
{
	//提供LVGL的心跳函数
	lv_tick_inc(1);
	//秒表StopWatch界面的时间来源
	if(ui_StopWatch_Flag)
	{
		ui_StopWatch_Ms += 1;
		if(ui_StopWatch_Ms >= 10)
		{
			ui_StopWatch_Ms = 0;
			ui_StopWatch_10Ms += 1;
		}
		
		if(ui_StopWatch_10Ms >= 100)
		{
			ui_StopWatch_10Ms = 0;
			ui_StopWatch_Sec += 1;
			//传递信号量
			uint8_t IdleBreakstr = 0;
			osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
			
		}
		if(ui_StopWatch_Sec >= 60)
		{
			ui_StopWatch_Sec = 0;
			ui_StopWatch_Min += 1;
		}
		if(ui_StopWatch_Min >= 99)
		{
			ui_StopWatch_Min = 0;
		}
	}
	user_HR_timecount += 1;
}

/**
  * @brief  LVGL Handler task, to run the lvgl
  * @param  argument: Not used
  * @retval None
  */
void LvHandlerTask(void *argument)
{
	//一个载体，用于传递信号量，告诉Idle线程，有LVGL线程工作，不空闲
	uint8_t IdleBreakstr = 0;
	while(1)
	{
		if(lv_disp_get_inactive_time(NULL)<1000)
		{
			//传递信号量
			osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
		}
		lv_task_handler();
		osDelay(1);
	}
}

/**
  * @brief  Watch Dog Feed task
  * @param  argument: Not used
  * @retval None
  */
void WDOGFeedTask(void *argument)
{
	//owdg
	WDOG_Port_Init();
	while(1)
	{
		WDOG_Feed();
		WDOG_Enable();
		osDelay(100);
	}
}
