#ifndef __FONT_H
#define __FONT_H 	   
//����ASCII��
//ƫ����32 
//ASCII�ַ���: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002ȡģ��ʽ���ã�����+����ʽ+˳��+C51��ʽ
//�ܹ���3���ַ�����12*12��16*16��24*24�����û������������������ֱ��ʵ��ַ�����
//ÿ���ַ���ռ�õ��ֽ���Ϊ:(size/8+((size%8)?1:0))*(size/2),����size:���ֿ�����ʱ�ĵ����С(12/16/24...)
 
//#include "stm32f10x.h"
// ------------------  ������ģ�����ݽṹ���� ------------------------ //
struct  Cn32CharTypeDef                   // ������ģ���ݽṹ 
{
	unsigned char  Index[2];            // ������������,һ������ռ�����ֽ�	
	unsigned char  Msk[116];            // ����������(32*29/8) 
};

extern const unsigned char ascii_1206[95][12];
extern const unsigned char ascii_1608[95][16];
extern const unsigned char ascii_2412[95][36];

extern const struct  Cn32CharTypeDef  CnChar32x29[];


#endif
