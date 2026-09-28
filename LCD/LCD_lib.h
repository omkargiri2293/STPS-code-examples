#ifndef LCD_LIB_H
#define LCD_LIB_H

#include <stdint.h>

/* LCD Functions */
void delay(unsigned int time);
void I2C_Init(void);
void I2C_Write(unsigned char data);
void LCD_strobe(void);
void LCD_data(unsigned char ch);
void LCD_cmd(unsigned char ch);
void LCD_init(void);
void LCD_display(int row, int pos, unsigned char *ch);
void Clear_datapin(void);
void Setdata(unsigned char ch);

#endif