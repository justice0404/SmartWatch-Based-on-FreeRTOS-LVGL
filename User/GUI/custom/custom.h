/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void custom_init(lv_ui *ui);
	
//LightTime&OffTime
extern const uint8_t ui_LTimeOptions[6];
extern const uint8_t ui_OTimeOptions[6];
extern uint8_t ui_LightTimeVale;
extern uint8_t ui_OffTimeVale;
extern uint8_t ui_LightTimeSelected;
extern uint8_t ui_OffTimeSelected;

//Home
extern uint8_t ui_Minute;
extern uint8_t ui_Hour;
extern uint8_t ui_Day;
extern uint8_t ui_Month;
extern uint8_t ui_WeedDayValue;
extern uint8_t ui_LightSliderValue;
//StopWatch
extern lv_timer_t * ui_StopWatchTimer;
extern uint8_t ui_StopWatch_Flag;
extern uint8_t ui_StopWatch_Min;
extern uint8_t ui_StopWatch_Sec;
extern uint8_t ui_StopWatch_10Ms;
extern uint8_t ui_StopWatch_Ms;

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
