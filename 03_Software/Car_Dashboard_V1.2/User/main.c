#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"
#include "keypad.h"
#include "peripheralInit.h"
#include "lcd_tft.h"
#include "hall_encoder.h"
/*uint16_t AD_Value;
uint8_t i;
float AD_Voltage;*/
int main(void)
{
//  u8 KeyValue;
	PeripheralInit(); // LCD初始化
	LCD_Clear(LCD_COLOR_BLACK); // 设置背景色
  HALL_ENCODER_Init();
  
	LCD_WriteString (10, 150, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"OIL LEFT");
	LCD_WriteString (10, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED");
  
  while (1)
  {	
		uint16_t revs = GetRevolutions();
		LCD_WriteString (10, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED");
		LCD_WriteNumInt (10, 190, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint16_t) revs);
  
//    // 按键扫描
//    KeyValue = KeyTransfer(); // 读取矩阵键盘值
//    if (KeyValue != 0xff)
//    {
//      LCD_WriteString(10,10,LCD_COLOR_RED,LCD_COLOR_BLACK,(uint8_t *)"Key Value:"); // 显示按键值
//      LCD_WriteNumChar(10,30,LCD_COLOR_RED,LCD_COLOR_BLACK,KeyValue); // 显示按键值
//			
//    }
  }
}

