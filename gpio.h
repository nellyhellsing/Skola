#ifndef GPIO_H_
#define GPIO_H_

/* Klockfrekvens: */
#define F_CPU 16000000UL /* 16 MHz klockfrekvens. */
#include <avr/io.h>      /* Bibliotek inneh�llande information om I/O-register. */
#include <util/delay.h>  /* Bibliotek f�r implementering av f�rdr�jning. */

#define LEDB 6  /* Lysdiod B ansluten till pin 6 / PORTD6. */
#define LEDG 7  /* Lysdiod G ansluten till pin 7 / PORTD7. */
#define LEDR 0  /* Lysdiod R ansluten till pin 8 / PORTB0. */

#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */
#define BUTTON2 4 /* Tryckknapp 2 ansluten till pin 12 / PORTB4. */

#define LEDB_ON PORTD |= (1 << LEDB) /* T�nder lysdiod B. */
#define LEDG_ON PORTD |= (1 << LEDG) /* T�nder lysdiod G. */
#define LEDR_ON PORTB |= (1 << LEDR) /* T�nder lysdiod R. */

#define LEDB_OFF PORTD &= ~(1 << LEDB) /* Sl�cker lysdiod B. */
#define LEDG_OFF PORTD &= ~(1 << LEDG) /* Sl�cker lysdiod G. */
#define LEDR_OFF PORTB &= ~(1 << LEDR) /* Sl�cker lysdiod R. */

#define LEDS_ON |= ((1 << LEDB) | (1 << LEDG) | (1 << LEDR))   /* T�nder lysdioderna. */
#define LEDS_OFF &= ~((1 << LEDB) | (1 << LEDG) | (1 << LEDR)) /* Sl�cker lysdioderna. */

#define BUTTON1_IS_PRESSED ((PINB & (1 << BUTTON1)) != 0) /* Indikerar nedtryckning av tryckknapp 1. */
#define BUTTON2_IS_PRESSED ((PINB & (1 << BUTTON2)) != 0) /* Indikerar nedtryckning av tryckknapp 2. */

void leds_on(void); //T�nder alla lysdioder
void leds_off(void); // Sl�cker alla lysdioder

void leds_blink(const uint16_t blink_speed_ms); // T�nder vardera lysdiod fr�n pin 8-6
void leds_blink_reversed(const uint16_t blink_speed_ms); // T�nder vardera lysdiod fr�n pin 6-8.

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar. Lysdiodernas pinnar 6 - 8 s�tts
*        till utportar, medan knapp 1 och 2 anv�nds f�r att insignalen ska bli
*        h�g eller l�g.
********************************************************************************/
void setup(void); 

/********************************************************************************
*           - delay_ms: f�rdr�jning m�tt i millsekunder.
*
*           - delay_time_ms: F�rdr�jningstid m�tt i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms);

#endif 