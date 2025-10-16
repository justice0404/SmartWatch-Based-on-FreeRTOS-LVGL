#ifndef PAGE_STACK_H
#define PAGE_STACK_H

#include "gui_guider.h"

//ҳ��ջ���
#define MAX_DEPTH 6

//ҳ��ṹ��
typedef struct{
	const char * name;
	void (*init)(lv_ui *ui);
	void (*deinit)(void);
	lv_obj_t **page_obj;
}Page_t;

//ҳ��ջ�ṹ��
//Topָ��ָ����һ�����е�λ��
typedef struct{
	Page_t* page[MAX_DEPTH];
	uint8_t top;
}PageStack_t;

extern PageStack_t PageStack;

Page_t* Page_Get_NowPage(void);
void Page_Back(lv_ui *ui);
void Page_Back_Bottom(lv_ui *ui);
void Page_Load(lv_ui *ui,Page_t *newPage);
void Pages_init(lv_ui *ui);

/**************��Ļ����**************/
extern Page_t Page_Home;	
extern Page_t Page_PowerOff;

extern Page_t Page_Menu;

extern Page_t Page_Calender;
extern Page_t Page_Calculater;
extern Page_t Page_Stopwatch;
extern Page_t Page_Heart;
extern Page_t Page_Environment;
extern Page_t Page_Compass;
extern Page_t Page_Game;
extern Page_t Page_Setting;

extern Page_t Page_SetLightTime;
extern Page_t Page_SetOffTime;
extern Page_t Page_SetDateTime;
extern Page_t Page_SetDate;
extern Page_t Page_SetTime;

#endif

