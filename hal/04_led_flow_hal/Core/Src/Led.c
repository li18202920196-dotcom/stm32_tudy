#include"Led.h"

void Led_Set(uint16_t led)
{
    HAL_GPIO_WritePin(GPIOA,led,GPIO_PIN_SET);
}

void Led_Reset(uint16_t led)
{
    HAL_GPIO_WritePin(GPIOA,led,GPIO_PIN_RESET);
}

void Led_Toggle(uint16_t led)
{
    HAL_GPIO_TogglePin(GPIOA,led);
}

void Led_SetAll(uint16_t led[],uint8_t size)
{
   for(uint8_t i = 0;i<size;i++)
    {
        Led_Set(led[i]);
    }
}

void Led_ResetAll(uint16_t led[],uint8_t size)
{
    for(uint8_t i = 0;i<size;i++)
    {
        Led_Reset(led[i]);
    }
}
