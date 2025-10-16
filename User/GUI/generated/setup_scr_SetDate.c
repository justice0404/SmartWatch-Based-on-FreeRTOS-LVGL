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
#include "HWDataAccess.h"

/**************屏幕注册**************/
void deinit_scr_SetDate(void);
Page_t Page_SetDate  = {"SetDate",setup_scr_SetDate,deinit_scr_SetDate,&guider_ui.SetDate};

/**************变量管理**************/
const char  yearoptions[] = "2022\n2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030\n2031\n2032\n2033\n2034\n2035";
const char  monthoptions[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";
const char  day31options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31";
const char  day30options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30";
const char  day29options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29";
const char  day28options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28";


void setup_scr_SetDate(lv_ui *ui)
{
	HW_DateTimeTypeDef datetime;
	HWInterface.RealTimeClock.GetTimeDate(&datetime);
	
    //Write codes SetDate
    ui->SetDate = lv_obj_create(NULL);
    lv_obj_set_size(ui->SetDate, 240, 280);
    lv_obj_set_scrollbar_mode(ui->SetDate, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetDate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDate, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDate_img_SetDateConfirm
    ui->SetDate_img_SetDateConfirm = lv_img_create(ui->SetDate);
    lv_obj_add_flag(ui->SetDate_img_SetDateConfirm, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetDate_img_SetDateConfirm, &_confirm_alpha_30x30);
    lv_img_set_pivot(ui->SetDate_img_SetDateConfirm, 50,50);
    lv_img_set_angle(ui->SetDate_img_SetDateConfirm, 0);
    lv_obj_set_pos(ui->SetDate_img_SetDateConfirm, 105, 240);
    lv_obj_set_size(ui->SetDate_img_SetDateConfirm, 30, 30);

    //Write style for SetDate_img_SetDateConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetDate_img_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetDate_img_SetDateConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDate_img_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetDate_img_SetDateConfirm, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDate_roller_SetDateYear
    ui->SetDate_roller_SetDateYear = lv_roller_create(ui->SetDate);
    lv_roller_set_options(ui->SetDate_roller_SetDateYear,yearoptions, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetDate_roller_SetDateYear,datetime.Year-22,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetDate_roller_SetDateYear, 15, 75);
    lv_obj_set_width(ui->SetDate_roller_SetDateYear, 90);

    //Write style for SetDate_roller_SetDateYear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetDate_roller_SetDateYear, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateYear, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateYear, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateYear, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateYear, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateYear, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateYear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDate_roller_SetDateYear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetDate_roller_SetDateYear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDate_roller_SetDateYear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDate_roller_SetDateYear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDate_roller_SetDateYear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetDate_roller_SetDateYear, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateYear, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateYear, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateYear, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateYear, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateYear, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateYear, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetDate_roller_SetDateYear, 3);
    //Write codes SetDate_cont_SetDateConfirm
    ui->SetDate_cont_SetDateConfirm = lv_obj_create(ui->SetDate);
    lv_obj_set_pos(ui->SetDate_cont_SetDateConfirm, 0, 240);
    lv_obj_set_size(ui->SetDate_cont_SetDateConfirm, 240, 40);
    lv_obj_set_scrollbar_mode(ui->SetDate_cont_SetDateConfirm, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetDate_cont_SetDateConfirm, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetDate_cont_SetDateConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDate_cont_SetDateConfirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetDate_cont_SetDateConfirm, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetDate_cont_SetDateConfirm, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetDate_cont_SetDateConfirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDate_cont_SetDateConfirm, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_cont_SetDateConfirm, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_cont_SetDateConfirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDate_cont_SetDateConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDate_roller_SetDateMonth
    ui->SetDate_roller_SetDateMonth = lv_roller_create(ui->SetDate);
    lv_roller_set_options(ui->SetDate_roller_SetDateMonth, monthoptions, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetDate_roller_SetDateMonth,datetime.Month-1,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetDate_roller_SetDateMonth, 120, 75);
    lv_obj_set_width(ui->SetDate_roller_SetDateMonth, 45);

    //Write style for SetDate_roller_SetDateMonth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetDate_roller_SetDateMonth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateMonth, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateMonth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateMonth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateMonth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateMonth, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateMonth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDate_roller_SetDateMonth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetDate_roller_SetDateMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDate_roller_SetDateMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDate_roller_SetDateMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDate_roller_SetDateMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetDate_roller_SetDateMonth, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateMonth, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateMonth, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateMonth, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateMonth, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateMonth, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateMonth, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetDate_roller_SetDateMonth, 3);
    //Write codes SetDate_roller_SetDateDay
    ui->SetDate_roller_SetDateDay = lv_roller_create(ui->SetDate);
    lv_roller_set_options(ui->SetDate_roller_SetDateDay, day31options, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetDate_roller_SetDateDay,datetime.Date-1,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetDate_roller_SetDateDay, 175, 75);
    lv_obj_set_width(ui->SetDate_roller_SetDateDay, 50);

    //Write style for SetDate_roller_SetDateDay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetDate_roller_SetDateDay, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateDay, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateDay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateDay, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateDay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateDay, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateDay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDate_roller_SetDateDay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetDate_roller_SetDateDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDate_roller_SetDateDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDate_roller_SetDateDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDate_roller_SetDateDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetDate_roller_SetDateDay, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDate_roller_SetDateDay, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDate_roller_SetDateDay, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDate_roller_SetDateDay, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDate_roller_SetDateDay, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDate_roller_SetDateDay, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDate_roller_SetDateDay, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetDate_roller_SetDateDay, 3);
    //The custom code of SetDate.


    //Update current screen layout.
    lv_obj_update_layout(ui->SetDate);

    //Init events for screen.
    events_init_SetDate(ui);
}

void deinit_scr_SetDate(void)
{
	
}
