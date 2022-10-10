#include "gpio.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar. Lysdiodernas pinnar 6 - 8 s�tts
*        till utportar, medan knapp 1 och 2 anv�nds f�r att insignalen ska bli 
*        h�g eller l�g.
********************************************************************************/
void setup(void) 
{
	DDRD = ((1 << LEDB) | (1 << LEDG));
	DDRB = (1 << LEDR);
	PORTB = ((1 << BUTTON1) | (1 << BUTTON2));
	return;
}

void leds_on(void) // T�nder alla lysdioder
{
	LEDG_ON;
	LEDR_ON;
	LEDB_ON;
}

void leds_off(void) // Sl�cker alla lysdioder
{
	LEDG_OFF;
	LEDR_OFF;
	LEDB_OFF;
}

void leds_blink(const uint16_t blink_speed_ms) // T�nder vardera lysdiod efter varandra.
{
	LEDB_ON;
	LEDG_OFF;
	LEDR_OFF;
	delay_ms(blink_speed_ms);


	LEDB_OFF;
	LEDG_ON;
	LEDR_OFF;
	delay_ms(blink_speed_ms);

	LEDB_OFF;
	LEDG_OFF;
	LEDR_ON;
	delay_ms(blink_speed_ms);
}

void leds_blink_reversed(const uint16_t blink_speed_ms) // T�nder vardera lysdiod �t andra h�llet.
{
	LEDB_OFF;
	LEDG_OFF;
	LEDR_ON;
	delay_ms(blink_speed_ms);

	LEDB_OFF;
	LEDG_ON;
	LEDR_OFF;
	delay_ms(blink_speed_ms);

	LEDB_ON;
	LEDG_OFF;
	LEDR_OFF;
	delay_ms(blink_speed_ms);
}

void delay_ms(const uint16_t delay_time_ms) // delay_time_ms = 100
{
	// 100 ms f�rdr�jning = 100 varv x 1 ms f�rdr�jning.
	
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}
}

