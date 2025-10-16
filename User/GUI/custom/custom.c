/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
 
const uint8_t ui_LTimeOptions[6] = {10,15,20,30,45,60};
const uint8_t ui_OTimeOptions[6] = {15,20,25,35,50,65};
uint8_t ui_LightTimeVale = 10;
uint8_t ui_OffTimeVale = 15;
uint8_t ui_LightTimeSelected = 0;
uint8_t ui_OffTimeSelected = 0;

//HomeΩÁ√Ê
uint8_t ui_LightSliderValue = 50;

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

