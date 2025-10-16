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
void deinit_scr_Game(void);
Page_t Page_Game  = {"Game",setup_scr_Game,deinit_scr_Game,&guider_ui.Game};


void setup_scr_Game(lv_ui *ui)
{
    //Write codes Game
    ui->Game = lv_obj_create(NULL);
    lv_obj_set_size(ui->Game, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Game, LV_SCROLLBAR_MODE_OFF);

    //Write style for Game, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Game, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Game, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Game, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Game_btn_Game
    ui->Game_btn_Game = lv_btn_create(ui->Game);
    ui->Game_btn_Game_label = lv_label_create(ui->Game_btn_Game);
    lv_label_set_text(ui->Game_btn_Game_label, "Home");
    lv_label_set_long_mode(ui->Game_btn_Game_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Game_btn_Game_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Game_btn_Game, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Game_btn_Game_label, LV_PCT(100));
    lv_obj_set_pos(ui->Game_btn_Game, 70, 170);
    lv_obj_set_size(ui->Game_btn_Game, 100, 50);

    //Write style for Game_btn_Game, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Game_btn_Game, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Game_btn_Game, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Game_btn_Game, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Game_btn_Game, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Game_btn_Game, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Game_btn_Game, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Game_btn_Game, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Game_btn_Game, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Game_btn_Game, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Game_btn_Game, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Game_label_GameText
    ui->Game_label_GameText = lv_label_create(ui->Game);
    lv_label_set_text(ui->Game_label_GameText, "Under Development ......");
    lv_label_set_long_mode(ui->Game_label_GameText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Game_label_GameText, 20, 50);
    lv_obj_set_size(ui->Game_label_GameText, 200, 80);

    //Write style for Game_label_GameText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Game_label_GameText, lv_color_hex(0xb9b8b8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Game_label_GameText, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Game_label_GameText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Game_label_GameText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Game_label_GameText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Game.


    //Update current screen layout.
    lv_obj_update_layout(ui->Game);

    //Init events for screen.
    events_init_Game(ui);
}

void deinit_scr_Game(void)
{
	
}
