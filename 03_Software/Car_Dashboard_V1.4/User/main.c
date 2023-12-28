#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"
#include "keypad.h"
#include "peripheralInit.h"
#include "lcd_tft.h"
#include "hall_sensor.h"

uint16_t current_speed = 0;
uint16_t travelled_distance = 0;
uint16_t oil_level = 0;
uint16_t flag = 1000;

void displaybasicInfo(void);
void updateSpeedInfo(void);
void displaySpeedInfo(void);
void updateOilInfo(void);
void displayOilInfo(void);

int main(void)
{
	PeripheralInit();
	LCD_Clear(LCD_COLOR_BLACK);

	displaybasicInfo();
	updateSpeedInfo();
	updateOilInfo();
	while(1)
	{
		displaySpeedInfo();
		updateSpeedInfo();
		displayOilInfo();
		updateOilInfo();
		flag ++;
	}
}

void displaybasicInfo(void)
{
	LCD_WriteString(10,10,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"CAR DASHBOARD");
	LCD_WriteString(10,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"CURRENT SPEED:");
	LCD_WriteString(280,30,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M/S");
	LCD_WriteString(10,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"TRAVELLED DISTANCE:");
	LCD_WriteString(280,50,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"M");
	LCD_WriteString(10,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,(uint8_t *)"OIL LEVEL:");
	LCD_DisplayChar(280,70,'%');
}

void updateSpeedInfo(void)
{
	current_speed = getCycleCount();
	travelled_distance = getTravelledDistance();
}

void displaySpeedInfo(void)
{
	LCD_WriteNumInt (200,30,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) current_speed);
	LCD_WriteNumInt (200,50,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) travelled_distance/120);
}

void updateOilInfo(void)
{
	if(flag >= 800)
	{
		uint16_t temp = getOilLevel();
		oil_level = temp/36;
		if(oil_level < 13)
		{
			oil_level = 0;
		}
		else if(oil_level >100)
		{
			oil_level = 100;
		}
		flag = 0;
		temp = 0;
	}
	
}

void displayOilInfo(void)
{
	LCD_WriteNumInt(200,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,oil_level); //显示油量
	//oil_level=0;
}
