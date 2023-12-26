#ifndef __GB2424_H
#define __GB2424_H

#include "fonts.h"

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 取模软件：   PCtoLCD2002完美版：逐行式						  //
/////////////////////////////////////////////////////////////////////////
const struct  typFNT_GBxx codeGB_24[] =          // 数据表 
{
{				0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x30, 0x02, 0x30, 0x18, 
        0x7F, 0xF8, 0x1A, 0x02, 0x00, 0x0A, 0x02, 0x00, 0x02, 0x02, 0x0C, 0x05, 0xFD, 0xF0, 0x04, 0x38, 
        0x60, 0x04, 0x68, 0x38, 0x08, 0xCC, 0x0C, 0x09, 0x18, 0x44, 0x0A, 0x1F, 0xE0, 0x38, 0x30, 0xC0, 
        0x10, 0x48, 0x80, 0x10, 0x85, 0x00, 0x11, 0x07, 0x00, 0x30, 0x07, 0x00, 0x10, 0x09, 0x80, 0x00, 
        0x30, 0x78, 0x03, 0xC0, 0x1C, 0x00, 0x00, 0x00 },   /*"凌",0*/
//{"智",  0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x12, 0x08, 0x0F, 0xFB, 0xFC, 0x08,
//        0x82, 0x08, 0x11, 0x82, 0x08, 0x01, 0x9A, 0x08, 0x3F, 0xFE, 0x08, 0x01, 0x82, 0x08, 0x03, 0x63,
//        0xF8, 0x02, 0x32, 0x08, 0x04, 0x1A, 0x00, 0x08, 0x00, 0x00, 0x31, 0xFF, 0xE0, 0x01, 0x00, 0x40,
//        0x01, 0x00, 0x40, 0x01, 0x00, 0x40, 0x01, 0xFF, 0xC0, 0x01, 0x00, 0x40, 0x01, 0x00, 0x40, 0x01,
//        0xFF, 0xE0, 0x01, 0x00, 0x60, 0x00, 0x00, 0x00 },   /*"智",1*/
//{"电",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00,
//        0x10, 0x00, 0x0F, 0xFF, 0xF0, 0x08, 0x10, 0x20, 0x08, 0x10, 0x20, 0x08, 0x10, 0x20, 0x08, 0x10,
//        0x20, 0x0F, 0xFF, 0xE0, 0x08, 0x10, 0x20, 0x08, 0x10, 0x20, 0x08, 0x10, 0x20, 0x08, 0x10, 0x20,
//        0x0F, 0xFF, 0xE0, 0x08, 0x10, 0x00, 0x00, 0x10, 0x08, 0x00, 0x10, 0x08, 0x00, 0x10, 0x04, 0x00,
//        0x18, 0x0C, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00 },   /*"电",2*/
//{"子",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0F, 0xFF, 0xF0, 0x00, 0x00, 0x60, 0x00,
//        0x00, 0x80, 0x00, 0x03, 0x00, 0x00, 0x14, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18,
//        0x0C, 0x7F, 0xFF, 0xFE, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00,
//        0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00,
//        0xF8, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00 },   /*"子",3*/

} ;


sFONT_CN Font24_CN = {
  codeGB_24,
  24, /* Width */
  24, /* Height */
  sizeof(codeGB_24) / sizeof(codeGB_24[0])
};

#endif
