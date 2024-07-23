/************************************/
/*	Author	  :	Abdelsalam Mahmoud	*/
/*	SWC		  : Spi  				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 9, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef _MSPI_INTERFACE_H_
#define _MSPI_INTERFACE_H_

#define MSPI_MODE_MASTER	1
#define MSPI_MODE_SLAVE 	0

#define MSPI_CLOCKPOLLHA_NONINVERTING_LEADING	0
#define MSPI_CLOCKPOLLHA_NONINVERTING_TRAILING	1
#define MSPI_CLOCKPOLLHA_INVERTING_LEADING		2
#define MSPI_CLOCKPOLLHA_INVERTING_TRAILING		3

#define MSPI_DATAORDER_MSP	0
#define MSPI_DATAORDER_LSP 	1

#define MSPI_PRESCALURE_4	0
#define MSPI_PRESCALURE_16	1
#define MSPI_PRESCALURE_64	2
#define MSPI_PRESCALURE_128	3
#define MSPI_PRESCALURE_2	4
#define MSPI_PRESCALURE_8	5
#define MSPI_PRESCALURE_32	6
#define MSPI_PRESCALURE_64	7


void MSPI_voidInit(u8 ARG_u8Mode,u8 ARG_u8ClockPolPha,u8 ARG_u8DataOrder,u8 ARG_u8Prescaler);
void MSPI_voidEnable(void);
void MSPI_voidDisable(void);
void MSPI_voidEnableInterrupt(void);
void MSPI_voidDisableInterrupt(void);
void MTIM_voidSetCallback(void(*ARG_pvoidfUserFunction)(void));
void MTIM_voidFlagPolling(void);
char MTIM_charTranscevier(char ARG_charChar);


#endif