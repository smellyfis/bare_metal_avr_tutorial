
#include <avr/io.h>

void main (void)
{
    /* set Pin 5 of portB for output */
    DDRB |= _BV(DDB5);
    DDRB &= ~_BV(DDB0);

    while(1)
    {
        /* Set the led to be on when button pressed */
        PORTB = (PORTB & ~_BV(DDB5)) | ((PINB & _BV(DDB0)) << DDB5);

        /* alternative way
        if (PINB & _BV(DDB0))
        {
            PORTB |= _BV(DDB5);
        }
        else
        {
            PORTB &= ~_BV(DDB5);
        }
        */
    }
}
