#include "main.h"

/* @brief  Configuration the PLL clock source and multiplication factor to set the value of system clock
	* @note   This function must be used only when the PLL is disabled.
	* @param  RCC_PLLSource: specifies the PLL entry clock source.
	*     @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected as PLL clock entry
	*     @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided by 2 selected as PLL clock entry 
	* @param  RCC_PLLMul: specifies the PLL multiplication factor.
	* this parameter can be RCC_PLLMul_x where x:[2,16]  
	* @retval None
	*/		
void RCC_HSE_Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul){
	RCC_DeInit();//Resets the RCC clock configuration to the default reset state
	RCC_HSEConfig(RCC_HSE_ON);//HSE oscillator ON
	if(RCC_WaitForHSEStartUp()==SUCCESS){ //HSE oscillator is stable and ready to use
		RCC_PLLConfig(RCC_PLLSource,RCC_PLLMul);//Configures the PLL clock source and multiplication factor
		RCC_PLLCmd(ENABLE);//ENABLE the RCC
		RCC_GetFlagStatus(RCC_FLAG_PLLRDY);// PLL clock ready
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//PLL selected as system clock
		while(RCC_GetSYSCLKSource()!=0x08);//Returns the clock source used as system clock if not PLL just Forever loop
		RCC_HCLKConfig(RCC_SYSCLK_Div1);// AHB clock = SYSCLK
		RCC_PCLK1Config(RCC_HCLK_Div2);//APB1 clock = HCLK/2
		RCC_PCLK2Config(RCC_HCLK_Div1);//APB2 clock = HCLK
		}

}