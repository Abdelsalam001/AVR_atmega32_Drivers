/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : KEYPAD				*/
/* Layer	 : HAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 6, 2023		*/
/* Last Edit : N/A					*/
/************************************/

#ifndef _HKEYPAD_INTERFACE_H_
#define _HKEYPAD_INTERFACE_H_

#define HKPD_PORT 	MDIO_PORTC
char HKPD_charGetKey(void);

#endif