#include <msp.h>
#include <stdint.h>

#define S1      0x0002                  // Switch -> P1.1
#define RED     0x0001                  // Red LED -> P2.0
#define GREEN   0x0002                  // Green LED -> P2.1

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer

    P2DIR |= RED + GREEN;           // Set LED pins --> Output
    P1DIR |= ~S1;                   // Set S1 pin -> Input
    P1REN |= S1;                    // Enable Resistor for S1 pin
    P1OUT |= S1;                    // Select Pull Up for SW pin

    volatile uint16_t flag = 0;

    while(1)
    {
        if(!(P1IN & S1))            // If S1 pressed
        {
            __delay_cycles(20000);  // Wait 20ms
            if(!(P1IN & S1))        // Check if S1 is still pressed
            {
                while(!(P1IN & S1));// Wait till S1 Released
                flag = !flag;       // Change flag value
            }
        }
        if(flag)                    // Check flag value
        {
            P2OUT &= ~GREEN;        // Green -> OFF
            P2OUT |= RED;           // Red -> ON
        }
        else
        {
            P2OUT &= ~RED;          // Red -> OFF
            P2OUT |= GREEN;         // Green -> ON
        }
    }
}
