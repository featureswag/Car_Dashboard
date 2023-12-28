#include "stm32f10x.h" // Device header
#include "delay.h"

volatile uint16_t cycle = 0;  // cycle is how many times the sensor counts
volatile uint16_t times=0;
//volatile uint16_t currentspeed =0;
volatile uint16_t distance = 0;  // distance is the distance travelled in mm

void HALL_SENSOR_Init(void) {
    
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


void TIM1_CC_IRQHandler(void) {
    if (TIM_GetITStatus(TIM1, TIM_IT_CC1) != RESET) {

        TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);
        cycle++;  // increment the cycle count
				
    }
}

// get the number of revolutions 
uint16_t getCycleCount(void) {
    uint16_t revs = 0;
    revs = cycle;
    times++;
    if(times>500)
		{
			times =0;
			cycle = 0;  // reset the counter
		}
		//currentspeed = cycle*1.6;
    return revs;  // return the number of revolutions
}


uint16_t getTravelledDistance(void) {
    distance = distance + cycle;  // return the number of revolutions
    return distance;  // return the number of revolutions
}


