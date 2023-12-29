#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"
#include "keypad.h"
#include "peripheralInit.h"
#include "lcd_tft.h"
#include "hall_sensor.h"
#include "display.h"
#include "fonts.h"

volatile uint16_t current_speed = 0;
volatile uint16_t travelled_distance = 0;
volatile uint16_t oil_level = 0;



void display_English_BasicInfo(void)
{
	LCD_Clear(LCD_COLOR_BLACK);
	LCD_WriteString(10,10,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"CAR DASHBOARD");
	LCD_WriteString(10,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED:");
	LCD_WriteString(280,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M/S");
	LCD_WriteString(10,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"TRAVELLED DISTANCE:");
	LCD_WriteString(280,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M");
	LCD_WriteString(10,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"OIL LEVEL:");
	LCD_DisplayChar(280,70,'%');

}

void display_Chinese_BasicInfo(void)
{
	LCD_Clear(LCD_COLOR_BLACK);
	LCD_WriteString(10,10,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"汽车仪表盘");
	LCD_WriteString(10,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"当前速度:");
	LCD_WriteString(280,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M/S");
	LCD_WriteString(10,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"已行驶里程数:");
	LCD_WriteString(280,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M");
	LCD_WriteString(10,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"剩余油量:");
	LCD_DisplayChar(280,70,'%');
}
void display_SpeedInfo(uint16_t current_status)
{
	LCD_WriteNumInt (200,30,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) current_speed);
	LCD_WriteNumInt (200,50,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) travelled_distance/120);
	if(current_status == 1)
	{
		if(current_speed>15) LCD_WriteString(160,170,LCD_COLOR_YELLOW,LCD_COLOR_RED,(uint8_t *)"SPEED WARNING!");
		else LCD_WriteString(160,170,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"               ");
	}
	else if(current_status == 2)
	{
		if(current_speed>15) LCD_WriteString(160,170,LCD_COLOR_YELLOW,LCD_COLOR_RED,(uint8_t *)"速度警告!");
		else LCD_WriteString(160,170,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"           ");
	}
}

void display_OilInfo(uint16_t current_status)
{
	LCD_WriteNumInt(200,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,oil_level); 
	if(current_status == 1)
	{
		if(oil_level<10) LCD_WriteString(10,170,LCD_COLOR_YELLOW,LCD_COLOR_RED,(uint8_t *)"OIL WARNING!");
		else LCD_WriteString(10,170,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"               ");
	}
	else if(current_status == 2)
	{
		if(oil_level<10) LCD_WriteString(10,170,LCD_COLOR_YELLOW,LCD_COLOR_RED,(uint8_t *)"油量警告!");
		else LCD_WriteString(10,170,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"          ");
	}
	
}

void update_SpeedInfo(void)
{
	current_speed = getCycleCount();
	travelled_distance = getTravelledDistance();
}

void update_OilInfo(uint16_t flag)
{
	if(flag >= 800)
	{
		uint16_t temp = getOilLevel();
		oil_level = temp/36;
		if(oil_level < 13) oil_level = 0;
		else if(oil_level >100) oil_level = 100;
		flag = temp = 0;
	}
}
