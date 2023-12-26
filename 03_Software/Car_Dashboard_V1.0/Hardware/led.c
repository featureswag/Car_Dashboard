#include "stm32f10x.h" // Device header
    /**
     * @brief  LED initialization function [LED初始化函数]
     * @param  None
     * @retval None
     */
void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);       // Enable GPIOA clock
    GPIO_InitTypeDef GPIO_InitStructure;                        // Define GPIO_InitStructure

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;           // Mode: Push-pull output
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1 | GPIO_Pin_2;    // Pin: 1 & 2
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // Speed: 50MHz

    GPIO_Init(GPIOA, &GPIO_InitStructure);                      // Initialize GPIOA

    GPIO_SetBits(GPIOA,GPIO_Pin_1 | GPIO_Pin_2);                // turn off LED_1 & LED_2
}//[test passed]

/**
 * @brief  LED 1 turn on function  [LED_1 点亮操作函数]
 * @param  None
 * @retval None
 */
void LED_On_1(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_1);                            // turn on LED_1
}//this function is used to turn on the LED1 (test passed)

/**
 * @brief  LED 2 turn on function   [LED_2 点亮操作函数]
 * @param  None
 * @retval None
 */
void LED_On_2(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);                            // turn on LED_2
}//this function is used to turn on the LED2 (test passed)

/**
 * @brief  LED 1 turn off function  [LED_1 熄灭操作函数]
 * @param  None
 * @retval None
 */
void LED_Off_1(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_1);                            // turn off LED_1
}//this function is used to turn off the LED1 (test passed)

/**
 * @brief  LED 2 turn off function  [LED_2 熄灭操作函数]
 * @param  None
 * @retval None
 */
void LED_Off_2(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_2);                            // turn off LED_2
}//this function is used to turn off the LED2 (test passed)

/**
 * @brief  switch LED 1 and LED 2 to on or off  [LED_1 和 LED_2 点亮或熄灭操作函数]
 * @param  LED to change                        [要改变的LED]
 *       @arg 1: LED 1                          [1 表示操作 LED 1]
 *       @arg 2: LED 2                          [2 表示操作 LED 2]
 * @param  enable or disable                    [使能或失能]
 *       @arg 0: off                            [0 表示熄灭]
 *       @arg 1: on                             [1 表示点亮]
 * @retval none
 */
void LED_Switch(uint8_t LED, uint8_t Mode)
{
    switch(LED){
        case 1:         //LED 1
        if(Mode == 1)
        {
            GPIO_ResetBits(GPIOA,GPIO_Pin_1);                          // turn on LED_1
        }
        else
        {
            GPIO_SetBits(GPIOA,GPIO_Pin_1);                            // turn off LED_1
        }
        case 2:         //LED 2
        if(Mode == 0)
        {
            GPIO_ResetBits(GPIOA,GPIO_Pin_2);                          // turn on LED_2
        }
        else
        {
            GPIO_SetBits(GPIOA,GPIO_Pin_2);                            // turn off LED_2
        } 
    }
}
/**
 * @brief  LED 1 reverse state function, use buttton to control   [LED_1 状态翻转操作函数]
 * @param  None
 * @retval None 
 */
void LED_Reverse_1(void)
{
    if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0){
        GPIO_SetBits(GPIOA, GPIO_Pin_1);
    }
    else{
        GPIO_ResetBits(GPIOA, GPIO_Pin_1);
    }
}
/**
 * @brief  LED 2 reverse state function, use buttton to control  [LED_2 状态翻转操作函数]
 * @param  None
 * @retval None
*/
void LED_Reverse_2(void)
{
    if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0){
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
    }
    else{
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);
    }
}
