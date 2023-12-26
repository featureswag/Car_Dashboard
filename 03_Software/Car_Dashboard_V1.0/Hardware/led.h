#ifndef __LED_H
#define __LED_H

void LED_Init(void);   // this fuction is used to initialize the LED 
void LED_On_1(void);   // this fuction is used to turn on  the LED_1 
void LED_On_2(void);   // this fuction is used to turn on  the LED_2 
void LED_Off_1(void);  // this fuction is used to turn off the LED_1 
void LED_Off_2(void);  // this fuction is used to turn off the LED_2 
void LED_Switch(uint8_t LED, uint8_t Mode);
void LED_Reverse_1(void);
void LED_Reverse_2(void);
#endif
