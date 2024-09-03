/*
 * File:   timer_pwm.c
 * Author: Esraa Salah
 *
 * Created on 02 September 2024, 17:48
 */


#include <avr/io.h>
#include "timer_pwm.h"
#include "EXTERNAL_INTERRUPT_TASK10.h"


void TIMER0_PWM_Init() {
    // Set Fast PWM mode with non-inverted output
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS01);  // Prescaler 8
    OCR0A = 0;  // Initialize PWM duty cycle
}

void set_motor_speed(int speed) {
    if (speed < 0) speed = 0;
    if (speed > 255) speed = 255;  // For 8-bit PWM
    OCR0A = speed;  // Set PWM duty cycle
}


volatile uint16_t motor_speed_rpm = 0;

void calculate_motor_speed() {
    int ticks_per_rev = 20;  
    int time_interval = 1000;  // Example value, adjust if needed
    motor_speed_rpm = (encoder_count * 60) / (ticks_per_rev * (time_interval / 1000));
    encoder_count = 0;
}
