#ifndef __GB2424_H
#define __GB2424_H

#include "fonts.h"

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 取模软件：   PCtoLCD2002完美版：逐行式						  //
/////////////////////////////////////////////////////////////////////////
const struct  typFNT_GBxx codeGB_24[] =          // 数据表 
{
{"油",	0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x03,0x00,0x0C,0x03,0x00,0x06,0x03,0x00,0x00,
		0x03,0x00,0x00,0xFF,0xF8,0x40,0xE3,0x18,0x31,0x63,0x18,0x19,0x63,0x18,0x19,0x63,
		0x18,0x02,0x63,0x18,0x02,0x63,0x18,0x04,0x7F,0xF8,0x04,0x63,0x18,0x04,0x63,0x18,
		0x0C,0x63,0x18,0x38,0x63,0x18,0x08,0x63,0x18,0x08,0x63,0x18,0x18,0x7F,0xF8,0x18,
		0x60,0x18,0x18,0x60,0x10,0x00,0x00,0x00},/*"油",0*/
{"量",	0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xC0,0x06,0x00,0x40,0x07,0xFF,0xC0,0x06,
		0x00,0x40,0x06,0x00,0x40,0x07,0xFF,0xC0,0x06,0x00,0x44,0x7F,0xFF,0xFE,0x00,0x00,
		0x00,0x07,0xFF,0xE0,0x04,0x18,0x60,0x07,0xFF,0xE0,0x04,0x18,0x60,0x04,0x18,0x60,
		0x07,0xFF,0xE0,0x04,0x18,0x60,0x1F,0xFF,0xF0,0x00,0x18,0x00,0x00,0x18,0x04,0x7F,
		0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00},/*"量",1*/
{"速",	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x18,0x02,0x08,0x0D,
		0xFF,0xFC,0x0C,0x02,0x00,0x00,0x02,0x00,0x00,0x7F,0xF8,0x00,0x62,0x10,0x7E,0x62,
		0x10,0x04,0x62,0x10,0x04,0x7F,0xF0,0x04,0x66,0x10,0x04,0x0E,0x00,0x04,0x0B,0xC0,
		0x04,0x12,0x70,0x04,0x22,0x18,0x04,0xC2,0x08,0x1B,0x02,0x00,0x31,0x02,0x00,0x20,
		0xF0,0x1E,0x00,0x1F,0xF8,0x00,0x00,0x00},/*"速",2*/
{"度",	0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x0C,0x00,0x00,0x0C,0x08,0x0F,0xFF,0xFC,0x08,
		0x40,0x80,0x08,0x20,0xC0,0x08,0x20,0x88,0x0F,0xFF,0xFC,0x08,0x20,0x80,0x08,0x20,
		0x80,0x08,0x3F,0x80,0x08,0x20,0x80,0x08,0x00,0x00,0x19,0xFF,0xE0,0x18,0x20,0x40,
		0x10,0x20,0x80,0x10,0x11,0x00,0x10,0x0A,0x00,0x20,0x0E,0x00,0x20,0x31,0xC0,0x40,
		0xC0,0x7E,0x07,0x00,0x08,0x00,0x00,0x00},/*"度",3*/
} ;


sFONT_CN Font24_CN = {
  codeGB_24,
  24, /* Width */
  24, /* Height */
  sizeof(codeGB_24) / sizeof(codeGB_24[0])
};

#endif