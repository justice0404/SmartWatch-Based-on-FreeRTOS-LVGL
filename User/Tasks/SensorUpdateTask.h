#ifndef __SENSORUPDATETASK_H__
#define __SENSORUPDATETASK_H__

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t user_HR_timecount;
	
void MPUCheckTask(void *argument);
void HRDataUpdateTask(void *argument);
void SensorDataUpdateTask(void *argument);

#ifdef __cplusplus
}
#endif

#endif

