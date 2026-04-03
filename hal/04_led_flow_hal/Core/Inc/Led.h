#ifndef __LED_H
#define __LED_H

#include "gpio.h"

void Led_Set(uint16_t led);
void Led_Reset(uint16_t led);

void Led_Toggle(uint16_t led);

void Led_SetAll(uint16_t led[],uint8_t size);
void Led_ResetAll(uint16_t led[],uint8_t size);

#endif
