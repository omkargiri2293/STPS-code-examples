#ifndef SEVEN_SEG_LIB_H
#define SEVEN_SEG_LIB_H

#include <stdint.h>
#include "GPIO_lib.h"


/* Segment Port */

#define SEG_PORT        GPIO_PORTB_BASE

#define SEG_A           PIN0
#define SEG_B           PIN1
#define SEG_C           PIN2
#define SEG_D           PIN3
#define SEG_E           PIN4
#define SEG_F           PIN5
#define SEG_G           PIN6


/* Display Enable Port */

#define DISPLAY_PORT    GPIO_PORTE_BASE

#define DISPLAY1        PIN0
#define DISPLAY2        PIN1
#define DISPLAY3        PIN2
#define DISPLAY4        PIN3


/* Switch Port */

#define SWITCH_PORT     GPIO_PORTF_BASE

#define SW1             PIN0
#define SW2             PIN4


/* Function Prototypes */

void SevenSeg_Init(void);

void SevenSeg_Write(unsigned char value);

void SevenSeg_Enable1(void);
void SevenSeg_Enable2(void);
void SevenSeg_Enable3(void);
void SevenSeg_Enable4(void);

void SevenSeg_DisableAll(void);

void SevenSeg_Display(uint16_t number);

void SevenSeg_Refresh(uint16_t number);

void SevenSeg_Delay(unsigned int ms);

#endif