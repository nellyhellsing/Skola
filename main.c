#include "gpio.h"

int main(void) /*Om knapp 1 �r nedtyckt blinkar vardera lysdiod �t ena h�llet (reversed), med en 
                tidsf�rdr�jning p� 100ms.
				Om knapp 2 �r nedtryckt blinkar vardera lysdiod �t andra h�llet, med en tidsf�rdr�jning p�
				100ms.
				Om b�da knappar �r nedtryckta lyser alla lysdioder konstant.
				Om inga knappar �r nedtryckta lyser inga lysdioder. */
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

