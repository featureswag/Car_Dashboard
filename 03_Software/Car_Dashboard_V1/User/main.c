#include "stm32f10x.h" // Device header
#include "delay.h"
#include "oled.h"
#include "ad.h"
#include "lcd1602.h"
#include "keypad.h"
#include "peripheralInit.h"
/*uint16_t AD_Value;
uint8_t i;
float AD_Voltage;*/
int main(void)
{
  u8 KeyValue;

  PeripheralInit(); // LCM1602初始化
  WrCLcdC(0x01);
  WriteString(1, 1, "Keyboard Test!"); // 显示提示信息
  WriteString(2, 1, "Key Value:");

  while (1)
  {
    // 按键扫描
    KeyValue = KeyTransfer(); // 读取矩阵键盘值
    if (KeyValue != 0xff)
    {
      WriteString(2, 12, "   ");        // 显示键值前清前显示键值
      WrCLcd_char_num(2, 12, KeyValue); // 显示键值
    }
  }
}

