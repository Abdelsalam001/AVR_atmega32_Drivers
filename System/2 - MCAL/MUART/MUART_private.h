/************************************/
/*	Author	  :	Abdelsalam Mahmoud	*/
/*	SWC		  : UART				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 2, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/


#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_

#define UCSRA	*((volatile u8*)0X2B)
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define U2X		1
#define DOR		3
#define PE		2
#define MPCM	0

#define UCSRB	*((volatile u8*)0X2A)
#define TXCIE 	7
#define UDRIE 	6
#define RXCIE 	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2 	2
#define TXB8	1
#define RXB8 	0

#define UCSRC	*((volatile u8*)0X40)
#define UCPOL	0
#define URSEL	7 
#define UMSEL 	6
#define UPM1 	5
#define UPM0 	4
#define USBS 	3
#define UCSZ1 	2
#define UCSZ0 	1

#define UBRRL	*((volatile u8*)0X29)
#define UBRRH	*((volatile u8*)0X40)
#define UDR		*((volatile u8*)0X2C)

#endif