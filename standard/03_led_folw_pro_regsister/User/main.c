#include "Led.h"
#include "Delay.h"

int main ()
{
	LED_Init();
	
	uint16_t led[] = {LED1,LED2,LED3};
	uint8_t i,n=3;
		while(1)
		{
			for(i=0;i<n;i++)
			{
				LED_Set(led[i]);
				Delay_ms(500);
				LED_Reset(led[i]);
			}
			for(i=n-2;i>0;i--)
			{
				LED_Set(led[i]);
				Delay_ms(500);
				LED_Reset(led[i]);
			}
		}
}
