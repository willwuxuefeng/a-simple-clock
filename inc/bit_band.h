#ifndef _bit_band_H
#define _bit_band_H

//#include "stm32f10x.h"

#define BIT_BAND_ALIAS(addr, bitnum)  ( (addr & 0xF0000000) + 0x2000000 + ( (addr & 0xFFFFF)<<5) + (bitnum<<2) ) //set the bitband to the value of bit alias address
#define BIT_BAND_ADDRESS(addr, bitnum)   (volatile unsigned long *)BIT_BAND_ALIAS(addr, bitnum)  //change the vlaue to the address which  can be recognized by c language
	
#define GPIOA_ODR_ADDRESS (GPIOA_BASE + 0x0c)   //set the GPIOA_ODR to the value of bit alias address
#define GPIOB_ODR_ADDRESS (GPIOB_BASE + 0x0c) //set the GPIOB_ODR to the value of bit alias address
#define GPIOC_ODR_ADDRESS (GPIOC_BASE + 0x0c) //set the GPIOC_ODR to the value of bit alias address
#define GPIOD_ODR_ADDRESS (GPIOD_BASE + 0x0c) //set the GPIOD_ODR to the value of bit alias address
#define GPIOE_ODR_ADDRESS (GPIOE_BASE + 0x0c) //set the GPIOE_ODR to the value of bit alias address
#define GPIOF_ODR_ADDRESS (GPIOF_BASE + 0x0c) //set the GPIOF_ODR to the value of bit alias address
#define GPIOG_ODR_ADDRESS (GPIOG_BASE + 0x0c) //set the GPIOG_ODR to the value of bit alias address

#define GPIOA_IDR_ADDRESS (GPIOA_BASE + 0x08) //set the GPIOA_ODR to the value of bit alias address
#define GPIOB_IDR_ADDRESS (GPIOB_BASE + 0x08) //set the GPIOB_ODR to the value of bit alias address
#define GPIOC_IDR_ADDRESS (GPIOC_BASE + 0x08) //set the GPIOC_ODR to the value of bit alias address
#define GPIOD_IDR_ADDRESS (GPIOD_BASE + 0x08) //set the GPIOD_ODR to the value of bit alias address
#define GPIOE_IDR_ADDRESS (GPIOE_BASE + 0x08) //set the GPIOE_ODR to the value of bit alias address
#define GPIOF_IDR_ADDRESS (GPIOF_BASE + 0x08) //set the GPIOF_ODR to the value of bit alias address
#define GPIOG_IDR_ADDRESS (GPIOG_BASE + 0x08) //set the GPIOG_ODR to the value of bit alias address

#define PA_OUT(n)  *(BIT_BAND_ADDRESS(GPIOA_ODR_ADDRESS, n)) // the value of output not address
#define PA_IN(n)   *(BIT_BAND_ADDRESS(GPIOA_IDR_ADDRESS, n)) // the value of input not address
#define PB_OUT(n)  *(BIT_BAND_ADDRESS(GPIOB_ODR_ADDRESS, n)) 
#define PB_IN(n)   *(BIT_BAND_ADDRESS(GPIOB_IDR_ADDRESS, n))
#define PC_OUT(n)  *(BIT_BAND_ADDRESS(GPIOC_ODR_ADDRESS, n))
#define PC_IN(n) 	 *(BIT_BAND_ADDRESS(GPIOC_IDR_ADDRESS, n))
#define PD_OUT(n)  *(BIT_BAND_ADDRESS(GPIOD_ODR_ADDRESS, n))
#define PD_IN(n)   *(BIT_BAND_ADDRESS(GPIOD_IDR_ADDRESS, n))
#define PE_OUT(n)  *(BIT_BAND_ADDRESS(GPIOE_ODR_ADDRESS, n))
#define PE_IN(n)   *(BIT_BAND_ADDRESS(GPIOE_IDR_ADDRESS, n))
#define PF_OUT(n)  *(BIT_BAND_ADDRESS(GPIOF_ODR_ADDRESS, n))
#define PF_IN(n)   *(BIT_BAND_ADDRESS(GPIOF_IDR_ADDRESS, n))
#define PG_OUT(n)  *(BIT_BAND_ADDRESS(GPIOG_ODR_ADDRESS, n))
#define PG_IN(n)   *(BIT_BAND_ADDRESS(GPIOG_IDR_ADDRESS, n))

#endif



