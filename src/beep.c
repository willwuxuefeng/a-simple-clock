#include "main.h"

void Beep_Init(){
	/*注意结构体的声明应该放在函数的前面*/
	GPIO_InitTypeDef GPIO_Initstructure;//声明一个结构体变量，用来初始化GPIO,
	SystemInit();  /*初始化系统时钟*/
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE);//打开GPIOC的时钟
	
	GPIO_Initstructure.GPIO_Pin = BEEP;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
    
    } 

void Beep_Fuction_Lib(){
	
    GPIO_SetBits(BEEP_PORT,BEEP);
    //Delay1(10000);
    GPIO_ResetBits(BEEP_PORT,BEEP);
    //Delay1(10000);
	
	
}

void Beep_Fuction_bitband(){
	PB_OUT(5) = 1;
	Delay_us(10);
	PB_OUT(5) = 0;
	Delay_us(1990);
}
