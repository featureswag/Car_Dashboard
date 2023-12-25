#include "stm32f10x.h"                  // Device header

/* *
    * @brief: initialize ADC
    * @param: none
    * @retval: none
*/
void AD_Init(void)
{
    /* *
    * 1. RCC Configuration 
        -* a. enable ADC clock
        -* b. enable GPIO clock
        -* c. configure ADC clock (prescaler, clock source)
    */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6); // ADCCLK = 72MHz / 6 = 12MHz

    /* *
    * 2. GPIO Configuration
        -* a. configure GPIO as analog input
    */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; // analog input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;     // PA0
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    /* *
    * 3. Regular Channel Configuration
        -* a. configure ADC channel
        -* b. configure ADC rank
        -* c. configure ADC sample time 
            sample time = 55.5 cycles = 1/12MHz * 55.5 = 4.625us
    */
    ADC_RegularChannelConfig(ADC1,ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);

    /**
     * 4. ADC Configuration
        -* a. configure ADC resolution
        -* b. configure ADC data alignment
        -* c. configure ADC conversion mode
        -* d. configure ADC external trigger
        -* e. configure ADC data alignment
        -* f. configure ADC continuous conversion mode
        -* g. configure ADC DMA
    */
    ADC_InitTypeDef ADC_InitStructure; 
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;     // independent mode, ADC1
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; // right alignment
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // no external trigger
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; // single conversion mode
    ADC_InitStructure.ADC_ScanConvMode = DISABLE; // single channel
    ADC_InitStructure.ADC_NbrOfChannel = 1; // 1 channel
    ADC_Init(ADC1,&ADC_InitStructure);

    /* *
    * 5. Enable ADC
        use ADC_Cmd() function
    */
    ADC_Cmd(ADC1,ENABLE);

    /* *
    * 6. ADC Calibration
        -* a. Enable ADC reset calibration register
        -* b. Check the ADC reset calibration register until the end of the reset calibration
        -* c. Start ADC calibration
        -* d. Check the ADC calibration until the end of the calibration
        -* e. Read the ADC calibration value
    */
    ADC_ResetCalibration(ADC1);
    while(ADC_GetResetCalibrationStatus(ADC1) == SET);/* wait until the end of the reset 
                                                         calibration.*/
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1) == SET);/* wait until the end of the calibration*/
}

/* *
    * @brief: Get ADC value
    * @param: none
    * @retval: ADC value
*/
uint16_t AD_GetValue(void)
{
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);
    while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);/*wait until the end of conversion
                                                            sample time = 55.5 cycles + 12.5 cycles --> 68 cycles 
                                                            time --> 1/(72MHz/6) = 1/12MHz
                                                            1/12MHz * 68 = 5.666us*/
    return ADC_GetConversionValue(ADC1);
}
