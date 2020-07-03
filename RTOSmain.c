/*
* TAS_main.c
*
* Created: 21-Jun-20 1:01:34 AM
*  Author: m.fathy
*/

/* include OS headers */
void interr_handle(void);
	LCD_displayStringRowColumn(1,0,"simple project:2");
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

void interr_handle(void)
ISR(INT0_vect)
{
	interr_handle();
}



