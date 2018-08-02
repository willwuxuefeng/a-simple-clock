#include "main.h"

void Key_Init(void){
	/*注意结构体的声明应该放在函数的前面*/
	GPIO_InitTypeDef GPIO_Initstructure;//声明一个结构体变量，用来初始化GPIO,
    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//打开时钟
	/*初始化K_UP按键*/
	GPIO_Initstructure.GPIO_Pin = K_UP;
	//GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;//输入下拉
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	/*初始化GPIOE上另外的三个按键*/
	GPIO_Initstructure.GPIO_Pin = K_DOWN|K_LEFT|K_RIGHT;
	//GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;//输入上拉
	GPIO_Init(GPIOE,&GPIO_Initstructure);
	
	/*初始化四个按键的初始值，确保判断按下的条件是按键按下才产生的动作*/
	GPIO_ResetBits(GPIOA,K_UP);//置0
	GPIO_SetBits(GPIOE,K_DOWN|K_LEFT|K_RIGHT);//置1
	
    }

void Key_Detection(){
    Led_Init();
		while(1){	//continuous scan ,so use while loop.
			if(k_up==1)
					Delay_ms(10);
					if(k_up==1)
							GPIO_Write(LED_PORT,0Xfe);
							while(k_up);//等待按键抬起		
			if(k_down==0)
					Delay_ms(10);
					if(k_down==0)
							GPIO_Write(LED_PORT,0Xfd);
							while(!(k_down))//等待按键抬起
			if(k_left==0)
					Delay_ms(10);
					if(k_left==0)
							GPIO_Write(LED_PORT,0Xfb);
							while(!(k_left));//等待按键抬起
			if(k_right==0)
					Delay_ms(10);
					if(k_right==0)
							GPIO_Write(LED_PORT,0Xf7);
							while(!(k_right));//等待按键抬起
				}
   
    }
