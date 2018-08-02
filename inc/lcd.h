#ifndef _lcd_H
	#define _lcd_H	
	#define TFTLCD_R61509V
	//TFTLCD struct
	typedef struct
	{
		u16 LCD_CMD; //0111 1111 1110 //A10 == 0
		u16 LCD_DATA;//1000 0000 0000 //A10 == 1
	}TFTLCD_TypeDef;

	//
	#define TFTLCD_BASE        ((u32)(0x6C000000 | 0x000007FE))  //0111 1111 1110 //A10Ϊ0
	#define TFTLCD             ((TFTLCD_TypeDef *) TFTLCD_BASE)  //wxf,ָ���ṹ��ĵ�ַ
  
	//TFTLCD��Ҫ������
	typedef struct  
	{										    
		u16 width;			//LCD ���
		u16 height;			//LCD �߶�
		u16 id;				//LCD ID
		u8  dir;            //LCD ������Ǻ���
	}_tftlcd_data;

	extern _tftlcd_data tftlcd_data;	//ȫ�ֱ���

	extern u16  FRONT_COLOR;//ǰ��ɫ���������Ǻ궨�� 
	extern u16  BACK_COLOR; //����ɫ
	

	//������ɫ
	#define WHITE         	 0xFFFF
	#define BLACK         	 0x0000	  
	#define BLUE         	 0x001F  
	#define BRED             0XF81F
	#define GRED 			 0XFFE0
	#define GBLUE			 0X07FF
	#define RED           	 0xF800
	#define MAGENTA       	 0xF81F
	#define GREEN         	 0x07E0
	#define CYAN          	 0x7FFF
	#define YELLOW        	 0xFFE0
	#define BROWN 			 0XBC40 //��ɫ
	#define BRRED 			 0XFC07 //
	#define GRAY  			 0X8430 //��ɫ

	void LCD_WriteCmd(u16 cmd);
	void LCD_WriteData(u16 data);
	void LCD_WriteCmdData(u16 cmd,u16 data);
	void LCD_WriteData_Color(u16 color);
 
	void TFTLCD_Init(void);           //��ʼ��

	//��������
	void LCD_Set_Window(u16 sx,u16 sy,u16 width,u16 height);
	void LCD_Clear(u16 Color);//����
	void LCD_Fill(u16 xState,u16 yState,u16 xEnd,u16 yEnd,u16 color);
	void LCD_DrawPoint(u16 x,u16 y);//����
	void LCD_DrawPoint_Color(u16 x,u16 y,u16 color);
	u16 LCD_ReadPoint(u16 x,u16 y);
	void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
	void LCD_DrawLine_Color(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
	void LCD_DrowSign(u16 x, u16 y, u16 color);
	void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);
	void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);
	void LCD_Draw_Circle_Color(u16 x0,u16 y0,u8 r,u16 color);
	

	//��ʾ�ַ�����
	void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);
	void LCD_ShowChar_Color(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 frontcolor,u16 backcolor);
	u32 LCD_Pow(u8 m,u8 n);
	void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);
	void LCD_ShowNum_Color(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode,u16 frontcolor,u16 backcolor);
	void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);
	void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);
	void LCD_ShowString_Color(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p,u16 frontcolor,u16 backcolor);
	void LCD_ShowFontHZ(u16 x, u16 y, u8 *cn);					   						   																			
	void LCD_ShowPicture(u16 x, u16 y, u16 wide, u16 high,u8 *pic);
	void LCD_ShowTime(void);

#endif  
	 
	 



