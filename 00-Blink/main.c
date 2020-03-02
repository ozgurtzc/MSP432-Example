#include <msp.h>
#include <stdint.h>

int main(void)
{
    volatile uint32_t i;

    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT
    P1DIR = 0x01;                           // P1.0 set as output

    while (1)                               // continuous loop
    {
        P1OUT ^= 0x01;                      // Blink P1.0 LED
        for (i = 200000; i > 0; i--);       // Delay
    }

}
