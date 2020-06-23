/* 
 * File:   main.h
 * Author: Guy Maimon
 *
 * Created on June 17 , 2020, 15:07 PM
 */

#ifndef MAIN_H
#define	MAIN_H

//main.h

#include "Config.h"


#define	LAT(Port,Pin)		LAT   ##  Port  ##  bits.LAT   ##  Port  ##  Pin
#define	PORT(Port,Pin)		PORT  ##  Port  ##  bits.R     ##  Port  ##  Pin
#define	TRIS(Port,Pin)		TRIS  ##  Port  ##  bits.TRIS  ##  Port  ##  Pin





#define POT             0b00000
#define NAME_A1         LAT     (A,1)
#define NAME_A2         LAT     (A,2)
#define NAME_A3         LAT     (A,3)
#define LED4            LAT     (A,4)
#define LED3            LAT     (A,5)
#define LED2            LAT     (A,6)
#define LED1            LAT     (A,7)

#define NAME_B0         LAT     (B,0)
#define NAME_B1         LAT     (B,1)
#define NAME_B2         LAT     (B,2)
#define NAME_B3         LAT     (B,3)
#define SW1             0b01011 //LAT     (B,4)
#define NAME_B5         LAT     (B,5)
#define NAME_B6         LAT     (B,6)
#define NAME_B7         LAT     (B,7)

#define NAME_C0         LAT     (C,0)
#define NAME_C1         LAT     (C,1)
#define NAME_C2         LAT     (C,2)
#define NAME_C3         LAT     (C,3)
#define NAME_C4         LAT     (C,4)
#define SW2             0b10001 //LAT     (C,5)
#define NAME_C6         LAT     (C,6)
#define NAME_C7         LAT     (C,7)


#define TRIS_POT        TRIS     (A,0)
#define TRIS_A1         TRIS     (A,1)
#define TRIS_A2         TRIS     (A,2)
#define TRIS_A3         TRIS     (A,3)
#define TRIS_LED4       TRIS     (A,4)
#define TRIS_LED3       TRIS     (A,5)
#define TRIS_LED2       TRIS     (A,6)
#define TRIS_LED1       TRIS     (A,7)

#define TRIS_B0         TRIS     (B,0)
#define TRIS_B1         TRIS     (B,1)
#define TRIS_B2         TRIS     (B,2)
#define TRIS_B3         TRIS     (B,3)
#define TRIS_SW1        TRIS     (B,4)
#define TRIS_B5         TRIS     (B,5)
#define TRIS_B6         TRIS     (B,6)
#define TRIS_B7         TRIS     (B,7)

#define TRIS_C0         TRIS     (C,0)
#define TRIS_C1         TRIS     (C,1)
#define TRIS_C2         TRIS     (C,2)
#define TRIS_C3         TRIS     (C,3)
#define TRIS_C4         TRIS     (C,4)
#define TRIS_SW2        TRIS     (C,5)
#define TRIS_C6         TRIS     (C,6)
#define TRIS_C7         TRIS     (C,7)








//#define	RED 		PORT  (A,2)    //LED, in on/off -when On
//#define	POT         0b00011         //A/D convertor AN3
//#define	INPUT   	LAT   (A,4)    //the input switch (for on/off)
//
//#define	OUTPUT		PORT  (C,0)    //the outpot port sending signals of 20 ms with varying uptime
//
//#define	TRIS_RED			TRIS (A,2)    
//#define TRIS_POT            TRIS (A,3)
//#define	TRIS_INPUT			TRIS (A,4)    
//#define	TRIS_OUTPUT			TRIS (C,0)    

#define ON_TIME             750
#define OFF_TIME            2450
#define TIME                7

#define MIN_TIME            ON_TIME
#define MAX_TIME            OFF_TIME

#endif	/* MAIN_H */

