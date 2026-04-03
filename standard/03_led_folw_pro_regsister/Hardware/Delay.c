#include "stm32f10x.h"

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
