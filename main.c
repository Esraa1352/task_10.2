/*
 * File:   main.c
 * Author: Esraa Salah
 *
 * Created on 02 September 2024, 15:09
 */

#include <avr/io.h>
#include "GPIO_task10.h"
#include "EXTERNAL_INTERRUPT_TASK10.h"
#include "adc.h"
#include "timer_pwm.h"
#include "SPI_TASK10.h"

int main(void) {
    GPIO_init();
    External_Interrupts_init();
    TIMER0_PWM_Init();
    SPI_init();
    ADC_init();
    
    while (1) {
       
        set_motor_speed(adc_value);
        calculate_motor_speed(); 
        SPI_send(motor_speed_rpm & 0xFF);        // Send lower byte
        SPI_send((motor_speed_rpm >> 8) & 0xFF); // Send higher byte
    }
    
    return 0;
}
