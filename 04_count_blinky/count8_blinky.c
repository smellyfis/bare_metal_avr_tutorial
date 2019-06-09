/* This uses TIMER0 which is a 8bit timer */
#include <avr/io.h>

/* How long to count to in milliseconds (note: has a 16ms accurracy) */
#define BLINK_MS 2000ULL
/* Which counter mode to use, 0x05 sets clock to FCPU/1024 */
#define COUNT_MODE (_BV(CS00) | _BV(CS02))
/* How many times to overflow the buffer before state change */
#define COUNT_TO ((BLINK_MS*F_CPU)/(0x0003E800 * (1ULL<<(2ULL*(COUNT_MODE & 0x7)))))

void main (void)
{
    /* Counter that increments each time the buffer overflows */
    /*Note: pick an approporately sized for the number of count */
    uint8_t overflow_counter = 0;

    /* storing tje COUNT_TO here just to be explicit */
    uint8_t count_to = COUNT_TO; 

    /* set Pin 5 of portB for output */
    DDRB |= _BV(DDB5);
    /* Intialize counter 1 to 0 */
    TCNT0 = 0x00;

    /* set counter 0 to be in normal mode */
    TCCR0A = 0x00;
    TCCR0B = COUNT_MODE;

    //OCR0A = 0xFF;

    while(1)
    {
        /* if buffer overflow increase counter */
        if (TIFR0 & _BV(TOV0))
        {
            overflow_counter++;
            /* reset overflow flag */
            TIFR0 = _BV(TOV0);
        }

        /* once overflow counter is greater than selected value change LED state */
        if (overflow_counter >= count_to)
        {
            /* Flip PortB pin 5 */
            PORTB ^= _BV(PORTB5);

            /* reset overflow counter */
            overflow_counter = 0;
        }
    }
}

