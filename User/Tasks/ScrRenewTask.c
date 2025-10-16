#include "TaskInit.h"
#include "ScrRenewTask.h"
#include "main.h"
#include "lvgl.h"

//sensor
#include "LSM303.h"
#include "em70x8.h"

extern osMessageQueueId_t Key_MessageQueue;

/**
  * @brief  Screen renew task
  * @param  argument: Not used
  * @retval None
  */
void ScrRenewTask(void *argument)
{
	uint8_t keystr = 0;
	while(1)
	{
		if(osMessageQueueGet(Key_MessageQueue,&keystr,NULL,0) == osOK)
		{
			//Key1按下
			if(keystr == 1)
			{
				Page_Back(&guider_ui);
			}
			
			//Key2按下
			else if(keystr == 2)
			{
				Page_Back_Bottom(&guider_ui);
			}
		}
		osDelay(10);
	}
}



