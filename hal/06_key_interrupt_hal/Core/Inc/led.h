#ifndef __LED_H_
#define __LED_H_

#include "gpio.h"

void LED_Set(uint16_t led);
void LED_Reset(uint16_t led);   
void LED_Off(void);
void LED_On(void);
void LED_Toggle(uint16_t led);

#endif
