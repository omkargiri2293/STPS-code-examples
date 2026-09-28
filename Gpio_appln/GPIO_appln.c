#include "GPIO_lib.h"

// Simple software delay function
void Delay(volatile uint32_t time) {
    while(time--) {
        // Dummy loop
    }
}

int main(void) {
    // 1. Initialize clock for Port F
    GPIO_Init_Clock(GPIO_PORTF_BASE);
    
    // 2. Configure PF1 (Red LED) as Output, no pull-up
    GPIO_Init_Pin(GPIO_PORTF_BASE, PIN1, OUTPUT, PULL_DISABLE);
    
    // 3. Configure PF4 (SW1) as Input with Pull-up
    GPIO_Init_Pin(GPIO_PORTF_BASE, PIN4, INPUT, PULL_ENABLE);
    
    while(1) {
        // SW1 is active low (0 when pressed)
        if (GPIO_Read_Pin(GPIO_PORTF_BASE, PIN4) == 0) {
            GPIO_Toggle_Pin(GPIO_PORTF_BASE, PIN1);
            Delay(80000); // Debounce delay
        } else {
            GPIO_Write_Pin(GPIO_PORTF_BASE, PIN1, 0); // Turn off LED if not pressed
        }
    }
}