#ifndef __KEYPAD4x4_H
#define __KEYPAD4x4_H	 
#include "sys.h"
#include "delay.h"
 
 
#define KEYPAD4x4PORT	GPIOA	//定义IO接口组
#define KEY4	GPIO_Pin_11	//定义IO接口
#define KEY3	GPIO_Pin_12	//定义IO接口
#define KEY2	GPIO_Pin_2	//定义IO接口
#define KEY1	GPIO_Pin_3	//定义IO接口
#define KEYa	GPIO_Pin_4	//定义IO接口
#define KEYb	GPIO_Pin_5	//定义IO接口
#define KEYc	GPIO_Pin_6	//定义IO接口
#define KEYd	GPIO_Pin_7	//定义IO接口
 
 
void KEYPAD4x4_Init(void);//初始化
void KEYPAD4x4_Init2(void);//初始化2（用于IO工作方式反转）
u8 KEYPAD4x4_Read (void);//读阵列键盘
		 				    
#endif