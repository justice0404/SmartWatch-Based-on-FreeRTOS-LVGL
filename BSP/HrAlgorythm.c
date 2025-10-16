#include "HrAlgorythm.h"
#include "string.h"

Queue datas;
Queue times;
Queue HR_List;

void HR_AlgoInit(void)
{
	initQueue(&datas);
	initQueue(&times);
	initQueue(&HR_List);
}

//平均滤波器
uint8_t Hr_Ave_Filter(uint32_t * HrList,uint8_t length)
{
	uint32_t ave;
	uint8_t i;
	for(i = 0;i<length;i++)
	{
		ave += HrList[i];
	}
	ave /= length;
	return (uint8_t)ave;
}

uint8_t HR_Calculate(uint16_t present_dat,uint32_t present_time)
{
	//存储两个峰值点的时间
	static uint16_t peaks_time[] = {0,0};
	//存储心率
	static uint8_t HR = 0;
	
	if(isQueueFull(&datas))
	{dequeue(&datas);}
	if(isQueueFull(&times))
	{dequeue(&times);}
	if(isQueueFull(&HR_List))
	{dequeue(&HR_List);}

	enqueue(&datas,present_dat);
	enqueue(&times,present_time);

	if((datas.data[3]>=datas.data[2]) && (datas.data[3]>=datas.data[1]) && (datas.data[3]>datas.data[0]) 
		&& (datas.data[3]>=datas.data[4]) && (datas.data[3]>=datas.data[5]) && (datas.data[3]>datas.data[6]))
	{
			if((times.data[3]-peaks_time[0])>425)
			{
					peaks_time[1] = peaks_time[0];
					peaks_time[0] = times.data[3];
					enqueue(&HR_List,60000/(peaks_time[0]-peaks_time[1]));
					if(HR_List.data[6]!=0)
					{HR = Hr_Ave_Filter(HR_List.data,7);}
			}
	}
	return HR;
}
