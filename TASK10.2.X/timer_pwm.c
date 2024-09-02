/*
 * File:   timer_pwm.c
 * Author: Esraa Salah
 *
 * Created on 02 September 2024, 17:48
 */


#include <avr/io.h>
#include "timer_pwm.h"
#include "EXTERNAL_INTERRUPT_TASK10.h"


void TIMER1_PWM_Init() {
    // Set fast PWM mode with non-inverted output
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11);  // Prescaler 8
    ICR1 = 19999;  // 50 Hz PWM
}

void set_motor_speed(int speed) {
    if (speed < 0) speed = 0;
    if (speed > 1023) speed = 1023;
    OCR1A = (speed * ICR1) / 1023;  // ADC value to PWM
}

volatile uint16_t motor_speed_rpm = 0;

void calculate_motor_speed() {
    int ticks_per_rev = 20;  
    int time_interval = 1000;
    motor_speed_rpm = (encoder_count * 60) / (ticks_per_rev * (time_interval / 1000));
    encoder_count = 0;
}
