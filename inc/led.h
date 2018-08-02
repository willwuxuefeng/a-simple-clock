#ifndef _led_H
#define _led_H

//#include "stm32f10x.h"

#define LED 									GPIO_Pin_All //all pin in the port
#define LED_PORT_RCC							RCC_APB2Periph_GPIOC //clock of led
#define LED_PORT 								GPIOC //port of led
									

void Led_Init(void);
void Delay0(u32 i);
void Led_Display_Lib(void);
void Led_Display_Bitband(void);

#endif
