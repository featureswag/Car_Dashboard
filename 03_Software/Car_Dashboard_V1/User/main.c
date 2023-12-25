#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"

/*uint16_t AD_Value;
uint8_t i;
float AD_Voltage;*/
int main(void)
{
	LCD1602_Init();
	LCD1602_ClearScreen();
	LCD1602_Show_Str(0,0,"1.Oil");
	LCD1602_Show_Str(0,1,"2.Velocity");
	while(1)
	{
		
	}
	return 0;
}

