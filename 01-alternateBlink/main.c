#include <msp.h>
#include <stdint.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer
    P1DIR |= BIT0;                  // P1.0 (Red LED), P2.3 (Blue LED)
    P2DIR |= BIT2;

    while(1)
    {
        volatile uint16_t i;

        P2OUT &= ~BIT2;             //Blue LED -> OFF
        P1OUT |= BIT0;              //Red LED -> ON

        for(i = 0; i<20000; i++);   //delay

        P1OUT &= ~BIT0;             //Red LED -> OFF
        P2OUT |= BIT2;              //Blue LED -> ON

        for(i = 0; i<20000; i++);   //delay
    }

}
