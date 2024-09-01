void TIMER1_PWM_Init() {
    // Set fast PWM mode with non-inverted output
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11);  // Prescaler 8
    ICR1 = 19999;  //  50 Hz PWM
}

void set_motor_speed(int speed) {
    if (speed < 0) speed = 0;
    if (speed > 1023) speed = 1023;
    OCR1A = (speed * ICR1) / 1023;  // ADC value to PWM
}

volatile int motor_speed_rpm = 0;

void calculate_motor_speed() {
    int ticks_per_rev = 20;  
    int time_interval = 1000;
    motor_speed_rpm = (encoder_count * 60) / (ticks_per_rev * (time_interval / 1000));
    encoder_count = 0;
}
void SPI_init() {
    // Set MOSI and SCK as output
    DDRB |= (1 << PB3) | (1 << PB5);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); // rate fck/16
}

void SPI_send(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}
