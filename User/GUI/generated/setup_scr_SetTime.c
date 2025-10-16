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
void deinit_scr_SetTime(void);
Page_t Page_SetTime  = {"SetTime",setup_scr_SetTime,deinit_scr_SetTime,&guider_ui.SetTime};

/**************变量管理**************/
const char  houroptions[] = "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23";
const char  minoptions[] = "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59";

void setup_scr_SetTime(lv_ui *ui)
{
	HW_DateTimeTypeDef datetime;
	HWInterface.RealTimeClock.GetTimeDate(&datetime);
	
    //Write codes SetTime
    ui->SetTime = lv_obj_create(NULL);
    lv_obj_set_size(ui->SetTime, 240, 280);
    lv_obj_set_scrollbar_mode(ui->SetTime, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetTime, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetTime_roller_SetTimeHour
    ui->SetTime_roller_SetTimeHour = lv_roller_create(ui->SetTime);
    lv_roller_set_options(ui->SetTime_roller_SetTimeHour,houroptions, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetTime_roller_SetTimeHour,datetime.Hours,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetTime_roller_SetTimeHour, 30, 70);
    lv_obj_set_width(ui->SetTime_roller_SetTimeHour, 50);

    //Write style for SetTime_roller_SetTimeHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetTime_roller_SetTimeHour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeHour, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeHour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeHour, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetTime_roller_SetTimeHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetTime_roller_SetTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_roller_SetTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_roller_SetTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_roller_SetTimeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetTime_roller_SetTimeHour, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeHour, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeHour, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeHour, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeHour, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeHour, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeHour, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetTime_roller_SetTimeHour, 3);
    //Write codes SetTime_roller_SetTimeMintue
    ui->SetTime_roller_SetTimeMintue = lv_roller_create(ui->SetTime);
    lv_roller_set_options(ui->SetTime_roller_SetTimeMintue,minoptions, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetTime_roller_SetTimeMintue,datetime.Minutes,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetTime_roller_SetTimeMintue, 95, 70);
    lv_obj_set_width(ui->SetTime_roller_SetTimeMintue, 50);

    //Write style for SetTime_roller_SetTimeMintue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetTime_roller_SetTimeMintue, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeMintue, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeMintue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeMintue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeMintue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeMintue, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeMintue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetTime_roller_SetTimeMintue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetTime_roller_SetTimeMintue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_roller_SetTimeMintue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_roller_SetTimeMintue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_roller_SetTimeMintue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetTime_roller_SetTimeMintue, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeMintue, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeMintue, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeMintue, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeMintue, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeMintue, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeMintue, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetTime_roller_SetTimeMintue, 3);
    //Write codes SetTime_roller_SetTimeSecond
    ui->SetTime_roller_SetTimeSecond = lv_roller_create(ui->SetTime);
    lv_roller_set_options(ui->SetTime_roller_SetTimeSecond,minoptions, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(ui->SetTime_roller_SetTimeSecond,datetime.Seconds,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetTime_roller_SetTimeSecond, 160, 70);
    lv_obj_set_width(ui->SetTime_roller_SetTimeSecond, 50);

    //Write style for SetTime_roller_SetTimeSecond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetTime_roller_SetTimeSecond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeSecond, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeSecond, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeSecond, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetTime_roller_SetTimeSecond, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetTime_roller_SetTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_roller_SetTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_roller_SetTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_roller_SetTimeSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetTime_roller_SetTimeSecond, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetTime_roller_SetTimeSecond, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_roller_SetTimeSecond, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_roller_SetTimeSecond, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_roller_SetTimeSecond, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_roller_SetTimeSecond, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_roller_SetTimeSecond, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetTime_roller_SetTimeSecond, 3);
    //Write codes SetTime_label_SetTimeIcon1
    ui->SetTime_label_SetTimeIcon1 = lv_label_create(ui->SetTime);
    lv_label_set_text(ui->SetTime_label_SetTimeIcon1, ":");
    lv_label_set_long_mode(ui->SetTime_label_SetTimeIcon1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetTime_label_SetTimeIcon1, 85, 105);
    lv_obj_set_size(ui->SetTime_label_SetTimeIcon1, 5, 30);

    //Write style for SetTime_label_SetTimeIcon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_label_SetTimeIcon1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_label_SetTimeIcon1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_label_SetTimeIcon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetTime_label_SetTimeIcon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_label_SetTimeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetTime_label_SetTimeIcon2
    ui->SetTime_label_SetTimeIcon2 = lv_label_create(ui->SetTime);
    lv_label_set_text(ui->SetTime_label_SetTimeIcon2, ":");
    lv_label_set_long_mode(ui->SetTime_label_SetTimeIcon2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetTime_label_SetTimeIcon2, 150, 105);
    lv_obj_set_size(ui->SetTime_label_SetTimeIcon2, 5, 30);

    //Write style for SetTime_label_SetTimeIcon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetTime_label_SetTimeIcon2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetTime_label_SetTimeIcon2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetTime_label_SetTimeIcon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetTime_label_SetTimeIcon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_label_SetTimeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetTime_img_SetTimeConfirm
    ui->SetTime_img_SetTimeConfirm = lv_img_create(ui->SetTime);
    lv_obj_add_flag(ui->SetTime_img_SetTimeConfirm, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetTime_img_SetTimeConfirm, &_confirm_alpha_30x30);
    lv_img_set_pivot(ui->SetTime_img_SetTimeConfirm, 50,50);
    lv_img_set_angle(ui->SetTime_img_SetTimeConfirm, 0);
    lv_obj_set_pos(ui->SetTime_img_SetTimeConfirm, 105, 240);
    lv_obj_set_size(ui->SetTime_img_SetTimeConfirm, 30, 30);

    //Write style for SetTime_img_SetTimeConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetTime_img_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetTime_img_SetTimeConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetTime_img_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetTime_img_SetTimeConfirm, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetTime_cont_SetTimeConfirm
    ui->SetTime_cont_SetTimeConfirm = lv_obj_create(ui->SetTime);
    lv_obj_set_pos(ui->SetTime_cont_SetTimeConfirm, 0, 240);
    lv_obj_set_size(ui->SetTime_cont_SetTimeConfirm, 240, 40);
    lv_obj_set_scrollbar_mode(ui->SetTime_cont_SetTimeConfirm, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetTime_cont_SetTimeConfirm, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetTime_cont_SetTimeConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetTime_cont_SetTimeConfirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetTime_cont_SetTimeConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetTime_cont_SetTimeConfirm, lv_color_hex(0x0e0e0e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetTime_cont_SetTimeConfirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetTime_cont_SetTimeConfirm, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetTime_cont_SetTimeConfirm, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetTime_cont_SetTimeConfirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetTime_cont_SetTimeConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of SetTime.


    //Update current screen layout.
    lv_obj_update_layout(ui->SetTime);

    //Init events for screen.
    events_init_SetTime(ui);
}

void deinit_scr_SetTime(void)
{
	
}
