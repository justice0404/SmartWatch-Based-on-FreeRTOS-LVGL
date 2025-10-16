#ifndef __TASKSINIT_H__
#define __TASKSINIT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "cmsis_os.h"
	

#define SCRRENEW_DEPTH	5

	
extern osMessageQueueId_t Key_MessageQueue;
extern osMessageQueueId_t HomeUpdata_MessageQueue;
extern osMessageQueueId_t DataSave_MessageQueue;
//信号量用法，标志屏幕空闲，需要变暗
extern osMessageQueueId_t Idle_MessageQueue;
//信号量用法，标志屏幕不空闲，需要按照用户设定亮度
extern osMessageQueueId_t IdleBreak_MessageQueue;
//信号量用法，标志需要进入睡眠状态
extern osMessageQueueId_t Stop_MessageQueue;

extern osSemaphoreId_t ui_sempr;

void User_Tasks_Init(void);
void TaskTickHook(void);

#ifdef __cplusplus
}
#endif

#endif

