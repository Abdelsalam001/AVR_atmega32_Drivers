/************************************/
/*	Author	  :	Abdelsalam Mahmoud	*/
/*	SWC		  : Spi  				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 9, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MSPI_interface.h"
#include "MSPI_private.h"

static void (*MSPI_pvoidfUserFunction)(void) = NULL_POINTER;

void MSPI_voidInit(u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8DataOrder, u8 ARG_u8Prescaler)
{
	if((ARG_u8Mode <= 1) && (ARG_u8ClockPolPha <= 3) && (ARG_u8DataOrder <= 1) && (ARG_u8Prescaler <=6))
	{
		SPCR = (SPCR & 0x80) | (1 << SPE) | (ARG_u8Mode << MSTR) | (ARG_u8ClockPolPha << CPHA) | (ARG_u8DataOrder << DORD) | (ARG_u8Prescaler & 0x03);
		SPSR = (SPSR & 0xC0) | (ARG_u8Prescaler >> 2);
	}
	else
	{
		/*Report an Error*/
	}
	
}


void MSPI_voidEnable(void)
{
	SET_BIT(SPCR, SPE);
}


void MSPI_voidDisable(void)
{
	CLEAR_BIT(SPCR, SPE);
}


void MSPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR, SPIE);
}


void MSPI_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPCR, SPIE);
}


void MSPI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void))
{
	if(MSPI_pvoidfUserFunction != NULL_POINTER)
	{
		MSPI_pvoidfUserFunction = ARG_pvoidfUserFunction;
	}
	else
	{
		/*Report an Error*/
	}
}


void MSPI_voidFlagPolling(void)
{
	while(!GET_BIT(SPSR, SPIF));
}


char MSPI_voidTransceive(char ARG_charChar)
{
	SPDR = ARG_charChar;
	MSPI_voidFlagPolling();
	return SPDR;
}


void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(MSPI_pvoidfUserFunction != NULL_POINTER)
	{
		MSPI_pvoidfUserFunction();
	}
	else
	{
		/*Do nothing (MISRA)*/
	}
}