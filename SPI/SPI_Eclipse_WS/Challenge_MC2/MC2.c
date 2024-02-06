/*
 ================================================================================================
 Name        : MC2.c
 Author      : Fady magdy
 Description : MC2 Code in Challenge
 ================================================================================================
 */

#include "spi.h"
#include "lcd.h"

int main(void)
{
	uint8 key;

	/* Initialize the LCD Driver */
	LCD_init();

	/* Initialize the SPI driver as Slave */
	SPI_initSlave();

    while(1)
    {
    	/*
    	 * Receive the pressed key from MC1 using SPI,
    	 * and send SPI_DEFAULT_DATA_VALUE as no need to send data to other device.
    	 */
		key = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

		/* Display the pressed key on LCD */
		if((key>=0) && (key<=9))
		{
			LCD_intgerToString(key);
		}
		else
		{
			LCD_displayCharacter(key);
		}
    }
}


