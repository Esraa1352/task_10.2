int main(void) {
    // Initialize peripherals
    ADC_init();                // Initialize ADC to read potentiometer
    Motor_init();              // Initialize motor control (PWM)
    SPI_init();                // Initialize SPI for debugging
    GPIO_init();               // Initialize GPIO (if needed)
    External_Interrupts_init(); // Initialize external interrupts (if needed)

    // Enable global interrupts
    sei(); // Enable global interrupts
    
    while (1) {
        // 1. Read potentiometer value using ADC
        uint16_t adcValue = ADC_read(); // Read ADC value (0-1023)
        
        // 2. Scale ADC value to control motor speed (0-255)
        uint16_t motorSpeed = adcValue / 4; // Scale 0-1023 to 0-255
        
        // 3. Set motor speed using PWM
        Motor_setSpeed(motorSpeed);
        
        // 4. Send motor speed over SPI for debugging
        SPI_sendData(motorSpeed);
    }
    
    return 0;
}

