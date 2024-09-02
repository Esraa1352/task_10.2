/*
 * File:   EXTERNAL_INTERRUPT_TASK10.2.C
 * Author: Esraa Salah
 *
 * Created on 01 September 2024, 22:10
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "EXTERNAL_INTERRUPT_TASK10.h"

volatile uint16_t encoder_count = 0;

void External_Interrupts_init() {
    EICRA |= (1 << ISC00) | (1 << ISC01); 
    EICRA |= (1 << ISC10) | (1 << ISC11); 
    EIMSK |= (1 << INT0) | (1 << INT1);

    // Enable global interrupts
    sei();
}

ISR(INT0_vect) {
    encoder_count++;
}

ISR(INT1_vect) {
    encoder_count++;
}

uint16_t get_encoder_count() {
    return encoder_count;
}
