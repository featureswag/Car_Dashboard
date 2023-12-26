#ifndef __LCD1602_H
#define __LCD1602_H

//----------------------------------------------------------------
// IO口操作
//-----------------------------------------------------------------
#define LCM_RS_set (GPIO_SetBits(GPIOD, GPIO_Pin_0))
#define LCM_RS_clr (GPIO_ResetBits(GPIOD, GPIO_Pin_0))
#define LCM_RW_set (GPIO_SetBits(GPIOD, GPIO_Pin_1))
#define LCM_RW_clr (GPIO_ResetBits(GPIOD, GPIO_Pin_1))
#define LCM_E_set  (GPIO_SetBits(GPIOD, GPIO_Pin_2))
#define LCM_E_clr  (GPIO_ResetBits(GPIOD, GPIO_Pin_2))

//-----------------------------------------------------------------
// 外部函数声明
//-----------------------------------------------------------------
extern void GPIO_LCM_Configuration(void);
extern void LCM_Init(void);                 // LCM初始化,使用时根据需要选择
extern void WrCLcdC(u8 lcdcomm);            // 写LCM的指令代码
extern void WrCLcdD(u8 lcddata);            // 写LCM要显示的数据
extern void WriteString(u8 x, u8 y, u8 *s); // 指定位置显示一串字符串
extern void CG_Write(void);                 // 将自定义的字符送到CGRAM
extern void Wr_CodeData(void);              // 写操作共同部分程序
// 显示十进制无符号字符数据
extern void WrCLcd_char_num(u8 x, u8 y, u8 num);
// 显示十进制无符号整形数据
extern void WrCLcd_int_num(u8 x, u8 y, u16 num);
// 显示十进制无符号长整形数据
extern void WrCLcd_long_num(u8 x, u8 y, unsigned long num);
extern void Wr_In1(void);   // 第一行显示
extern void Wr_In2(void);   // 第二行显示
extern void CL_Enter(void); // 第一行光标左移显示
extern void CR_Enter(void); // 第二行光标右移显示
extern void L_Enter(void);  // 第一行画面左移显示
extern void R_Enter(void);  // 第二行画面右移显示
extern void CGWrite(void);  // 显示产品信息

#endif

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
