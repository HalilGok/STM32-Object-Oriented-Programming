/*
 * PowerLed.c
 *
 *  Created on: Aug 20, 2021
 *      Author: theen
 */

#include "PowerLed.h"

void PowerLed_ctor(PowerLed_Type * const me,
		           LedColor_Type _color,
				   LedDiameter_Type _diameter,
				   LedState_Type _state,
				   LedCurrent_Type _current,
				   LedVoltage_Type _voltage)
{
   Led_ctor(&me->super, _color, _state);
   me->current = _current;
   me->voltage = _voltage;

}
void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type _current)
{
   me->current = _current;
}
void PowerLed_setDiameter(PowerLed_Type * const me,LedDiameter_Type _diameter)
{
   me->diameter = _diameter;
}

led_elec_type PowerLed_ComputePower(PowerLed_Type * const me)
{
    return me->current * me->voltage;
}
led_elec_type PowerLed_getCurrent(PowerLed_Type * const me)
{
 	return me->current;
}
led_elec_type PowerLed_getDiameter(PowerLed_Type * const me)
{
    return me->diameter;
}
led_elec_type PowerLed_getVoltage(PowerLed_Type * const me)
{
   return me->voltage;
}


