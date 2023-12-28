#include <stm32f10x.h>
#include "Delay.h"
#include "keypad.h"
#include "lcd1602.h"
#include "PeripheralInit.h"
#include "lcd_tft.h"
#include "hall_sensor.h"
#include "ad.h"
/*
  函数功能: 系统外设初始化
  入口参数: 无
  返 回 值: 无
  注意事项: 无
*/
void PeripheralInit(void)
{
  //LCM_Init();                    // lcd1602 init
  GPIO_Keyboard_Configuration(); // keypad init
  LCD_Init(); // lcd_tft init
  HALL_SENSOR_Init(); //hall sensor init
  AD_Init();
}

