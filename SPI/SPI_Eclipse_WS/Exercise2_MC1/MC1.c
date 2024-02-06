/*
 ================================================================================================
 Name        : MC1.c
 Author      : Fady Magdy
 Description : MC1 Code in Exercise2
 ================================================================================================
 */

#include "spi.h"
#include <util/delay.h> /* To use the delay functions */

int main(void)
{
	/* Initialize the SPI driver as Master */
	SPI_initMaster();

	/* Delay until MC2 finish its initialization task */
	_delay_ms(100);

	/* Send the string to MC2 */
	SPI_sendString("I am Micro1#");

    while(1)
    {

    }
}


