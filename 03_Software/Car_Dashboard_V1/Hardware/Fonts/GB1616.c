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
{ 0x10, 0x40, 0x10, 0x20, 0x10, 0x20, 0x11, 0xFE, 0xFC, 0x00, 0x10, 0x88, 0x31, 0x04, 0x3A, 0x02, 
  0x54, 0x88, 0x50, 0x88, 0x90, 0x50, 0x10, 0x50, 0x10, 0x20, 0x10, 0x50, 0x10, 0x88, 0x13, 0x06 }, /*"校",1*/

};




sFONT_CN Font16_CN = {
  codeGB_16,
  16, /* Width */
  16, /* Height */
  sizeof(codeGB_16) / sizeof(codeGB_16[0])
};


#endif 

