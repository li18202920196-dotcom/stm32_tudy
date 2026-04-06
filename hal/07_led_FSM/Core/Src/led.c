#include "led.h"


void LED_Set(uint16_t led)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,led,GPIO_PIN_SET);
}

void LED_Reset(uint16_t led)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,led,GPIO_PIN_RESET);
}

void LED_Off(void)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED3_Pin,GPIO_PIN_SET);
}

void LED_On(void)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED1_GPIO_Port,LED3_Pin,GPIO_PIN_RESET);
}

void LED_Toggle(uint16_t led)
{
	HAL_GPIO_TogglePin(GPIOA,led);
}
