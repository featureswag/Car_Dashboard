# AD 单次转换非扫描

#### 原理

原理：通过判断 EOC (End of Conversion) 转换结束标志位来判断转换是否完成。

> 该位由硬件（规则或注入）通道组转换结束时设置，由软件清楚或由读取ADC_DR时清楚。

- 0 表示转换未完成
- 1 表示转换完成

#### 代码部分

**AD 初始化代码（校准部分）**

```C
void AD_Init(void)
{
    /*********************************************************************************
	其他配置代码
		………………………………
		………………………………
		………………………………（略）
*********************************************************************************** /
	
	
	/*校准步骤
	1、复位校准。
	2、等待复位校准完成。
	3、开始校准。
	4、等待校准完成。*/
	ADC_ResetCalibration(ADC1); // 复位
    while(ADC_GetResetCalibrationStatus(ADC1) == SET);/* wait until the end of the reset 
                                                         calibration.*/
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1) == SET);/* wait until the end of the calibration*/
}

```



**返回 AD 值**

```c
uint16_t AD_GetValue(void)
{
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);
    while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);/*wait until the end of conversion
                                                            sample time = 55.5 cycles + 12.5 
                                                            cycles --> 68 cycles 
                                                            time --> 1/(72MHz/6) = 1/12MHz
                                                            1/12MHz * 68 = 5.666us*/
    return ADC_GetConversionValue(ADC1);
}
```

采样时间= 55.5 个采样周期 + 12.5 个固定采样周期 = 68 个采样周期

采样频率 = 晶振72MHz / 6 分频 = 12MHz

采样时间 = （1 / 12MHz ）* 68 个采样周期 = 5.666us 

 