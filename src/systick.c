/******************************************************************************
Changed by will  Dec.3,2017              
Caution:
1. External clock is 8M and the internal clock is 72M
2. the counter is 24bit ,not 32bit ,so the max value of counter is 2^24=16777216s ,
	 when calculate the ms 900*i should less than 16777216s,than also means that 
	 the max of i ms is 18641.
*******************************************************************************/

#include "main.h"

void Delay_us(u32 i){
  u32 temp;
	//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); this is the librsry function ,i will operate the reg directly
	SysTick->CTRL = 0X01;//Set to the peripheral clock 72M/8,and enable the counter;
	SysTick->LOAD = 9*i;//9 clolck means 1us
  SysTick->VAL = 0;//set val to be 0, the load value will be reload;
	do
	{
	temp = SysTick->CTRL;//wait for the flag,when the value decrease to zer0,the flag will to set to 1;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));//make sure that the counter is enable and the flag is 1
	SysTick->CTRL = 0;//stop the counter and reset the flag;
	SysTick->VAL = 0;//reset the val
			
	}
	
    
void Delay_ms(u32 i){
	u32 temp;
	SysTick->CTRL = 0X01;//Set to the peripheral clock 72M/8,and enable the counter;
	SysTick->LOAD = 9000*i;//900 clock means 1ms
	
	SysTick->VAL = 0;//set val to be 0, the load value will be reload;
	do{
	temp = SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16)))) ;//make sure that the counter is enable and the flag is 1
	SysTick->CTRL = 0;//stop the counter and reset the flag;
	SysTick->VAL = 0;//reset the val£»

	}


	    