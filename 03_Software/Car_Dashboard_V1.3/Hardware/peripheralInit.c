#include <stm32f10x.h>
#include "Delay.h"
#include "keypad.h"
#include "lcd1602.h"
#include "PeripheralInit.h"
#include "lcd_tft.h"
/*
  函数功能: 系统外设初始化
  入口参数: 无
  返 回 值: 无
  注意事项: 无
*/
void PeripheralInit(void)
{
  //LCM_Init();                    // 液晶1602初始化
  GPIO_Keyboard_Configuration(); // 键盘IO口配置
  LCD_Init(); // 液晶初始化
}

