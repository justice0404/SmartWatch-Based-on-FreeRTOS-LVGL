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
//�ź����÷�����־��Ļ���У���Ҫ�䰵
extern osMessageQueueId_t Idle_MessageQueue;
//�ź����÷�����־��Ļ�����У���Ҫ�����û��趨����
extern osMessageQueueId_t IdleBreak_MessageQueue;
//�ź����÷�����־��Ҫ����˯��״̬
extern osMessageQueueId_t Stop_MessageQueue;

extern osSemaphoreId_t ui_sempr;

void User_Tasks_Init(void);
void TaskTickHook(void);

#ifdef __cplusplus
}
#endif

#endif

