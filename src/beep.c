#include "main.h"

void Beep_Init(){
	/*ע��ṹ�������Ӧ�÷��ں�����ǰ��*/
	GPIO_InitTypeDef GPIO_Initstructure;//����һ���ṹ�������������ʼ��GPIO,
	SystemInit();  /*��ʼ��ϵͳʱ��*/
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE);//��GPIOC��ʱ��
	
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
