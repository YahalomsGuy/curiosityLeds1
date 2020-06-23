# curiosityLeds1
This is the first Microchip project Im uploading to GitHub

This is a very basic sample of the basic built in abilities of MicroChip's Curiosity HPC Board.

The board allow a developer to simulate almost any project, 
With few built in components such as:
* 2 PIC sockets (28 / 40 pin)
* 4 leds
* 2 switches
* 5.0 / 3.3 vold jumper selector
etc.
The Curiosity is build with a PKOB (Pik Kit On Board) programmer that allows to interact with MPlabX and test the code.

In this case , I am using:
* MPlab X 5.40
* XC8 C compiler
* PIC18F26k22

The config.h file is a basic configuration file for the PIC.
The Main.h contains all the constants (for the pins of the pic and other constants)
The Main.C is obviously where the Main function is and where the functions are written.

In this project , I am mapping:
* The 4 LED's (All outputs -  named LED1,LED2,LED3,LED4)
* The Switches (Analog inputs - named SW1,SW2)
and 
* The Potentiometer (Analog Input - Names POT)

All checked 8 times in RunADC and returned as 8 bit (Unsigned char) to the main function.


The main function simply collects the values of the Switches and the Potentiometer
and activating the LEDs according to the Status of the Switches and the Potentiometer.

Each of the Switches will make 2 LEDS Blink:
* SW1 will make LEDs 1,3 flash
* SW2 will make LEDs 2,4 flash

the speed of the flashing is determined by POT, while a loop of the 8 bit value of POT / multiplied by 7 ms (as configured in TIME)
will run for each of the LEDs.


