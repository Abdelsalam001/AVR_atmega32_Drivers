/************************************/
/*	Author	  :	Abdelsalam Mahmoud  */
/*	SWC		  : Watchdog			*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef _MWDT_PRIVATE_H_
#define _MWDT_PRIVATE_H_


#define WDTCR	*((volatile u8*)0X41)

#define WDTOE	4
#define WDE  	3
#define WDP2	2
#define WDP1	1
#define WDP0	0

#endif