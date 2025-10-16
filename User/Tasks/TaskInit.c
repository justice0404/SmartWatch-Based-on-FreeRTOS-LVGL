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

lv_ui guider_ui;  //gui_guider.h�ж���

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
osSemaphoreId_t ui_sempr;  // �ź���ID
const osSemaphoreAttr_t ui_sempr_attributes = 
{
    .name = "ui_sempr",     // �ź������ƣ���ѡ��
    .attr_bits = 0,         // ����λ��ͨ��Ϊ0��
    .cb_mem = NULL,         // ���Զ�����ƿ��ڴ�
    .cb_size = 0            // �Զ�������ƿ�
};

//------------------------------------------------------------------------

//------------------------------------Message Queues--------------------------------
//���ݰ����ļ�ֵ
osMessageQueueId_t Key_MessageQueue;
//��ʱ���ã��ź����÷�����ʾ�Ƿ���Ҫ����Home
osMessageQueueId_t HomeUpdata_MessageQueue;
//�Ƿ���Ҫ�洢
osMessageQueueId_t DataSave_MessageQueue;


//�ź����÷�����־��Ļ���У���Ҫ�䰵
osMessageQueueId_t Idle_MessageQueue;
//�ź����÷�����־��Ļ�����У���Ҫ�����û��趨����
osMessageQueueId_t IdleBreak_MessageQueue;
//�ź����÷�����־��Ҫ����˯��״̬
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
	
	/*********************************** ��Ӷ�ʱ�� ***********************************/
	
	IdleTimerHandle = osTimerNew(IdleTimerCallback,osTimerPeriodic,NULL,NULL);
	osTimerStart(IdleTimerHandle,100); //����100ms�ļ�ʱ
	
	
	
	
	/*********************************** �����Ϣ���� ***********************************/
	
	Key_MessageQueue = osMessageQueueNew(1,1,NULL);
	HomeUpdata_MessageQueue = osMessageQueueNew(1,1,NULL);
	DataSave_MessageQueue = osMessageQueueNew(2,1,NULL);
	
	Idle_MessageQueue = osMessageQueueNew(1,1,NULL);
	IdleBreak_MessageQueue = osMessageQueueNew(1,1,NULL);
	Stop_MessageQueue = osMessageQueueNew(1,1,NULL);
	
	
	
	/*********************************** ����ź��� ***********************************/
	
	ui_sempr = osSemaphoreNew(1,0,&ui_sempr_attributes);
	
	
	
	/*********************************** ����߳� ***********************************/
	
	//Ӳ����ʼ����������ɾ
	HardwareInitTaskHandle = osThreadNew(HardwareInitTask,NULL,&HardwareInitTask_attributes);
	//LVGL������ui()�����
	LvHandlerTaskHandler = osThreadNew(LvHandlerTask,NULL,&LvHandlerTask_attributes);
	//����ι���������
	WDOGFeedTaskHandle = osThreadNew(WDOGFeedTask,NULL,&WDOGFeedTask_attributes);
	
	//�����������
	KeyTaskHandle = osThreadNew(KeyTask,NULL,&KeyTask_attributes);
	//��Ļ��������
	ScrRenewTaskHandle = osThreadNew(ScrRenewTask,NULL,&ScrRenewTask_attributes);
	//���������ݸ�������
	SensorDataTaskHandle = osThreadNew(SensorDataUpdateTask,NULL,&SensorDataTask_attributes);
	//���ʲ�����������
	HRDataTaskHandle = osThreadNew(HRDataUpdateTask,NULL,&HRDataTask_attributes);
	//MPU6050��������
	MPUCheckTaskHandle = osThreadNew(MPUCheckTask,NULL,&MPUCheckTask_attributes);
	
	//����Ϩ�������߳�
	IdleEnterTaskHandle = osThreadNew(IdleEnterTask,NULL,&IdleEnterTask_attributes);
	//����˯��ģʽ�����߳�
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
	//�ṩLVGL����������
	lv_tick_inc(1);
	//���StopWatch�����ʱ����Դ
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
			//�����ź���
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
	//һ�����壬���ڴ����ź���������Idle�̣߳���LVGL�̹߳�����������
	uint8_t IdleBreakstr = 0;
	while(1)
	{
		if(lv_disp_get_inactive_time(NULL)<1000)
		{
			//�����ź���
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
