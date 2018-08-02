#include "main.h"
u8 issecondflag =0;
//前面板画圆盘函数
void LCD_Draw_DoubleCircle_Color(u16 x0,u16 y0,u8 r1,u8 r2,u16 color){
    u8 r;
    for(r = r1;r < r2;r ++){
        LCD_Draw_Circle_Color(x0,y0,r,color);
    }

}

//表盘刻度和数字
void LCD_Show_ScaleIndexTable(u16 color){
	u8 i;
    u8 stringnum[12][3] = {"12","1","2","3","4","5","6","7","8","9","10","11"};
	printf("the character is: %c \r\n",stringnum[0][2]);
    for(i = 0;i < 60;i ++){
            LCD_DrawLine_Color(CORE_X + BIG_RADIUS * sin(PI / 180 * 6 * i),CORE_Y - BIG_RADIUS * cos(PI / 180 * 6 * i),
                CORE_X + INSIDE_RADIUS * sin(PI / 180 * 6 * i),CORE_Y - INSIDE_RADIUS * cos(PI / 180 * 6 * i),color);
            if(i % 5 == 0){
            LCD_DrawLine_Color(CORE_X + SMALL_RADIUS * sin(PI / 180 * 6 * i),CORE_Y - SMALL_RADIUS * cos(PI / 180 * 6 * i),
                CORE_X + INSIDE_RADIUS * sin(PI / 180 * 6 * i),CORE_Y - INSIDE_RADIUS * cos(PI / 180 * 6 * i),color);
			LCD_ShowString_Color(CORE_X - 3 + VALUE_RADIUS * sin(PI / 180 * 6 * i),CORE_Y - 3 - VALUE_RADIUS * cos(PI / 180 * 6 * i),
                12,12,12,stringnum[i / 5],color,BLACK);
            }
    }
	
}

//显示年月日时分秒
void LCD_Show_Date(u16 color){
    u8 string[19];
    u8 string1[10];
     //将字符串 2018-03-17 17:30:00 这写打印成字符串 ，所以string[19]
    sprintf((char *)string,"%02d-%02d-%02d %02d:%02d:%02d",calendar.w_year,calendar.w_month,calendar.w_day,calendar.hour,calendar.min,calendar.sec );
    LCD_ShowString_Color(DIGITAL_TIME_POSX,DIGITAL_TIME_POSY,8*19,16,16,string,YELLOW,BLACK);//8*19表示这19个字符的宽度
}

//画指针
void LCD_Show_PointerMove(void){
    
    //秒针走动
    LCD_DrawLine_Color(CORE_X + BIG_SECOND_RADIUS * sin(PI / 180 * 6 * calendar.sec),CORE_Y - BIG_SECOND_RADIUS * cos(PI / 180 * 6 * calendar.sec),
            CORE_X - SMALL_SECOND_RADIUS * sin(PI / 180 * 6 * calendar.sec),CORE_Y + SMALL_SECOND_RADIUS * cos(PI / 180 * 6 * calendar.sec),SECOND_COLOR);
    //分针走动
    LCD_DrawLine_Color(CORE_X + BIG_MINUTE_RADIUS * sin(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),CORE_Y - BIG_MINUTE_RADIUS * cos(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),
            CORE_X - SMALL_MINUTE_RADIUS * sin(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),CORE_Y + SMALL_MINUTE_RADIUS * cos(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),MINUTE_COLOR);
    //时针走动
    LCD_DrawLine_Color(CORE_X + BIG_HOUR_RADIUS * sin(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_Y - BIG_HOUR_RADIUS * cos(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_X - SMALL_HOUR_RADIUS * sin(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_Y + SMALL_HOUR_RADIUS * cos(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),HOUR_COLOR);
}

//擦除指针
void LCD_Clear_PointerMove(void){
    //秒针擦除
    LCD_DrawLine_Color(CORE_X + BIG_SECOND_RADIUS * sin(PI / 180 * 6 * calendar.sec),CORE_Y - BIG_SECOND_RADIUS * cos(PI / 180 * 6 * calendar.sec),
            CORE_X - SMALL_SECOND_RADIUS * sin(PI / 180 * 6 * calendar.sec),CORE_Y + SMALL_SECOND_RADIUS * cos(PI / 180 * 6 * calendar.sec),BLACK);
    //分针擦除
    LCD_DrawLine_Color(CORE_X + BIG_MINUTE_RADIUS * sin(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),CORE_Y - BIG_MINUTE_RADIUS * cos(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),
            CORE_X - SMALL_MINUTE_RADIUS * sin(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),CORE_Y + SMALL_MINUTE_RADIUS * cos(PI / 180 * 6 * (calendar.min + (double)calendar.sec / 60)),BLACK);
    //时针擦除
    LCD_DrawLine_Color(CORE_X + BIG_HOUR_RADIUS * sin(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_Y - BIG_HOUR_RADIUS * cos(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_X - SMALL_HOUR_RADIUS * sin(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),
        CORE_Y + SMALL_HOUR_RADIUS * cos(PI / 180 * 30 * (calendar.hour +  (double)calendar.min / 60 +  (double)calendar.sec / 3600)),BLACK);
}