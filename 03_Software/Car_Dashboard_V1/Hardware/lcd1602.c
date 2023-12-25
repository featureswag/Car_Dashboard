/*1602.C文件1602采用四线传输*/
#include "lcd1602.h"
#include "delay.h"
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef	GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); //打开时钟
    //dataIO GPIOA4~7 初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LCD_DATA_PORT, &GPIO_InitStructure);				// RS RW E IO初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}
/* 检测液晶是否繁忙 */
void LCD1602_Wait_Ready(void)
{
    int8_t sta;
    DATAOUT(0xff);    //PA端口全部置1
    LCD_RS_Clr();     //RS 0
    LCD_RW_Set();     //RW 1
    do
    {
        LCD_EN_Set();   //EN 1
        delay_ms(5);	//延时5MS
        sta = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7);//读取状态字
        LCD_EN_Clr();  //EN  0
    }
    while(sta & 0x80); //bit7等于1表示忙,重复检测到其为0停止
}
/*向1602写入一字节命令,cmd-待写入命令 */
//写入指令PA4-7 RS-0  RW-0
void LCD1602_Write_Cmd(u8 cmd)
{
    LCD1602_Wait_Ready();  //判断忙不忙
    LCD_RS_Clr();
    LCD_RW_Clr();
    DATAOUT(cmd);  //先传高四位
    LCD_EN_Set();
    LCD_EN_Clr();
    DATAOUT(cmd << 4); //低四位左移到高四位
    LCD_EN_Set();
    LCD_EN_Clr();
}
/* 向1602写入一字节数据*/
void LCD1602_Write_Dat(u8 dat)
{
    LCD1602_Wait_Ready(); //判断忙不忙
    LCD_RS_Set();   //1
    LCD_RW_Clr();   //0
    DATAOUT(dat);   //先传高四位
    LCD_EN_Set();
    LCD_EN_Clr();
    DATAOUT(dat << 4); //低四位左移到高四位
    LCD_EN_Set();
    LCD_EN_Clr();
}
/*清屏*/
void LCD1602_ClearScreen(void)
{
    LCD1602_Write_Cmd(0x01);   /* 设置RAM其实地址,即光标位置,（X,Y）对应屏幕上的字符坐标 */
}
void LCD1602_Set_Cursor(u8 x, u8 y)
{
    u8 addr;
    if (y == 0)addr = 0x00 + x;
    else addr = 0x40 + x;
    LCD1602_Write_Cmd(addr | 0x80);
	LCD1602_Write_Cmd(addr | 0x80);
}
/* 在液晶上显示字符串,（X,Y）-对应屏幕上的其实坐标，str-字符串指针 */
void LCD1602_Show_Str(u8 x, u8 y, u8 *str)
{
    LCD1602_Set_Cursor(x, y);
    while(*str != '\0')
    {
        LCD1602_Write_Dat(*str++);
    }	
}
void LCD1602_write_figer(unsigned char y_add , unsigned char x_add , u32 figer, unsigned int len)//在任何位置写数字-数组
{
    unsigned char d[7],i,j;
    
	LCD1602_Set_Cursor(y_add , x_add);
	
    d[6]=figer%10;
    d[5]=figer%100/10;
    d[4]=figer%1000/100;
    d[3]=figer%10000/1000;
	d[2]=figer%100000/10000;
	d[1]=figer%1000000/100000;
    d[0]=figer/10000000;
    for(i=7-len;i<7;i++)
    {
        if(d[i]!=0)break;
    }

    //if(i==5)i--;
	
	
	for(j=7-len;j<i;j++)
	{
		LCD1602_Write_Dat(0x30);//数据装完，准备发送
	}
    for(j=i;j<7;j++)
    {
       LCD1602_Write_Dat(d[j]|0x30);//取得的数字加上0x30也即得到该数字的ASCII码，再将该数字发送去显示
    }
}
/* 初始化液晶 */
void LCD1602_Init(void)
{
	GPIO_Configuration();
    LCD1602_Write_Cmd(0x28);	//16*2显示，5*7点阵，4位数据口
	delay_ms(2); 
	LCD1602_Write_Cmd(0x0C);	//开显示，光标关闭
	delay_ms(2); 
	LCD1602_Write_Cmd(0x06);	//文字不动，地址自动+1
	delay_ms(2); 
	LCD1602_Write_Cmd(0x01);	//清屏
	delay_ms(2); 
}
