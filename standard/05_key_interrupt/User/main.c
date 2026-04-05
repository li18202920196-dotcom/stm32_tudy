#include "Led.h"
#include "Key.h"

int main ()
{
	LED_Init();
	Key_Init();
	
	
	uint16_t led[] = {LED1, LED2, LED3};
		while(1)
		{
			if(led_mode_flag ==0)
			{
				
			}
			else
			{
				for (uint8_t i = 0; i < 3; i++)
				{
					LED_Set(led[i]);
					Delay_ms(500);
					LED_Reset(led[i]);
				}
				
			}
		}
}
