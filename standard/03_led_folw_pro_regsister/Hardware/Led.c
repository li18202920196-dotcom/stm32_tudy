#include "stm32f10x.h"

void LED_Init()
{
// 1. 时钟配置
	//RCC->APB2ENR = 4; // 等价于*(uint32_t *)(0x40021000 + 0x18) = 4;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		
	//2.GOPIO工作模式配置
	GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1);
	GPIOA->CRL |= GPIO_CRL_MODE0 |GPIO_CRL_MODE1;
	
	
	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	GPIOA->CRH |= GPIO_CRH_MODE8;
	
	//3.PA0输出低电平
	GPIOA->ODR |= (GPIO_ODR_ODR0 | GPIO_ODR_ODR1 | GPIO_ODR_ODR8);
}

void LED_Set(uint16_t led)
{
    GPIOA->ODR &= ~led;
}

void LED_Reset(uint16_t led)
{
    GPIOA->ODR |= led;
}

void LED_Toggle(uint16_t led)
{
	if((GPIOA->IDR &= led) == 0)
	{
		LED_Reset(led);
	}
	else
	{
		LED_Set(led);
	}
}
