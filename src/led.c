/************************************************************************************
	changed by will                      Dec.2,2017 sat
	to verify the functionality of the development board

*************************************************************************************/
#include "main.h"

void Led_Init(){
	/*ע��ṹ�������Ӧ�÷��ں�����ǰ��*/
	GPIO_InitTypeDef GPIO_Initstructure;//����һ���ṹ�������������ʼ��GPIO,
	
	RCC_APB2PeriphClockCmd(LED_PORT_RCC,ENABLE);//��GPIOC��ʱ��
	
	GPIO_Initstructure.GPIO_Pin = LED;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORT,&GPIO_Initstructure);
	GPIO_Write(LED_PORT,(u16)0xff);  //���е�led��ʼ��ʱȫ���رա�
    }

void Delay0(u32 i) {
    while(i--);
    }
 /*
@brief  fuction is realized by calling the library
*/	
void Led_Display_Lib(){
    while(1){
        GPIO_SetBits(LED_PORT,LED);
        Delay_ms(1000);//note the scope of systicks
		/*��ʱ�Ĳ��淶д��
		Delay_ms(1000);
		Delay_ms(1000);
		Delay_ms(1000);
        Delay0(6000000);//��ʱԼ1s
		*/
        GPIO_ResetBits(LED_PORT,LED);
        Delay_ms(1000);
		/*��ʱ�Ĳ��淶д��
		Delay_ms(1000);
		Delay_ms(1000);
		Delay_ms(1000);
        Delay0(6000000);//��ʱԼ1s
		*/
        }
		//GPIO_ReadOutputDataBit()
    }

/*
@brief  fuction is realized by the bitband
*/	
void Led_Display_Bitband(){
    while(1){
        PC_OUT(0) = 1; //Control output of PA_0 to be 1
        Delay_ms(1000);//note the scope of systicks
		PC_OUT(0) = 0; //Control output OF PA_0 to be 0
        Delay_ms(1000);
        }
   
    }

