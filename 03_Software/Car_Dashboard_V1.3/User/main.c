#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"
#include "keypad.h"
#include "peripheralInit.h"
#include "lcd_tft.h"
#include "hall_sensor.h"
/*uint16_t AD_Value;
uint8_t i;
float AD_Voltage;*/
int main(void)
{
//  u8 KeyValue;
	PeripheralInit(); // LCD初始化
	LCD_Clear(LCD_COLOR_BLACK); // 设置背景色
  HALL_SENSOR_Init();
  AD_Init();
	LCD_WriteString (10, 150, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"OIL LEFT");
	LCD_WriteString (10, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED");
  //uint16_t cyclecount = 0;
	uint16_t currentspeed = 0;
//	uint16_t times = 0;
	uint16_t mile = 0;
	uint16_t advalue = 0;
  while (1)
  {	
		currentspeed =getCycleCount();
		advalue = AD_GetValue();
		//calculate the travelled distance
		// if(times>0)
		// {
		// 	times =0;
		// 	mile = mile + currentspeed;
		// }
		LCD_WriteString (10, 150, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"OIL LEFT");
		LCD_WriteNumInt (160, 150, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint16_t) advalue);
		LCD_WriteString (10, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED");
		LCD_WriteNumInt (160, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint16_t) currentspeed);
		LCD_WriteString (250, 170, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *) "meter/s");

		mile = getTravelledDistance();
		LCD_WriteString (10, 190, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *) "TRAVELLED DISTANCE");
		LCD_WriteNumInt (160, 190, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint16_t) mile);
		LCD_WriteString (250, 190, LCD_COLOR_RED, LCD_COLOR_BLACK,(uint8_t *) "meter");
  
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

