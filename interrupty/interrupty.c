
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

ISR(PCINT0_vect)
{
    /* Flip LED STATE */
    PORTB = (PORTB & ~_BV(DDB5)) | (PORTB ^ _BV(DDB5) &  _BV(DDB5));
}


void main (void)
{
    /* Set LED Port B Pin 5 to output */
    DDRB |= _BV(DDB5);

    /* Turn off LED Port B pin 5 */
    PORTB &= ~_BV(DDB5);

    /* Turn interupts on for Port B (PCINT0..7) */
    PCICR |= _BV(PCIE0);

    /* Only interupt for Port B pin 0 (PCINT0) */
    PCMSK0 |= _BV(PCINT0);

    sei();

    while(1)
    {
        /*TODO sleep_mode */
        sleep_mode();
    }
}
