
#ifndef __KEYPAD_H
#define __KEYPAD_H

//-----------------------------------------------------------------
// 函数声明
//-----------------------------------------------------------------
extern u8 Key_scan(void);    // 按键扫描, 返回键盘按下位置
extern u8 KeyTransfer(void); // 译码输出
extern void GPIO_Keyboard_Configuration(void);

#endif

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------