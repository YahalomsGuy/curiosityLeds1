//Configure for 18F26K22 processor

#pragma config	FOSC	= INTIO67   //Internal clock, RA6 & RA7 set as regular outputs
#pragma config	PLLCFG	= ON        //Turn ON PLL (increases clock speed)
#pragma config	FCMEN	= OFF
#pragma config	IESO	= OFF
#pragma config	PWRTEN	= OFF
#pragma config	BOREN	= OFF       //Hardware Controlled BOR, Software BOR Disabled
#pragma config	BORV	= 250       //BOR if voltage drops below 2.5V
#pragma config	WDTEN	= SWON      //Software controlled WDT
#pragma config	WDTPS	= 1024      // 1024 * 4 ms = 4.096 seconds
#pragma config	MCLRE	= EXTMCLR
#pragma config	HFOFST 	= OFF
#pragma config	PBADEN 	= OFF
#pragma config	CCP2MX 	= PORTC1
#pragma config	STVREN 	= ON
#pragma config	LVP     = ON
#pragma config	XINST 	= OFF
#pragma config	DEBUG	= OFF

#pragma config	CP0	= OFF  //ON
#pragma config	CP1	= OFF  //ON
#pragma config	CP2	= OFF  //ON
#pragma config	CP3	= OFF  //ON
#pragma config	CPB	= OFF  //ON
#pragma config	CPD	= OFF  //ON

#pragma config	WRT0	= OFF
#pragma config	WRT1	= OFF
#pragma config	WRT2	= OFF
#pragma config	WRT3	= OFF
#pragma config	WRTB	= OFF
#pragma config	WRTC	= OFF
#pragma config	WRTD	= OFF

#pragma config	EBTR0	= OFF
#pragma config	EBTR1	= OFF
#pragma config	EBTR2	= OFF
#pragma config	EBTR3	= OFF
#pragma config	EBTRB	= OFF
