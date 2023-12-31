// 
///*预定义汉字点阵数据文件*/
//
///*------------------------------------------------------------------------------
#ifndef __GB1616_H
#define __GB1616_H

#include "fonts.h"


/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 取模软件：   纵向取模 -> PCtoLCD2002完美版：逐行式                         //
/////////////////////////////////////////////////////////////////////////
const struct  typFNT_GBxx codeGB_16[] =          // 数据表 
{
{"油",0x00,0x40,0x20,0x40,0x10,0x40,0x10,0x40,0x87,0xFC,0x44,0x44,0x44,0x44,0x14,0x44,
			0x14,0x44,0x27,0xFC,0xE4,0x44,0x24,0x44,0x24,0x44,0x24,0x44,0x27,0xFC,0x04,0x04},/*"油",0*/

{"量",0x00,0x00,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0xFF,0xFE,0x00,0x00,0x1F,0xF0,
			0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,0x01,0x00,0x1F,0xF0,0x01,0x00,0x7F,0xFC},/*"量",1*/

{"剩",0x07,0x02,0x78,0x02,0x08,0x02,0xFF,0x82,0x2A,0x12,0x2A,0x92,0xEB,0x12,0x2A,0x92,
			0x6A,0x92,0xA9,0x92,0x1C,0x12,0x2A,0x12,0x49,0x02,0x88,0x82,0x08,0x0A,0x08,0x04},/*"剩",2*/

{"余",0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x10,0x10,0x2F,0xE8,0xC1,0x06,
			0x01,0x00,0x3F,0xF8,0x01,0x00,0x11,0x10,0x11,0x08,0x21,0x04,0x45,0x04,0x02,0x00},/*"余",3*/
};


sFONT_CN Font16_CN = {
  codeGB_16,
  16, /* Width */
  16, /* Height */
  sizeof(codeGB_16) / sizeof(codeGB_16[0])
};


#endif 

