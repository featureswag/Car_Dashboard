#include "stm32f10x.h" // Device header
#include "delay.h"

volatile uint16_t revolutions = 0;  // 旋转次数计数器
volatile uint16_t times=0;

void HALL_ENCODER_Init(void) {
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_ICInitTypeDef  TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInit(TIM1, &TIM_ICInitStructure);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_ITConfig(TIM1, TIM_IT_CC1, ENABLE);
    TIM_Cmd(TIM1, ENABLE);
}

// TIM1 中断处理函数
void TIM1_CC_IRQHandler(void) {
    if (TIM_GetITStatus(TIM1, TIM_IT_CC1) != RESET) {

        TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);
        revolutions++;  // 每次霍尔传感器触发时增加计数器
				
    }
}

// 获取圈数并重置计数器
uint16_t GetRevolutions(void) {
    uint16_t revs = revolutions;
		times++;
    if(times>1500)
		{
			times =0;
			revolutions = 0;  // 重置计数器
		}
		if(revs>0)
		{
			revs--;
		}
    return revs;      // 返回自上次调用以来的旋转次数
}





