#include "stm32f10x.h"
#include "delay.h"
/**
 * @brief  Key Initialization Function  [按键初始化函数]
 * @param  None
 * @retval None 
 */
void KEY_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);     // Enable GPIOB clock        [开启GPIOB时钟]
    GPIO_InitTypeDef GPIO_InitStrucure;                      // Define GPIO_InitStructure [定义GPIO_InitStructure]
    GPIO_InitStrucure.GPIO_Mode  = GPIO_Mode_IPU;            // Mode: Push-pull output    [模式：推挽输出]
    GPIO_InitStrucure.GPIO_Pin   = GPIO_Pin_1 | GPIO_Pin_11 ;// Pin: 1 & 11               [引脚：1 & 11]
    GPIO_InitStrucure.GPIO_Speed = GPIO_Speed_50MHz;         // Speed: 50MHz              [速度：50MHz]

    GPIO_Init(GPIOB, &GPIO_InitStrucure);                    // Initialize GPIOB          [初始化GPIOB]
}

/**
 * @brief  Key Read Function  [按键读取函数]
 * @param  None
 * @retval key state     [按键状态]
 *     1: Key 1 pressed  [按键1按下]
 *     2: Key 2 pressed  [按键2按下]
 */
uint8_t KEY_Read(void)
{
    uint8_t KeyState;
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0){
       delay_ms(20);
       while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);
       delay_ms(20);
       KeyState = 1;
    }
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0){
       delay_ms(20);
       while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0);
       delay_ms(20);
       KeyState = 2;
    }

    return KeyState;
}

