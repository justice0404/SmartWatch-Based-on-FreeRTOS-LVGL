/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "PageManager.h"

/**************ÆÁÄ»×¢²á**************/
void deinit_scr_Calender(void);
Page_t Page_Calender  = {"Calender",setup_scr_Calender,deinit_scr_Calender,&guider_ui.Calender};


lv_calendar_date_t Calender_calendar_1_today;
lv_calendar_date_t Calender_calendar_1_highlihted_days[1];
void setup_scr_Calender(lv_ui *ui)
{
    //Write codes Calender
    ui->Calender = lv_obj_create(NULL);
    lv_obj_set_size(ui->Calender, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Calender, LV_SCROLLBAR_MODE_OFF);

    //Write style for Calender, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Calender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Calender_calendar_1
    ui->Calender_calendar_1 = lv_calendar_create(ui->Calender);
    Calender_calendar_1_today.year = 2025;
    Calender_calendar_1_today.month = 9;
    Calender_calendar_1_today.day = 30;
    lv_calendar_set_today_date(ui->Calender_calendar_1, Calender_calendar_1_today.year, Calender_calendar_1_today.month, Calender_calendar_1_today.day);
    lv_calendar_set_showed_date(ui->Calender_calendar_1, Calender_calendar_1_today.year, Calender_calendar_1_today.month);
    Calender_calendar_1_highlihted_days[0].year = 2025;
    Calender_calendar_1_highlihted_days[0].month = 10;
    Calender_calendar_1_highlihted_days[0].day = 1;
    lv_calendar_set_highlighted_dates(ui->Calender_calendar_1, Calender_calendar_1_highlihted_days, 1);
    lv_obj_t *Calender_calendar_1_header = lv_calendar_header_arrow_create(ui->Calender_calendar_1);
    lv_calendar_t *Calender_calendar_1 = (lv_calendar_t *)ui->Calender_calendar_1;
    lv_obj_add_event_cb(Calender_calendar_1->btnm, Calender_calendar_1_draw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(ui->Calender_calendar_1, Calender_calendar_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Calender_calendar_1, 0, 0);
    lv_obj_set_size(ui->Calender_calendar_1, 240, 280);

    //Write style state: LV_STATE_DEFAULT for &style_Calender_calendar_1_main_main_default
    static lv_style_t style_Calender_calendar_1_main_main_default;
    ui_init_style(&style_Calender_calendar_1_main_main_default);

    lv_style_set_border_width(&style_Calender_calendar_1_main_main_default, 1);
    lv_style_set_border_opa(&style_Calender_calendar_1_main_main_default, 255);
    lv_style_set_border_color(&style_Calender_calendar_1_main_main_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_Calender_calendar_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_opa(&style_Calender_calendar_1_main_main_default, 216);
    lv_style_set_bg_color(&style_Calender_calendar_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_Calender_calendar_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_Calender_calendar_1_main_main_default, 0);
    lv_style_set_radius(&style_Calender_calendar_1_main_main_default, 0);
    lv_obj_add_style(ui->Calender_calendar_1, &style_Calender_calendar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Calender_calendar_1_extra_header_main_default
    static lv_style_t style_Calender_calendar_1_extra_header_main_default;
    ui_init_style(&style_Calender_calendar_1_extra_header_main_default);

    lv_style_set_text_color(&style_Calender_calendar_1_extra_header_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_Calender_calendar_1_extra_header_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_Calender_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_opa(&style_Calender_calendar_1_extra_header_main_default, 215);
    lv_style_set_bg_color(&style_Calender_calendar_1_extra_header_main_default, lv_color_hex(0x252524));
    lv_style_set_bg_grad_dir(&style_Calender_calendar_1_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(Calender_calendar_1_header, &style_Calender_calendar_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Calender_calendar_1_main_items_default
    static lv_style_t style_Calender_calendar_1_main_items_default;
    ui_init_style(&style_Calender_calendar_1_main_items_default);

    lv_style_set_bg_opa(&style_Calender_calendar_1_main_items_default, 0);
    lv_style_set_border_width(&style_Calender_calendar_1_main_items_default, 1);
    lv_style_set_border_opa(&style_Calender_calendar_1_main_items_default, 255);
    lv_style_set_border_color(&style_Calender_calendar_1_main_items_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_Calender_calendar_1_main_items_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_Calender_calendar_1_main_items_default, lv_color_hex(0xA9A2A2));
    lv_style_set_text_font(&style_Calender_calendar_1_main_items_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_Calender_calendar_1_main_items_default, 255);
    lv_obj_add_style(lv_calendar_get_btnmatrix(ui->Calender_calendar_1), &style_Calender_calendar_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //The custom code of Calender.


    //Update current screen layout.
    lv_obj_update_layout(ui->Calender);

}

void deinit_scr_Calender(void)
{
	
}
