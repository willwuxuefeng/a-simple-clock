#ifndef _system_clk_H
#define _system_clk_H

#include "stm32f10x.h"
#include "stdint.h"

void RCC_HSE_Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
#endif