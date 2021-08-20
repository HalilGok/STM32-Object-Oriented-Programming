/*
 * PowerLed.h
 *
 *  Created on: Aug 20, 2021
 *      Author: theen
 */

#ifndef INC_POWERLED_H_
#define INC_POWERLED_H_

#include "Led.h"

typedef uint8_t led_elec_type;
typedef uint8_t led_diam_type;
typedef enum {
    CURR_LOW = 10,  /* 10mA */
	CURR_NORMAL = 20,
	CURR_HIGH = 35,
	CURR_VERY_HIGH = 60

}LedCurrent_Type;

typedef enum {
	DIAM_2MM = 2, /* 2mm */
	DIAM_5MM = 5,
	DIAM_7MM = 7

}LedDiameter_Type;

typedef enum {
   VOL_LOW = 3,  /* 3V */
   VOL_NORMAL = 5,
   VOL_HIGH = 9


}LedVoltage_Type;

typedef struct {
	Led_Type super;
	LedVoltage_Type voltage;
	LedCurrent_Type current;
	LedDiameter_Type diameter;

}PowerLed_Type;

LedDiameter_Type diameter;
void PowerLed_ctor(PowerLed_Type * const me,
		           LedColor_Type _color,
				   LedDiameter_Type _diameter,
				   LedState_Type _state,
				   LedCurrent_Type _current,
				   LedVoltage_Type _voltage);

void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type _current);
void PowerLed_setDiameter(PowerLed_Type * const me,LedDiameter_Type _diameter);

led_elec_type PowerLed_ComputePower(PowerLed_Type * const me);
led_elec_type PowerLed_getCurrent(PowerLed_Type * const me);
led_elec_type PowerLed_getDiameter(PowerLed_Type * const me);
led_elec_type PowerLed_getVoltage(PowerLed_Type * const me);




#endif /* INC_POWERLED_H_ */






