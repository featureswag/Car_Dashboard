#include "stm32f10x.h"
#include "keypad4x4.h"
 
void KEYPAD4x4_Init()
{
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);     // Enable GPIOB clock        [开启GPIOB时钟]
   GPIO_InitTypeDef GPIO_InitStrucure;                      // Define GPIO_InitStructure [定义GPIO_InitStructure]
   GPIO_InitStrucure.GPIO_Mode  = GPIO_Mode_IPU;            // Mode: Push-pull output    [模式：推挽输出]
   GPIO_InitStrucure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 ;// Pin: 1 & 2               [引脚：1 & 11]
   GPIO_InitStrucure.GPIO_Speed = GPIO_Speed_50MHz;         // Speed: 50MHz              [速度：50MHz]

   GPIO_Init(GPIOB, &GPIO_InitStrucure);                    // Initialize GPIOB          [初始化GPIOB]
}
