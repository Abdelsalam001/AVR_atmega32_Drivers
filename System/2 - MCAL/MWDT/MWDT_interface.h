/************************************/
/*	Author	  :	Abdelsalam Mahmoud  */
/*	SWC		  : Watchdog			*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef _MWDT_INTERFACE_H_
#define _MWDT_INTERFACE_H_

#define MWDT_PRESCALURE_16_3MS	0
#define MWDT_PRESCALURE_32_5MS	1
#define MWDT_PRESCALURE_65MS	2
#define MWDT_PRESCALURE_130MS	3
#define MWDT_PRESCALURE_260MS	4
#define MWDT_PRESCALURE_520MS	5
#define MWDT_PRESCALURE_1S		6
#define MWDT_PRESCALURE_2_1S	7

void MWDT_voidInit(u8 ARG_u8Prescalur);
void MWDT_voidEnable(void);
void MWDT_voidDisable(void);
void MWDT_voidReset(void);



#endif