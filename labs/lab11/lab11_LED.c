#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC802.h"
#include "fsl_debug_console.h"
#define LED_GREEN (12) 
#define BUTTON_USER (8) 



void PIN_INT0_IRQHandler(void) {

    if (PINT->IST & (1 << 0)) {
        PINT->IST = (1 << 0);
        GPIO->NOT[0] = (1UL<<12);
    } else {
        asm("NOP");
    }
    return;
}



int main(void) {

      /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    __disable_irq(); 
    NVIC_DisableIRQ(PIN_INT0_IRQn); 

    SYSCON->SYSAHBCLKCTRL0 |= ( SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK | SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK);
    SYSCON->PRESETCTRL0 &= ~(SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK | SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK);
    SYSCON->PRESETCTRL0 |= (SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK | SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK);

    PINT->ISEL = 0x00;
    PINT->CIENR = 0b00000001;
    PINT->SIENF = 0b00000001;
    PINT->IST = 0xFF;

    SYSCON->PINTSEL[0] = BUTTON_USER;

    NVIC_EnableIRQ(PIN_INT0_IRQn);
    GPIO->DIRSET[0] = (1UL << LED_GREEN);
    __enable_irq();

    return 0;
}

