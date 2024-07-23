/************************************/
/*	Author	  :	Abdelsalam Mahmoud  */
/*	SWC		  : Watchdog			*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 1, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/


void MWDT_voidInit(u8 ARG_u8Prescalur)
{
	WDTCR = ((WDTCR)&0XF8)| ARG_u8Prescalur;
	
}
void MWDT_voidEnable(void)
{
	
	SET_BIT(WDTCR,WDE);
}
void MWDT_voidDisable(void)
{
	WDTCR |= (3<<WDE);
	WDTCR =0X00;
}
void MWDT_voidReset(void)
{
__asm__ __volatile__("WDR");	
}