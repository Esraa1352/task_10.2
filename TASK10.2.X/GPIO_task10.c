/*
 * File:   GPIO_task10.2.c
 * Author: Esraa Salah
 *
 * Created on 01 September 2024, 22:09
 */


#include <avr/io.h>
#include "GPIO_task10.h"

void GPIO_init() {
    // PD6 (OC0A - PWM output) as output for motor control
    SET_PIN_AS_OUTPUT(DDRD, PD6);

    // PD2 (INT0) and PD3 (INT1) inputs for encoder signals
    SET_PIN_AS_INPUT(DDRD, PD2);
    SET_PIN_AS_INPUT(DDRD, PD3);
}
