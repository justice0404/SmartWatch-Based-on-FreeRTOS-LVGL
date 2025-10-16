#include "TaskInit.h"
#include "main.h"
#include "Key.h"

/**
  * @brief  Key press check task
  * @param  argument: Not used
  * @retval None
  */
void KeyTask(void *argument)
{
	uint8_t keystr = 0;
	uint8_t IdleBreakstr = 0;
	
	while(1)
	{
		switch(KeyScan(0))
		{
			case 1:
				keystr = 1;
				osMessageQueuePut(Key_MessageQueue,&keystr,0,1);
				//传递信号量
				osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
				break;
			
			case 2:
				keystr = 2;
				osMessageQueuePut(Key_MessageQueue,&keystr,0,1);
				//传递信号量
				osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
				break;
		}
		
		osDelay(1);
	}
}

