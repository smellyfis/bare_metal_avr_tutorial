#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

void main (void)
{
    /* set Pin 5 of portB for output */
    DDRB |= _BV(DDB5);

    while(1)
    {
        /* Turn on PortB pin 5 */
        PORTB |= _BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS);

        /* Turn off PortB pin 5 */
        PORTB &= ~_BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS);
    }
}

