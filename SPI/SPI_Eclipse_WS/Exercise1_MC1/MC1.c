/*
 ================================================================================================
 Name        : MC1.c
 Author      : Fady Magdy
 Description : MC1 Code in Exercise1
 ================================================================================================
 */

#include "spi.h"
#include "gpio.h"

/* Push button pull-down configuration */
#define BUTTON_PRESSED     LOGIC_HIGH
#define BUTTON_RELEASED    LOGIC_LOW

int main(void)
{
	/* Initialize the SPI driver as Master */
	SPI_initMaster();

	/* Configure PA0 as input pin */
	GPIO_setupPinDirection(PORTA_ID,PIN0_ID,PIN_INPUT);

    while(1)
    {
    	/* Check the push button status, and send to MC2 using SPI */
		if(GPIO_readPin(PORTA_ID,PIN0_ID) == BUTTON_PRESSED)
		{
			/* Send the button state, and no need to receive data from the other device */
			SPI_sendReceiveByte(BUTTON_PRESSED);
		}
		else
		{
			/* Send the button state, and no need to receive data from the other device */
			SPI_sendReceiveByte(BUTTON_RELEASED);
		}
    }
}
