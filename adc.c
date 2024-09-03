/*
 * File:   adc.c
 * Author: Esraa Salah
 *
 * Created on 02 September 2024, 15:36
 */


#include <avr/io.h>
#include "adc.h"

void ADC_init() {
    ADMUX = (1 << REFS0);  
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);  
}

int ADC_read(int channel) {
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC & 0xFF;  // Mask to 8-bit
}
