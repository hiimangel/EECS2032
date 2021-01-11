/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    LPC802_Project.c
 * @brief   Application entry point.
 */


#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC802.h"
#include "fsl_debug_console.h"
#define LED_BLUE (8) // Define the blue LED (we dont use it)
#define LED_RED (9) // Define the red LED
#define LED_GREEN (12) // Define the green LED



#define USER_INPUT (8) // User input button is defined 



void delay() { // Delay function, delays the time it takes to run the program by using processing power
    int INC=0;
    while(INC < 100000){
    	INC++;
    }
}


int main(void) {
                                    //Initilizae the board

									BOARD_InitBootPins();
									BOARD_InitBootClocks();
									BOARD_InitBootPeripherals();
								#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
									BOARD_InitDebugConsole();
								#endif

    SYSCON->SYSAHBCLKCTRL0 |= (SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK); //ENABLE THE GPIO

    while(1){ // Infinite Loop
        if(GPIO->B[0][USER_INPUT] & 1){ // is the USER button pressed on the board
            GPIO->DIRSET[0] = (1UL<<LED_GREEN); //TURN ON THE GREEN LED 
            delay(); // Time interval using a long while increnment loop
            GPIO->DIRCLR[0] = (1UL<<LED_GREEN); //Turn Off the green led
            delay(); // Delay again in order to make blinking consistent
        }else{
            GPIO->DIRSET[0] = (1UL<<LED_RED); // Turn on the red LED
            delay(); //delay
            GPIO->DIRCLR[0] = (1UL<<LED_RED); // Turn off the Red led
            delay(); //Delay for consistency 
        }
    }
    return 0 ; //exit the program
}







