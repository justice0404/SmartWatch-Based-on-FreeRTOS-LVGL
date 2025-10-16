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

/**************屏幕注册**************/
void deinit_scr_Calculater(void);
Page_t Page_Calculater  = {"Calculater",setup_scr_Calculater,deinit_scr_Calculater,&guider_ui.Calculater};


void setup_scr_Calculater(lv_ui *ui)
{
    //Write codes Calculater
    ui->Calculater = lv_obj_create(NULL);
    lv_obj_set_size(ui->Calculater, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Calculater, LV_SCROLLBAR_MODE_OFF);

    //Write style for Calculater, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Calculater, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Calculater, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Calculater, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Calculater_btnm_1
    ui->Calculater_btnm_1 = lv_btnmatrix_create(ui->Calculater);
    static const char *Calculater_btnm_1_text_map[] = {"1", "2", "3", "+", "\n", "4", "5", "6", "-", "\n", "7", "8", "9", "x", "\n", ".", "0", "=", "÷", "",};
    lv_btnmatrix_set_map(ui->Calculater_btnm_1, Calculater_btnm_1_text_map);
    lv_obj_set_pos(ui->Calculater_btnm_1, 0, 70);
    lv_obj_set_size(ui->Calculater_btnm_1, 240, 210);

    //Write style for Calculater_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Calculater_btnm_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Calculater_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Calculater_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Calculater_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Calculater_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui->Calculater_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->Calculater_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Calculater_btnm_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Calculater_btnm_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Calculater_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Calculater_btnm_1, 1, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Calculater_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Calculater_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Calculater_btnm_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Calculater_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Calculater_btnm_1, &lv_font_montserratMedium_20, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Calculater_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Calculater_btnm_1, 4, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Calculater_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Calculater_btnm_1, lv_color_hex(0x868787), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Calculater_btnm_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Calculater_btnm_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //The custom code of Calculater.


    //Update current screen layout.
    lv_obj_update_layout(ui->Calculater);

}

void deinit_scr_Calculater(void)
{
	
}
