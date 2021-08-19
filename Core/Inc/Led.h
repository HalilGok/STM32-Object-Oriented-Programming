/*
 * Led.h
 *
 *  Created on: Aug 19, 2021
 *      Author: theen
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdint.h>
#include <stdio.h>
#include "retarget.h"
#include "stm32f4xx.h"

#define LED_PORT GPIOD

#define LED_PORT_CLOCK (1U<<3)

#define LED_RED_PIN  (1U<<14)
#define LED_GREEN_PIN  (1U<<12)
#define LED_BLUE_PIN  (1U<<15)
#define LED_YELLOW_PIN  (1U<<13)

#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT  (1U<<24)
#define LED_YELLOW_MODE_BIT  (1U<<26)
#define LED_BLUE_MODE_BIT  (1U<<30)


typedef enum {
	RED = 0,
	GREEN,  // 1
	YELLOW, //2
	BLUE   //3
}LedColor_Type;

typedef enum {
	OFF = 0,
	ON = 1

}LedState_Type;

/* Led's attributes */
typedef struct {
	LedColor_Type color; /* color of led */
	LedState_Type state; /* state of led */
    uint32_t last_update;

}Led_Type;

void Led_ctor(Led_Type * const me, LedColor_Type _color,LedState_Type _state);
void Led_setState(Led_Type * const me, LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

#endif /* INC_LED_H_ */
