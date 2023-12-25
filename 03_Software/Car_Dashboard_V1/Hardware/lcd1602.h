#ifndef __LCD1602_H
#define __LCD1602_H	  
#include "stm32f10x.h"
#define LCD_DATA_PORT 					 GPIOD//1602指令/数据 引脚
#define	LCD_RS_Set()	GPIO_SetBits	(GPIOD, GPIO_Pin_0)
#define	LCD_RS_Clr()	GPIO_ResetBits	(GPIOD, GPIO_Pin_0)//1602读写引脚
#define	LCD_RW_Set()	GPIO_SetBits	(GPIOD, GPIO_Pin_1)
#define	LCD_RW_Clr()	GPIO_ResetBits	(GPIOD, GPIO_Pin_1)//1602使能引脚
#define	LCD_EN_Set()	GPIO_SetBits	(GPIOD, GPIO_Pin_2)
#define	LCD_EN_Clr()	GPIO_ResetBits	(GPIOD, GPIO_Pin_2)//1602数据端口	PD4~7
#define	DATAOUT(x)		LCD_DATA_PORT->ODR=(LCD_DATA_PORT->ODR&0X0F)|(x&0xf0)

void GPIO_Configuration(void);
void LCD1602_Wait_Ready(void);
void LCD1602_Write_Cmd(u8 cmd);
void LCD1602_Write_Dat(u8 dat);
void LCD1602_ClearScreen(void);
void LCD1602_Set_Cursor(u8 x, u8 y);
void LCD1602_Show_Str(u8 x, u8 y, u8 *str);
void LCD1602_Init(void);
void LCD1602_write_figer(unsigned char y_add , unsigned char x_add , u32 figer, unsigned int len);//在任何位置写数字-数组
#endif
