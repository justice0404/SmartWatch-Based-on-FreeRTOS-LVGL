#ifndef __AHT21_H
#define __AHT21_H

#include "main.h"
#include "delay.h"
#include "MyI2C.h"

uint8_t AHT_Read_Status(void);
void AHT_Reset(void);
uint8_t AHT_Init(void);
uint8_t AHT_Read(float *humi, float *temp);

#endif
