/************************************/
/*	Author	  :	Abdelsalam Mahmoud	*/
/*	SWC		  : Spi  				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 9, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef _MSPI_PRIVATE_H_
#define _MSPI_PRIVATE_H_

#define     SPDR	*((volatile u8*)0X2F)

#define		SPIF 	7
#define 	WCOL	6
#define 	SPI2X	0

#define	    SPSR	*((volatile u8*)0X2E)
#define 	SPIE	7
#define 	SPE		6
#define 	DORD	5
#define 	MSTR	4
#define 	CPOL	3
#define 	CPHA	2
#define 	SPR1	1
#define 	SPR0	0

#define     SPCR	*((volatile u8*)0X2D)

#endif