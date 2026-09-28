#ifndef LCD_LIB_H
#define LCD_LIB_H

#include <stdint.h>
#include "GPIO_lib.h"


/*------------------------------------------------
   LCD Pin Connections

   PB0 -> LCD D4
   PB1 -> LCD D5
   PB2 -> LCD D6
   PB3 -> LCD D7
   PB4 -> LCD RS
   PB5 -> LCD EN
  ------------------------------------------------*/

#define LCD_DATA_PORT      GPIO_PORTB_BASE

#define LCD_D4             PIN0
#define LCD_D5             PIN1
#define LCD_D6             PIN2
#define LCD_D7             PIN3

#define LCD_RS             PIN4
#define LCD_EN             PIN5


/*------------------------------------------------
   LCD Functions
  ------------------------------------------------*/

void LCD_init(void);

void LCD_cmd(unsigned char ch);

void LCD_data(unsigned char ch);

void LCD_strobe(void);

void LCD_display(int row, int pos, unsigned char *ch);

void Clear_datapin(void);

void Setdata(unsigned char ch);

void delay(unsigned int time);


#endif