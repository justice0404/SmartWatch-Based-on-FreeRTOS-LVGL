# SmartWatch-Based-on-FreeRTOS-LVGL
一个基于STM32F411CUE6微控制器、FreeRTOS实时操作系统和LVGL图形库开发的多功能智能手表原型。本项目独立实现了从底层传感器驱动（I2C/SPI）到系统构建（FreeRTOS）再到上层应用（LVGL）的全流程开发，完整复刻了智能手表的心率、海拔、温湿度等数据测量和熄屏、关机的低功耗设计等核心功能。重点解决有限MCU内存下，UI界面无卡顿的挑战，实现了30FPS+流畅运行。
