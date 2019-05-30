#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

void main (void)
{
    /* set Pin 5 of portB for output */
    /* DDRB |= _BV(DDB5); */
    /* mega - pin 5 port k */
    DDRK |= _BV(DDK5);

    while(1)
    {
        /* Turn on PortB pin 5 */
        PORTK |= _BV(PORTK5);
        _delay_ms(BLINK_DELAY_MS);

        /* Turn off PortB pin 5 */
        PORTK &= ~_BV(PORTK5);
        _delay_ms(BLINK_DELAY_MS);
    }
}

