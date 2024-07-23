/************************************/
/*	Author	  :	Abdelsalam Mahmoud	*/
/*	SWC		  : UART				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 2, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/


#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MUART_interface.h"
#include "MUART_private.h"

static void (*MUART_pvoidfUserFunctionRxC)(void) = NULL_POINTER;
static void (*MUART_pvoidfUserFunctionTxC)(void) = NULL_POINTER;
static void (*MUART_pvoidfUserFunctionUDRE)(void) = NULL_POINTER;


void MUART_voidInit(u32 ARG_u32BaudRate, u8 ARG_u8DataBits, u8 ARG_u8Parity, u8 ARG_u8StopBits)
{
	if(((ARG_u8DataBits<=3)||(ARG_u8DataBits==7))&&((ARG_u8Parity<=3)&&(ARG_u8Parity!=1)&&(ARG_u8StopBits)<=1))
	{
		u16 L_u16UBRR = (F_CPU / (16*ARG_u32BaudRate))-1;
		UBRRL = (u8)L_u16UBRR;
		UBRRH = (u8)((L_u16UBRR>>8)& 0X0F);
		UCSRB = (UCSRB & 0XFB) | (ARG_u8DataBits & 0b100); 
		UCSRC = (UCSRC & 0XC1) | (1 << URSEL) | ((ARG_u8DataBits & 0b11)<< UCSZ0) | (ARG_u8StopBits << USBS) | (ARG_u8Parity << UPM0);
	}
}

void MUART_voidEnableTx(void)
{
	SET_BIT(UCSRB, TXEN);
}

void MUART_voidDisableTx(void)
{
	CLEAR_BIT(UCSRB, TXEN);
}
void MUART_voidEnableRx(void)
{
	SET_BIT(UCSRB, RXEN);
}
void MUART_voidDisableRx(void)
{
	CLAR_BIT(UCSRB, RXEN);
}

void MUART_voidEnableIntrrupt(u8 ARG_IntrruptSource)
{
	if((ARG_IntrruptSource>=5)&&(ARG_IntrruptSource<=7))
	{
		SET_BIT(UCSRB,ARG_IntrruptSource);
	}
}
void MUART_voidDisableIntrrupt(u8 ARG_IntrruptSource)
{
	if((ARG_IntrruptSource>=5)&&(ARG_IntrruptSource<=7))
	{
		CLEAR_BIT(UCSRB,ARG_IntrruptSource);
	}
}
void MUART_voidSetCallback(void(*ARG_pvoidfUserFunction)(void), u8 ARG_u8InterruptSource)
{
	switch(ARG_u8InterruptSource)
	{
		case MUART_INTERRUPT_RXC	:	MUART_pvoidfUserFunctionRxC	=ARG_u8InterruptSource; break;
	    case MUART_INTERRUPT_TXC	:	MUART_pvoidfUserFunctionTxC =ARG_u8InterruptSource; break;
        case MUART_INTERRUPT_UDRE   :	MUART_pvoidfUserFunctionUDRE=ARG_u8InterruptSource; break;
		default: break;
	}
}

void MUART_voidTxFlagPolling(void)
{
	while(!GET_BIT(UCSRA,TXC));
}
void MUART_voidRxFlagPolling(void)
{
	while(!GET_BIT(UCSRA,RXC));
}
void MUART_voidUDREFlagPolling(void)
{
	while(!GET_BIT(UCSRA,UDRE));
}

void MUART_voidSendChar(char ARG_charChar)
{
	MUART_voidUDREFlagPolling();
	UDR =ARG_charChar;
}
char MUART_charReciveChar(void)
{
	MUART_voidRxFlagPolling();
	return UDR;
}

void MUART_voidSendStrinrg(const char* ARG_ccharpString)
{
	u32 L_u32i =0;
	do
	{
		MUART_voidSendChar(ARG_ccharpString[L_u32i]);
	}while(ARG_ccharpString[L_u32i]!='\0');
	
}
void MUART_voidReciveStrinrgUntil(char* ARG_charpString, char ARG_charTerminatingChar)
{
		u32 L_u32i =0;
	do
	{
		ARG_ccharpString[L_u32i] = MUART_charReciveChar();
		L_u32i++;
	}while(ARG_ccharpString[L_u32i-1]!= ARG_charTerminatingChar);
	ARG_charpString[L_u32i-1] = '\0';
	
}