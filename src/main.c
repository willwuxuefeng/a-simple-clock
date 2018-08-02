#include "main.h"
int main(){
	

	RCC_HSE_Config(RCC_PLLSource_HSE_Div2, RCC_PLLMul_9);//set the System clock period to be 8/2*4 = 36MHZ
	Usart3_232_Printf_Init(115200);
	TFTLCD_Init();
	LCD_Clear(BLACK);
	
	LCD_ShowString_Color(10,10,24*19,24,24,"THIS IS A RTC CLOCK",RED,BLACK);
	LCD_ShowString_Color(150,360,12*14,24,12,"Design by will",BLUE,BLACK);
	LCD_ShowString_Color(170,375,12*10,24,12,"2018.07.15",BLUE,BLACK);
	
	
	RTC_Init(); 
	
	while(1){
		LCD_Show_Date(YELLOW);
		if(issecondflag != 0){
			issecondflag = 0;
			LCD_Clear_PointerMove();
			RTC_Get();//获得当前时间
			LCD_Show_Date(YELLOW);
			LCD_Draw_Circle_Color(CORE_X,CORE_Y,AXIS_RADIUS,RED);//内部的转针的公共轴
			LCD_Show_PointerMove();
		}
		LCD_Show_ScaleIndexTable(YELLOW);
		//画边框
		LCD_Draw_DoubleCircle_Color(CORE_X,CORE_Y,INSIDE_RADIUS,OUTSIDE_RADIUS,YELLOW);
		LCD_Draw_Circle_Color(CORE_X,CORE_Y,OUTSIDE_RADIUS + 8,RED);
		LCD_Draw_Circle_Color(CORE_X,CORE_Y,AXIS_RADIUS,RED);//内部的转针的公共轴
	
	}  
}

