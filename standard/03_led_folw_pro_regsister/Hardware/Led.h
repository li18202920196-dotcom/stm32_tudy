#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1 GPIO_ODR_ODR0
#define LED2 GPIO_ODR_ODR1
#define LED3 GPIO_ODR_ODR8

void LED_Init(void);
void LED_Set(uint16_t led);
void LED_Reset(uint16_t led);
void LED_Toggle(uint16_t led);

#endif
