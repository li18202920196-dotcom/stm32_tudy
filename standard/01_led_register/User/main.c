#include "stm32f10x.h"                  // Device header

//利用系统定时器,72Mhz=1/72us
void Delay_us(uint16_t us)
{
	//1.装载一个计数值
	SysTick->LOAD = 72 * us;
	//2.配置系统时钟
	SysTick->CTRL |= 0x05;
	//3.判断计数值是否为零
	while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG))
	{}
	//4.关闭定时器
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE;
}

void Delay_ms(uint16_t ms)
{
	while(ms--)
	{
		Delay_us(1000);
	}
}

void Delay_s(uint16_t s)
{
	while (s--)
	{
		Delay_ms(1000);
	}
}

int main ()
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
		while(1)
		{
			GPIOA->ODR &= ~(GPIO_ODR_ODR0);
		    Delay_ms(500);
			GPIOA->ODR |= GPIO_ODR_ODR0;

			GPIOA->ODR &= ~(GPIO_ODR_ODR1);
			Delay_ms(500);
			GPIOA->ODR |= GPIO_ODR_ODR1;

			GPIOA->ODR &= ~(GPIO_ODR_ODR8);
			Delay_ms(500);
			GPIOA->ODR |= GPIO_ODR_ODR8;
		}
}
