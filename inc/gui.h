#ifndef _GUI_H
    #define _GUI_H
    #include "stm32f10x.h"
    #define  PI 			             3.141592653
    #define  CORE_X                      120
    #define  CORE_Y                      230
    #define  AXIS_RADIUS                 8//转轴半径
    #define  OUTSIDE_RADIUS              110
    #define  INSIDE_RADIUS               100
    #define  BIG_RADIUS                  90//显示短的刻度用
    #define	 SMALL_RADIUS                85//显示长的刻度用
    #define  VALUE_RADIUS	             80 //显示数字的使用的半径
    #define	 HOUR_RADIUS                 20
    #define  MINUTE_RADIUS               40
    #define  SECONDE_RADIUS              60
    #define  DIGITAL_TIME_POSX           40//数字时间的X起始坐标
    #define  DIGITAL_TIME_POSY           50//数字时间的Y起始坐标
    //秒针
    #define  BIG_SECOND_RADIUS           90
    #define  SMALL_SECOND_RADIUS         20
    #define  SECOND_COLOR                RED
    //分针
    #define  BIG_MINUTE_RADIUS           60
    #define  SMALL_MINUTE_RADIUS         15
    #define  MINUTE_COLOR                BLUE
    //时针
    #define  BIG_HOUR_RADIUS             40
    #define  SMALL_HOUR_RADIUS           10
    #define  HOUR_COLOR                  GREEN
    extern u8 issecondflag;
    void LCD_Draw_DoubleCircle_Color(u16 x0,u16 y0,u8 r1,u8 r2,u16 color);//圆盘
	void LCD_Show_ScaleIndexTable(u16 color);
    void LCD_Show_Date(u16 color);
	void LCD_Show_PointerMove(void);
    void LCD_Clear_PointerMove(void);
    
#endif