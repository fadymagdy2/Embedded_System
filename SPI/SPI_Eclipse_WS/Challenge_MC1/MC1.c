/*
 ================================================================================================
 Name        : MC1.c
 Author      : Fady Magdy
 Description : MC1 Code in Challenge
 ================================================================================================
 */

#include "keypad.h"
#include "spi.h"
#include <util/delay.h> /* To use the delay functions */

int main(void)
{
	uint8 key;

	/* Initialize the SPI driver as Master */
	SPI_initMaster();

    while(1)
    {
    	/* Get the pressed button from keypad */
		key = KEYPAD_getPressedKey();

		/* Send the pressed key to MC2 using SPI, and no need to receive data from the other device */
		SPI_sendReceiveByte(key);

		/* Wait 500msec before getting a new press from the keypad buttons, Press time is 500msec */
		_delay_ms(500);
    }
}


