/* Initalize Fast PWM on OCR1A*/
DDRB |= _BV(PB1); // Set PWM pin as output
PLLCSR |= _BV(PLLE); // Start PLL
_delay_us(100);      // Wait till PLL stablizes p. 9
PLLCSR |= _BV(PCKE); // Set Clock source to PLL
OCR1C = 132; // Set OCR1C to top p. 91 (60kkHz)
OCR1A = 66;  // Set beginning OCR1A value (50% duty cycle)
TCCR1  |= _BV(CS12);   /* Set clock prescaler to 8   */
TCCR1 |= _BV(PWM1A)   /* Enable PWM based on OCR1A  */ \
   |  _BV(COM1A0)   /* Set PWM compare mode p. 89 */ \
   ;
