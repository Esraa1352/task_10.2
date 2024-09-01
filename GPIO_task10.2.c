/*
 * File:   GPIO_task10.2.c
 * Author: Esraa Salah
 *
 * Created on 01 September 2024, 22:09
 */


#include <xc.h>
#include "GPIO_TASK10.2.h"

void GPIO_init() {
    //PD6 (OC0A - PWM output) as output for motor control
    SET_PIN_AS_OUTPUT(DDRD, PORT_D6);

    // PD2 (INT0) and PD3 (INT1) inputs for encoder signals
    SET_PIN_AS_INPUT(DDRD, PORT_D2);
    SET_PIN_AS_INPUT(DDRD, PORT_D3);
}

void main(void) {
    return;
}
