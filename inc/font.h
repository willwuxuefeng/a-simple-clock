#ifndef __FONT_H
#define __FONT_H 	   
//常用ASCII表
//偏移量32 
//ASCII字符集: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002取模方式设置：阴码+逐列式+顺向+C51格式
//总共：3个字符集（12*12、16*16和24*24），用户可以自行新增其他分辨率的字符集。
//每个字符所占用的字节数为:(size/8+((size%8)?1:0))*(size/2),其中size:是字库生成时的点阵大小(12/16/24...)
 
//#include "stm32f10x.h"
// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  Cn32CharTypeDef                   // 汉字字模数据结构 
{
	unsigned char  Index[2];            // 汉字内码索引,一个汉字占两个字节	
	unsigned char  Msk[116];            // 点阵码数据(32*29/8) 
};

extern const unsigned char ascii_1206[95][12];
extern const unsigned char ascii_1608[95][16];
extern const unsigned char ascii_2412[95][36];

extern const struct  Cn32CharTypeDef  CnChar32x29[];


#endif
