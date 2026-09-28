#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Base addresses for GPIO ports (Advanced Peripheral Bus - APB)
#define GPIO_PORTA_BASE 0x40004000
#define GPIO_PORTB_BASE 0x40005000
#define GPIO_PORTC_BASE 0x40006000
#define GPIO_PORTD_BASE 0x40007000
#define GPIO_PORTE_BASE 0x40024000
#define GPIO_PORTF_BASE 0x40025000

// System Control Registers for Clock Gating
#define SYSCTL_RCGCGPIO_R (*((volatile uint32_t *)0x400FE608))

// GPIO Register Offsets
#define GPIO_DATA_OFFSET  0x3FC
#define GPIO_DIR_OFFSET   0x400
#define GPIO_AFSEL_OFFSET 0x420
#define GPIO_PUR_OFFSET   0x510
#define GPIO_DEN_OFFSET   0x51C
#define GPIO_LOCK_OFFSET  0x520
#define GPIO_CR_OFFSET    0x524
#define GPIO_AMSEL_OFFSET 0x528

// Pin Definitions
#define PIN0 (1U << 0)
#define PIN1 (1U << 1)
#define PIN2 (1U << 2)
#define PIN3 (1U << 3)
#define PIN4 (1U << 4)
#define PIN5 (1U << 5)
#define PIN6 (1U << 6)
#define PIN7 (1U << 7)

// Direction Definitions
typedef enum {
    INPUT = 0,
    OUTPUT = 1
} GPIODir_Type;

// Pull-up Resistor Definitions
typedef enum {
    PULL_DISABLE = 0,
    PULL_ENABLE = 1
} GPIOPur_Type;

// Function Prototypes
void GPIO_Init_Clock(uint32_t portBase);
void GPIO_Init_Pin(uint32_t portBase, uint8_t pinMask, GPIODir_Type dir, GPIOPur_Type pur);
void GPIO_Write_Pin(uint32_t portBase, uint8_t pinMask, uint8_t state);
uint8_t GPIO_Read_Pin(uint32_t portBase, uint8_t pinMask);
void GPIO_Toggle_Pin(uint32_t portBase, uint8_t pinMask);

#endif