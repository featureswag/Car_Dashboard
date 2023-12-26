#include <stm32f10x.h>
#include "delay.h"
#include "keypad.h"

//-----------------------------------------------------------------
// 全局变量定义
//-----------------------------------------------------------------
u8 IOToggle = 0x00; // IO输入输出状态切换变量

//-----------------------------------------------------------------
// void GPIO_Keyboard_Configuration(void)
//-----------------------------------------------------------------
//
// 函数功能: 按键IO口配置
// 入口参数: 无
// 返回参数: 无
// 全局变量: 无
// 调用模块: 无
// 注意事项: 注意IO状态切换
// 键盘及IO口分配:
//       PE0     -1-  -2-    -3-    -+-
//       PE1     -4-  -5-    -6-    ---
//       PE2     -7-  -8-    -9-    -*-
//       PE3    -Brk-  -0-    -ok-  -/-
//          		PE4    PE5    PE6   PC13
//-----------------------------------------------------------------
void GPIO_Keyboard_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  // 打开PE,PC口时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOE, ENABLE);
  //**********************************************************************
  // 配置PE4-PE6,PC13为列输入
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  if (!IOToggle)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  else
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  if (!IOToggle)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  else
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  //**********************************************************************

  //**********************************************************************
  // 配置PE0-PE3为行输出
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  if (!IOToggle) // 推挽输出
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  else
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  //**********************************************************************
}

//-----------------------------------------------------------------
// unsigned char Key_scan (void)
//-----------------------------------------------------------------
//
// 函数功能: 按键扫描
// 入口参数: 无
// 返回参数: 检测到的数据
// 全局变量: 无
// 调用模块:
// 注意事项: 无键按下返回0xff
// 键盘及IO口分配:
//       PE0     -1-  -2-    -3-    -+-
//       PE1     -4-  -5-    -6-    ---
//       PE2     -7-  -8-    -9-    -*-
//       PE3    -Brk-  -0-    -ok-  -/-
//          		PE4    PE5    PE6   PC13
//-----------------------------------------------------------------
#define GPIO_Pin_0to3 ((uint16_t)0x000F) /*!< Pin 0~3 selected */
#define GPIO_Pin_4to6 ((uint16_t)0x0070) /*!< Pin 4~6 selected */

u8 Key_scan(void)
{
  u8 Date_HL = 0,
     Date_h = 0,
     Date_l = 0,
     BitState = 0;
  u16 State = 0;

  GPIO_WriteBit(GPIOE, GPIO_Pin_0to3, Bit_RESET); // 把PE0-PE3清零
  GPIO_WriteBit(GPIOE, GPIO_Pin_4to6, Bit_SET);   // 把PE4-PE6拉高
  GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);     // 把PC13拉高
  delay_ms(2);
  State = GPIO_ReadInputData(GPIOE) & 0x0070;           // 读取PE4-PE6状态
  BitState = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13); // 读取PC13状态

  // 列值不全部为0
  if ((State != 0x0070) || (BitState != 0x01)) // 有键按下
  {
    delay_ms(20);                                        // 延时20mS消抖
    State = GPIO_ReadInputData(GPIOE) & 0x0070;           // 读取PE4-PE6状态
    BitState = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13); // 读取PC13状态

    if ((State != 0x0070) || (BitState != 0x01)) // 确实有键按下
    {
      if (BitState) // 不是PC13列按下
      {
        Date_h = ~(State | 0x80);
        Date_h &= 0xF0;
      }
      else
      {
        Date_h = 0x80; // 第四列按下
      }

      IOToggle = 1; // PE0-PE3由输出改成输入，PE4-PE6由输入改成输出
      GPIO_Keyboard_Configuration();
      GPIO_WriteBit(GPIOE, GPIO_Pin_0to3, Bit_SET);   // 把PE0-PE3拉高
      GPIO_WriteBit(GPIOE, GPIO_Pin_4to6, Bit_RESET); // 把PE4-PE6清零
      GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);   // 把PC13清零
      delay_ms(2);

      State = GPIO_ReadInputData(GPIOE); // 读取PE4-PE6状态
      Date_l = ~(State & 0x000f);
      Date_l &= 0x0F;

      while ((State & 0x000f) != 0x000f)   // 等待按键释放
        State = GPIO_ReadInputData(GPIOE); // 读取PE4-PE6状态
      IOToggle = 0;                        // IO返回原来状态
      GPIO_Keyboard_Configuration();
      Date_HL = (Date_h + Date_l); // 返回行列值
    }
    else
    {
      Date_HL = 0xff;
    }
  }
  else
  {
    Date_HL = 0xff;
  }
  return (Date_HL);
}

//-----------------------------------------------------------------
// u8  KeyTransfer (void)
//-----------------------------------------------------------------
// 函数功能: 按键数值处理
// 入口参数: 无
// 返回参数: 按键处理的数据
// 全局变量: 无
// 注意事项：
//  键盘编码布局：
//       1        2      3         12(+)
//       4        5      6         13(-)
//       7        8      9         14(*)
//      10(取消)  0      11(确认)  15(/)
//
//--------------------------------------------------------------
u8 KeyTransfer(void)
{
  u8 key_4x4_value;
  switch (Key_scan())
  {
  // 按下相应的键显示相对应的码值
  case 0x11:
    key_4x4_value = 1;
    break; // 1
  case 0x21:
    key_4x4_value = 2;
    break; // 2
  case 0x41:
    key_4x4_value = 3;
    break; // 3
  case 0x81:
    key_4x4_value = 12;
    break; // +
  case 0x12:
    key_4x4_value = 4;
    break; // 4
  case 0x22:
    key_4x4_value = 5;
    break; // 5
  case 0x42:
    key_4x4_value = 6;
    break; // 6
  case 0x82:
    key_4x4_value = 13;
    break; // -
  case 0x14:
    key_4x4_value = 7;
    break; // 7
  case 0x24:
    key_4x4_value = 8;
    break; // 8
  case 0x44:
    key_4x4_value = 9;
    break; // 9
  case 0x84:
    key_4x4_value = 14;
    break; // *
  case 0x18:
    key_4x4_value = 10;
    break; // break
  case 0x28:
    key_4x4_value = 0;
    break; // 0
  case 0x48:
    key_4x4_value = 11;
    break; // ok
  case 0x88:
    key_4x4_value = 15;
    break; // /
  default:
    key_4x4_value = 0xff; // other
  }
  return (key_4x4_value);
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
