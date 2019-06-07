/* This uses TIMER1 which is a 16bit timer */
#include <avr/io.h>

#define BLINK_DELAY_MS 1000

void main (void)
{

    /* set Pin 5 of portB for output */
    DDRB |= _BV(DDB5);
    /* Intialize counter 1 to 0 */
    TCNT1 = 0x0000;

    /* set counter 1 to be in normal mode with prescaler F_CPU / 1024 (15.625KHz) */
    TCCR1A = 0x00;
    TCCR1B = _BV(CS00) | _BV(CS02);

    //OCR0A = 0xFF;

    while(1)
    {
        /* once counter 1 is greater than 15625 (1 second) change LED state */
        if (TCNT1 >= 0x3D09)
        {
            /* Flip PortB pin 5 */
            PORTB ^= _BV(PORTB5);

            /* reset overflow counter 1*/
            TCNT1=0x0000;
        }
    }
}

