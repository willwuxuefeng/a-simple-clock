/************************************************************
defign by will 								at Dec.2,2017	sat
Verify the function of the development board
*************************************************************/
#ifndef _beep_H
#define _beep_H

//#include "stm32f10x.h"

#define BEEP_PORT_RCC  	RCC_APB2Periph_GPIOB
#define BEEP_PORT  			GPIOB
#define BEEP  					GPIO_Pin_5

void Beep_Init(void);
void Beep_Fuction_Lib(void);
void Beep_Fuction_bitband(void);

#endif
