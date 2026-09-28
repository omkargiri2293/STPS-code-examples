#ifndef LCD_LIB_H
#define LCD_LIB_H

#include <stdint.h>


/*------------------------------------------------
   I2C0 Base Address
  ------------------------------------------------*/
#define I2C0_BASE       0x40020000


/*------------------------------------------------
   I2C0 Register Offsets
  ------------------------------------------------*/
#define I2C_MSA_OFFSET  0x000
#define I2C_MCS_OFFSET  0x004
#define I2C_MDR_OFFSET  0x008
#define I2C_MTPR_OFFSET 0x00C
#define I2C_MCR_OFFSET  0x020


/*------------------------------------------------
   I2C0 Registers
  ------------------------------------------------*/
#define I2C0_MSA_R  (*((volatile uint32_t *)(I2C0_BASE + I2C_MSA_OFFSET)))
#define I2C0_MCS_R  (*((volatile uint32_t *)(I2C0_BASE + I2C_MCS_OFFSET)))
#define I2C0_MDR_R  (*((volatile uint32_t *)(I2C0_BASE + I2C_MDR_OFFSET)))
#define I2C0_MTPR_R (*((volatile uint32_t *)(I2C0_BASE + I2C_MTPR_OFFSET)))
#define I2C0_MCR_R  (*((volatile uint32_t *)(I2C0_BASE + I2C_MCR_OFFSET)))


/*------------------------------------------------
   I2C Master Control
  ------------------------------------------------*/
#define I2C_MASTER_RUN       0x01
#define I2C_MASTER_START     0x02
#define I2C_MASTER_STOP      0x04
#define I2C_MASTER_ACK       0x08


/*------------------------------------------------
   LCD I2C Address
  ------------------------------------------------*/
#define LCD_I2C_ADDR        0x27


/*------------------------------------------------
   LCD Backpack Pin Mapping

   P0 -> D4
   P1 -> D5
   P2 -> D6
   P3 -> D7
   P4 -> RS
   P5 -> EN
   P6 -> Backlight
   P7 -> Not used
  ------------------------------------------------*/


/*------------------------------------------------
   Function Prototypes
  ------------------------------------------------*/

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