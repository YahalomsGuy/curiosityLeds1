	/*
	 * File:   main.c
	 * Author: Guy Maimon.
	 *
	 *
	 * 2020-June-17: Guy Maimon: Version V1.01
	 * - Initial version , imported from BSURE 2.61
		
     * Characteristics of the HiTech 500 Servo
     -  low is counter clockwise end
     -  lowest is around 700 us
     -  high is clockwise end
     -  highest is around 2500
     -	for 180deg (-90deg :+ 90deg) movement the scope will be 750-2450, 
     -  the center (0deg) is 1600

	 * the device has two operation modes:
		1 - when the switch (INPUT) is ON (1) the servo goes to the end of the movement spectrum
		2 - when the switch os OFF (0) the position is controlled by the potentiometer (POT)
		2.1 - to allow quick processing of POT , the movement is in 9 degrees jumps
	 
     * 	 
	 */


	#include <xc.h>
	#include "main.h"
	#define	VERSION 10	// v1.0.1
	#define _XTAL_FREQ	32000000ul

	void InitializeHardware(void);
    unsigned char ReadInput(char source[3]);
    unsigned char ReadPot(void);
    unsigned char ReadSw1(void);
    unsigned char ReadSw2(void);
    unsigned char ReadAdc(void);
    unsigned char potValue;
    int i;
    unsigned char sw1Value;
    unsigned char sw2Value;
	int main(void) {
        
		InitializeHardware();
		__delay_ms(55);   //initiation timeout
		CLRWDT();
		while(1){
			CLRWDT();
            potValue = ReadPot();
            sw1Value = ReadSw1();
            sw2Value = ReadSw2();
            CLRWDT();
            
            if(sw2Value == 0){
                LED4 = ~LED4;
                for(i = 0 ; i < potValue;i++){
                    __delay_ms(TIME);   //initiation timeout
                }
                LED4 = ~LED4;
            }
            if(sw1Value == 0){
                LED3 = ~LED3;
                for(i = 0 ; i < potValue;i++){
                    __delay_ms(TIME);   //initiation timeout
                }
                LED3 = ~LED3;
            }
            if(sw2Value == 0){
                LED2 = ~LED2;
                for(i = 0 ; i < potValue;i++){
                    __delay_ms(TIME);   //initiation timeout
                }
                LED2 = ~LED2;
            }
            if(sw1Value == 0){
                LED1 = ~LED1;
                for(i = 0 ; i < potValue;i++){
                __delay_ms(TIME);   //initiation timeout
                }
                LED1 = ~LED1;
            }

        }
	}


	////////////FUNCTION INITIALIZATION/////////////////
	
    
    

	void InitializeHardware(void) {
		//Setup OSC
		OSCCON = 0b11111000; //PLL enabled here and in CONFIG, 8x4 = 32Mhz Internal Clock

		//PORT A INPUT/OUTPUT SETUP  0 is output  1 is input
		TRIS_POT = 1;
        TRIS_A1 = 0;
        TRIS_A2 = 0;
        TRIS_A3 = 0;
        TRIS_LED4 = 0;
        TRIS_LED3 = 0;
        TRIS_LED2 = 0;
        TRIS_LED1 = 0;
        
		//PORT B INPUT/OUTPUT SETUP  0 is output  1 is input
		TRIS_B0 = 0;
        TRIS_B1 = 0;
        TRIS_B2 = 0;
        TRIS_B3 = 0;
        TRIS_SW1 = 1;
        TRIS_B5 = 0;
        TRIS_B6 = 0;
        TRIS_B7 = 0;

		//PORT C INPUT/OUTPUT SETUP  0 is output  1 is input
		TRIS_C1 = 0;
        TRIS_C2 = 0;
        TRIS_C3 = 0;
        TRIS_C4 = 0;
        TRIS_SW2 = 1;
        TRIS_C6 = 0;
        TRIS_C7 = 0;

        //Initialize Output state
        LATA = 0;
        LATB = 0;
        LATC = 0;

        //Set which Inputs are Analog
        //1 for every analog output (low to high) AN0 only is 0b00000001
        ANSELA = 0b00001000;  
        ANSELB = 0b00000000;
        ANSELC = 0b00000000;

        //Setup ADCs
        ADCON0 = 0b00000000; //Disabled
        ADCON1 = 0b00000000; //Internal plus & minus references
        ADCON2 = 0b10010110; //Right Justified, 4 TAD, Fosc/64

        //Setup OSC
        OSCCON = 0b01110100; //16Mhz Internal Clock (before PLL)
        OSCTUNEbits.PLLEN = 1; //Enable PLL for 64Mhz Clock

        //Timer0 (16 bit) for HOLD delay
        T0CON = 0b10000111; //Timer0 ON, 16bit, 1:256 prescaler

        //Timer1 (16 bit) for Read Photo delay
        PIR1bits.TMR1IF = 0;	//Reset Timer1 flag
        TMR1 = 0;
        T1CON = 0b00110011;	//FOSC/4, 1:8 prescale, enabled
        //=> 8 * 16 bits = overflow every 524,288 Tcy (32.768ms @64Mhz)

        WDTCONbits.SWDTEN = 1; //WatchDog Timer ON, software controlled
}

    unsigned char ReadPot(void) {
    	ADCON0bits.CHS = POT;  //00000
        return(ReadAdc());
    }
    
    unsigned char ReadSw1(void) {
    	ADCON0bits.CHS = SW1;  //00000
        return(ReadAdc());
    }
    unsigned char ReadSw2(void) {
    	ADCON0bits.CHS = SW2;  //00000
        return(ReadAdc());
    }
    unsigned char ReadAdc(void) {
		
		unsigned int RawAdcValue;
		unsigned int AdcValue;
		unsigned long Sum;
		unsigned char NumReads;

		CLRWDT();

		Sum = 0;
		ADCON0bits.ADON = 1; // enable the ADC

		//Average 2 reads per channel
		for (NumReads = 0; NumReads < 8; NumReads++) {
			//Wait the required acquisition time, before starting conversion
			__delay_us(10);

			ADCON0bits.GO = 1; //Start a conversion
			while (ADCON0bits.GO); // Wait while busy

			//Get A/D
			RawAdcValue = (int) ADRES;

			//Only want 12 LSbits (ignoring any sign bits)
			AdcValue = (int) RawAdcValue & 0xFFF;

			Sum += (long) AdcValue;
		}

		ADCON0bits.ADON = 0; // disable the ADC

		//Convert from 12 bit to 8 bit & Divide by NumReads
		AdcValue = (long) Sum >> 5;

		return (AdcValue);

	}
