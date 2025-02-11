/************************************/
/* Author	 : Abdelsalam Mahmoud	*/
/* SWC		 : KEYPAD				*/
/* Layer	 : HAL					*/
/* Version	 : 1.0					*/
/* Date		 : October 6, 2023		*/
/* Last Edit : N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HKEYPAD_interface.h"
#include "HKEYPAD_config.h"

char HKPD_charGetKey(void)
{
	u8 L_u8Row, L_u8Col;
	MDIO_voidSetPortDirection(HKPD_PORT, 0x0f);
	MDIO_voidSetPortValue(HKPD_PORT, 0xf0);
	do
	{
		L_u8Row = MDIO_u8GetPortValue(HKPD_PORT);
		L_u8Row =((~L_u8Row) & 0xf0) >> 4;
	}while(0==L_u8Row);

	MDIO_voidSetPortDirection(HKPD_PORT, 0xf0);
	MDIO_voidSetPortValue(HKPD_PORT, 0x0f);
	L_u8Col = MDIO_u8GetPortValue(HKPD_PORT);
	L_u8Col =((~L_u8Col) & 0x0f) ;

	switch (L_u8Row) {
		case 1:L_u8Row=0;	break;
		case 2:L_u8Row=1;	break;
		case 4:L_u8Row=2;	break;
		case 8:L_u8Row=3;	break;
		default:L_u8Row=4;	break;
	}
	switch (L_u8Col) {
		case 1:L_u8Col=0;	break;
		case 2:L_u8Col=1;	break;
		case 4:L_u8Col=2;	break;
		case 8:L_u8Col=3;	break;
		default:L_u8Col=4;	break;
	}
return HKPD_charKeypad[L_u8Row][L_u8Col];
	}
