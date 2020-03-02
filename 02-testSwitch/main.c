#include <msp.h>
#include <stdint.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer

    P1DIR |= BIT0;                   // P1.0 (Red) -> Output others Input

    P1DIR &= ~BIT1;
    P1REN |= BIT1;                   // P1.1 (S1) Pull Up/Down Enable
    P1OUT |= BIT1;                   // P1.1 Pull Up Enable

    while(1)
    {
        if(P1IN & BIT1)             // If S1 is NOT pressed
            P1OUT &= ~BIT0;         // LED OFF
        else
            P1OUT |= BIT0;          // LED ON
    }

}
