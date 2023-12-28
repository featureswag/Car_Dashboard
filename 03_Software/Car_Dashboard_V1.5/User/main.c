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
uint16_t keyval = 0;

//English Version display
void display_English_BasicInfo(void);
//Chinese Version display
void display_Chinese_BasicInfo(void);

//Module Info display
void display_SpeedInfo(void);
void display_OilInfo(void);

//Update program function
void update_SpeedInfo(void);
void update_OilInfo(void);

int main(void)
{
	PeripheralInit();
	LCD_Clear(LCD_COLOR_BLACK);

	// info display and update
	display_English_BasicInfo();
	update_SpeedInfo();
	update_OilInfo();

	while(1)
	{
		keyval = KeyTransfer();
		switch (keyval)
		{
		case 1:
			display_English_BasicInfo();
			break;
		case 2:
			display_Chinese_BasicInfo();
			break;
		default:
			break;
		}
		display_SpeedInfo();
		update_SpeedInfo();
		display_OilInfo();
		update_OilInfo();
		flag ++;
	}
}

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
void display_SpeedInfo(void)
{
	LCD_WriteNumInt (200,30,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) current_speed);
	LCD_WriteNumInt (200,50,LCD_COLOR_YELLOW, LCD_COLOR_BLACK,(uint16_t) travelled_distance/120);
}

void display_OilInfo(void)
{
	LCD_WriteNumInt(200,70,LCD_COLOR_YELLOW,LCD_COLOR_BLACK,oil_level); 
}




void update_SpeedInfo(void)
{
	current_speed = getCycleCount();
	travelled_distance = getTravelledDistance();
}

void update_OilInfo(void)
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

