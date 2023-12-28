// 
///*Ԥ���庺�ֵ��������ļ�*/
//
///*------------------------------------------------------------------------------
#ifndef __GB1616_H
#define __GB1616_H

#include "fonts.h"


/////////////////////////////////////////////////////////////////////////
// ������ģ��                                                          //
// ȡģ������   ����ȡģ -> PCtoLCD2002�����棺����ʽ                         //
/////////////////////////////////////////////////////////////////////////
const struct  typFNT_GBxx codeGB_16[] =          // ���ݱ� 
{
{"��",0x01,0x00,0x21,0x08,0x11,0x08,0x09,0x10,0x09,0x20,0x01,0x00,0x7F,0xF8,0x00,0x08,
0x00,0x08,0x00,0x08,0x3F,0xF8,0x00,0x08,0x00,0x08,0x00,0x08,0x7F,0xF8,0x00,0x08},/*"��",0*/

{"ǰ",0x10,0x10,0x08,0x10,0x08,0x20,0xFF,0xFE,0x00,0x00,0x3E,0x08,0x22,0x48,0x22,0x48,
0x3E,0x48,0x22,0x48,0x22,0x48,0x3E,0x48,0x22,0x08,0x22,0x08,0x2A,0x28,0x24,0x10},/*"ǰ",1*/

{"��",0x00,0x40,0x20,0x40,0x10,0x40,0x10,0x40,0x87,0xFC,0x44,0x44,0x44,0x44,0x14,0x44,
0x14,0x44,0x27,0xFC,0xE4,0x44,0x24,0x44,0x24,0x44,0x24,0x44,0x27,0xFC,0x04,0x04},/*"��",2*/

{"��",0x00,0x00,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0xFF,0xFE,0x00,0x00,0x1F,0xF0,
0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,0x01,0x00,0x1F,0xF0,0x01,0x00,0x7F,0xFC},/*"��",3*/

{"��",0x00,0x40,0x20,0x40,0x17,0xFC,0x10,0x40,0x03,0xF8,0x02,0x48,0xF2,0x48,0x13,0xF8,
0x10,0xE0,0x11,0x50,0x12,0x48,0x14,0x44,0x10,0x40,0x28,0x00,0x47,0xFE,0x00,0x00},/*"��",4*/

{"��",0x01,0x00,0x00,0x80,0x3F,0xFE,0x22,0x20,0x22,0x20,0x3F,0xFC,0x22,0x20,0x22,0x20,
0x23,0xE0,0x20,0x00,0x2F,0xF0,0x24,0x10,0x42,0x20,0x41,0xC0,0x86,0x30,0x38,0x0E},/*"��",5*/

{"��",0x00,0x00,0x3F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x20,0x10,0x20,0x10,0x3F,0xF0,
0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x04,0x20,0x04,0x20,0x04,0x1F,0xFC,0x00,0x00},/*"��",6*/

{"��",0x08,0x00,0x09,0xFC,0x10,0x00,0x20,0x00,0x48,0x00,0x08,0x00,0x13,0xFE,0x30,0x20,
0x50,0x20,0x90,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0xA0,0x10,0x40},/*"��",7*/

{"ʻ",0x00,0x20,0xF8,0x20,0x08,0x20,0x49,0xFC,0x49,0x24,0x49,0x24,0x49,0x24,0x7D,0x24,
0x05,0xFC,0x04,0x20,0x1C,0xA0,0xE4,0x60,0x44,0x60,0x04,0x90,0x29,0x08,0x12,0x06},/*"ʻ",8*/

{"��",0x00,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,
0x01,0x00,0x01,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x00,0x00},/*"��",9*/

{"��",0x08,0x00,0x1D,0xFC,0xF1,0x04,0x11,0x04,0x11,0x04,0xFD,0xFC,0x10,0x00,0x30,0x00,
0x39,0xFE,0x54,0x20,0x54,0x20,0x91,0xFC,0x10,0x20,0x10,0x20,0x13,0xFE,0x10,0x00},/*"��",10*/

{"��",0x08,0x20,0x49,0x20,0x2A,0x20,0x08,0x3E,0xFF,0x44,0x2A,0x44,0x49,0x44,0x88,0xA4,
0x10,0x28,0xFE,0x28,0x22,0x10,0x42,0x10,0x64,0x28,0x18,0x28,0x34,0x44,0xC2,0x82},/*"��",11*/

{"��",0x01,0x00,0x21,0x00,0x11,0xFC,0x12,0x00,0x84,0x00,0x41,0xF8,0x48,0x00,0x08,0x00,
0x13,0xF8,0x10,0x08,0xE0,0x08,0x20,0x08,0x20,0x0A,0x20,0x0A,0x20,0x06,0x00,0x02},/*"��",12*/
	
{"��",0x02,0x00,0x02,0x00,0x02,0x00,0x7F,0xFC,0x04,0x00,0x09,0x00,0x11,0x00,0x21,0x00,
0x3F,0xF8,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00},/*"��",13*/
	
{"��",0x08,0x80,0x08,0x48,0x0A,0x48,0x12,0x08,0x12,0x08,0x31,0x10,0x31,0x10,0x51,0x10,
0x90,0xA0,0x10,0xA0,0x10,0x40,0x10,0x40,0x10,0xA0,0x11,0x10,0x12,0x08,0x14,0x06},/*"��",14*/
	
{"��",0x01,0x00,0x01,0x00,0x7F,0xFC,0x01,0x00,0x01,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,
0xFF,0xFE,0x05,0x00,0x08,0x88,0x18,0x50,0x28,0x20,0xC9,0x18,0x0A,0x06,0x0C,0x00},/*"��",15*/
	
{"��",0x02,0x00,0x04,0x00,0x1F,0xF0,0x11,0x10,0x10,0x90,0xFF,0xFE,0x10,0x10,0x12,0x10,
0x21,0x50,0x40,0x20,0x3F,0xF8,0x24,0x48,0x24,0x48,0x24,0x48,0xFF,0xFE,0x00,0x00},/*"��",16*/

{"ʣ",0x07,0x02,0x78,0x02,0x08,0x02,0xFF,0x82,0x2A,0x12,0x2A,0x92,0xEB,0x12,0x2A,0x92,
0x6A,0x92,0xA9,0x92,0x1C,0x12,0x2A,0x12,0x49,0x02,0x88,0x82,0x08,0x0A,0x08,0x04},/*"ʣ",17*/
	
{"��",0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x10,0x10,0x2F,0xE8,0xC1,0x06,
0x01,0x00,0x3F,0xF8,0x01,0x00,0x11,0x10,0x11,0x08,0x21,0x04,0x45,0x04,0x02,0x00},/*"��",18*/
};


sFONT_CN Font16_CN = {
  codeGB_16,
  16, /* Width */
  16, /* Height */
  sizeof(codeGB_16) / sizeof(codeGB_16[0])
};


#endif 
