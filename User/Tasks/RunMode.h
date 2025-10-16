#ifndef __RUNMODETASKS_H__
#define __RUNMODETASKS_H__

#ifdef __cplusplus
extern "C" {
#endif


void IdleEnterTask(void *argument);
void StopEnterTask(void *argument);
void IdleTimerCallback(void *argument);

extern uint16_t IdleTimerCount;

#ifdef __cplusplus
}
#endif

#endif