/************************************************************************************
	changed by will                      Dec.14,2017 THU
	to verify the functionality of the development board

*************************************************************************************/
#include "main.h"

void Smg_Init(){
    GPIO_InitTypeDef GPIO_InitStructure;//declaration
    
    RCC_APB2PeriphClockCmd(SMG_PORT_RCC,ENABLE);
    GPIO_InitStructure.GPIO_Pin = SMG_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(SMG_PORT,&GPIO_InitStructure);
    GPIO_Write(SMG_PORT,0XFF);//初始化smg的管脚，都为1.
	
}

void Smg_Display(){
    u8 i;
    u8 smg_duan[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
    for(i=0;i<16;i++){
        GPIO_Write(GPIOC,(u16)(smg_duan[i]));
        Delay_ms(1000);
        }
		if(i == 16)
				GPIO_Write(SMG_PORT,0XFF);//swith off the SMG
    }


