/*
 * File:   timer&spi&motor.c
 * Author: Esraa Salah
 *
 * Created on 02 September 2024, 16:58
 */


#include <avr/io.h>
#include "SPI_TASK10.h"

void SPI_init() {
    // Set MOSI and SCK as output
    DDRB |= (1 << PB3) | (1 << PB5);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); // rate fck/16
}

void SPI_send(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}
