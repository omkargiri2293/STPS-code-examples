#include "GPIO_lib.h"

// Enables the clock for the selected GPIO port
void GPIO_Init_Clock(uint32_t portBase) {
    uint8_t portOffset = 0;
    
    switch(portBase) {
        case GPIO_PORTA_BASE: portOffset = 0; break;
        case GPIO_PORTB_BASE: portOffset = 1; break;
        case GPIO_PORTC_BASE: portOffset = 2; break;
        case GPIO_PORTD_BASE: portOffset = 3; break;
        case GPIO_PORTE_BASE: portOffset = 4; break;
        case GPIO_PORTF_BASE: portOffset = 5; break;
        default: return;
    }
    
    // Enable clock for the port
    SYSCTL_RCGCGPIO_R |= (1U << portOffset);
    
    // Short delay to let the clock stabilize
    volatile uint32_t delay = SYSCTL_RCGCGPIO_R;
}

// Configures the specified pins
void GPIO_Init_Pin(uint32_t portBase, uint8_t pinMask, GPIODir_Type dir, GPIOPur_Type pur) {
    // Unlock mechanism needed for special pins (like PF0, PD7)
    if (((portBase == GPIO_PORTF_BASE) && (pinMask & PIN0)) || 
        ((portBase == GPIO_PORTD_BASE) && (pinMask & PIN7))) {
        (*((volatile uint32_t *)(portBase + GPIO_LOCK_OFFSET))) = 0x4C4F434B; // Unlock CR
        (*((volatile uint32_t *)(portBase + GPIO_CR_OFFSET))) |= pinMask;
    }

    // Set Direction
    if (dir == OUTPUT) {
        (*((volatile uint32_t *)(portBase + GPIO_DIR_OFFSET))) |= pinMask;
    } else {
        (*((volatile uint32_t *)(portBase + GPIO_DIR_OFFSET))) &= ~pinMask;
    }
    
    // Configure Pull-up Resistor
    if (pur == PULL_ENABLE) {
        (*((volatile uint32_t *)(portBase + GPIO_PUR_OFFSET))) |= pinMask;
    } else {
        (*((volatile uint32_t *)(portBase + GPIO_PUR_OFFSET))) &= ~pinMask;
    }
    
    // Disable Analog Mode
    (*((volatile uint32_t *)(portBase + GPIO_AMSEL_OFFSET))) &= ~pinMask;
    
    // Disable Alternate Functions
    (*((volatile uint32_t *)(portBase + GPIO_AFSEL_OFFSET))) &= ~pinMask;
    
    // Enable Digital Functionality
    (*((volatile uint32_t *)(portBase + GPIO_DEN_OFFSET))) |= pinMask;
}

// Writes digital value to specified pins
void GPIO_Write_Pin(uint32_t portBase, uint8_t pinMask, uint8_t state) {
    volatile uint32_t *dataReg = (volatile uint32_t *)(portBase + GPIO_DATA_OFFSET);
    if (state) {
        *dataReg |= pinMask;
    } else {
        *dataReg &= ~pinMask;
    }
}

// Reads digital value from specified pins
uint8_t GPIO_Read_Pin(uint32_t portBase, uint8_t pinMask) {
    volatile uint32_t *dataReg = (volatile uint32_t *)(portBase + GPIO_DATA_OFFSET);
    return ((*dataReg & pinMask) ? 1 : 0);
}

// Toggles the state of specified pins
void GPIO_Toggle_Pin(uint32_t portBase, uint8_t pinMask) {
    volatile uint32_t *dataReg = (volatile uint32_t *)(portBase + GPIO_DATA_OFFSET);
    *dataReg ^= pinMask;
}