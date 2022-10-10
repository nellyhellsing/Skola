#include "gpio.h"

int main(void) /*Om knapp 1 är nedtyckt blinkar vardera lysdiod åt ena hållet (reversed), med en 
                tidsfördröjning på 100ms.
				Om knapp 2 är nedtryckt blinkar vardera lysdiod åt andra hållet, med en tidsfördröjning på
				100ms.
				Om båda knappar är nedtryckta lyser alla lysdioder konstant.
				Om inga knappar är nedtryckta lyser inga lysdioder. */
{
   setup();
   
    while (1) 
    {
		 if (BUTTON1_IS_PRESSED && !BUTTON2_IS_PRESSED)
		 {
			 leds_blink_reversed(100);	 
		 }
		
		 if (BUTTON2_IS_PRESSED && !BUTTON1_IS_PRESSED)
		 {
			 leds_blink(100);
		 }
	    
		 if (BUTTON1_IS_PRESSED && BUTTON2_IS_PRESSED)
	     {
			 leds_on();
	     }
		
		 else
		 {
			 leds_off();
		 }
    }
}

