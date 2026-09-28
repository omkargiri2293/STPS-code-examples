#include "LCD lib.h"


/*------------------------------------------------
   GPIO Port B Base Address
  ------------------------------------------------*/
#define GPIO_PORTB_BASE       0x40005000


/*------------------------------------------------
   GPIO Register Offsets
  ------------------------------------------------*/
#define GPIO_AFSEL_OFFSET     0x420
#define GPIO_ODR_OFFSET       0x50C
#define GPIO_DEN_OFFSET       0x51C
#define GPIO_PCTL_OFFSET      0x52C


/*------------------------------------------------
   System Control Registers
  ------------------------------------------------*/
#define SYSCTL_RCGCGPIO_R     (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCI2C_R      (*((volatile uint32_t *)0x400FE620))


/*------------------------------------------------
   GPIO Port B Registers
  ------------------------------------------------*/
#define GPIO_PORTB_AFSEL_R    (*((volatile uint32_t *)(GPIO_PORTB_BASE + GPIO_AFSEL_OFFSET)))

#define GPIO_PORTB_ODR_R      (*((volatile uint32_t *)(GPIO_PORTB_BASE + GPIO_ODR_OFFSET)))

#define GPIO_PORTB_DEN_R      (*((volatile uint32_t *)(GPIO_PORTB_BASE + GPIO_DEN_OFFSET)))

#define GPIO_PORTB_PCTL_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + GPIO_PCTL_OFFSET)))


/*------------------------------------------------
   I2C Pin Definitions

   PB2 -> SDA
   PB3 -> SCL
  ------------------------------------------------*/
#define I2C_SDA_PIN           (1U << 2)
#define I2C_SCL_PIN           (1U << 3)


/*------------------------------------------------
   Delay Function
  ------------------------------------------------*/
void delay(unsigned int time)
{
    unsigned int i;
    unsigned int j;

    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 200; j++)
        {
        }
    }
}


/*------------------------------------------------
   I2C Initialization

   PB2 -> SDA
   PB3 -> SCL
  ------------------------------------------------*/
void I2C_Init(void)
{
    /*
     * Enable GPIO Port B clock
     */
    SYSCTL_RCGCGPIO_R |= (1U << 1);


    /*
     * Enable I2C0 clock
     */
    SYSCTL_RCGCI2C_R |= (1U << 0);


    /*
     * Delay for clock stabilization
     */
    delay(10);


    /*
     * Enable alternate function
     * for PB2 and PB3
     */
    GPIO_PORTB_AFSEL_R |=
        (I2C_SDA_PIN | I2C_SCL_PIN);


    /*
     * Configure PB2 and PB3
     * for I2C function
     */
    GPIO_PORTB_PCTL_R =
        (GPIO_PORTB_PCTL_R & 0xFFFF00FF) |
        0x00003300;


    /*
     * Enable open drain for SDA
     */
    GPIO_PORTB_ODR_R |= I2C_SDA_PIN;


    /*
     * Enable digital functionality
     */
    GPIO_PORTB_DEN_R |=
        (I2C_SDA_PIN | I2C_SCL_PIN);


    /*
     * Enable I2C master mode
     */
    I2C0_MCR_R = 0x10;


    /*
     * Set I2C clock to approximately 100 kHz
     *
     * Assuming system clock = 16 MHz
     */
    I2C0_MTPR_R = 7;
}


/*------------------------------------------------
   I2C Write

   Sends one byte to LCD backpack
  ------------------------------------------------*/
void I2C_Write(unsigned char data)
{
    /*
     * Set slave address
     *
     * LCD_I2C_ADDR is a 7-bit address.
     * Shift left by one bit for write.
     */
    I2C0_MSA_R =
        (LCD_I2C_ADDR << 1);


    /*
     * Put data into I2C data register
     */
    I2C0_MDR_R = data;


    /*
     * Start single byte transmission
     *
     * 0x07:
     * RUN + START + STOP
     */
    I2C0_MCS_R = 0x07;


    /*
     * Wait until transmission completes
     */
    while(I2C0_MCS_R & I2C_MASTER_RUN)
    {
    }


    /*
     * Small delay
     */
    delay(1);
}


/*------------------------------------------------
   Clear Data Pins
  ------------------------------------------------*/
void Clear_datapin(void)
{
    I2C_Write(0x00);
}


/*------------------------------------------------
   Set LCD Data Pins

   P0 -> D4
   P1 -> D5
   P2 -> D6
   P3 -> D7

   P6 -> Backlight
  ------------------------------------------------*/
void Setdata(unsigned char ch)
{
    unsigned char temp;


    /*
     * Keep only lower four bits
     */
    temp = ch & 0x0F;


    /*
     * Backlight ON
     */
    temp |= 0x40;


    /*
     * Send data
     */
    I2C_Write(temp);
}


/*------------------------------------------------
   LCD Enable Strobe
  ------------------------------------------------*/
void LCD_strobe(void)
{
    /*
     * EN = 1
     * Backlight = 1
     */
    I2C_Write(0x60);

    delay(1);


    /*
     * EN = 0
     * Backlight = 1
     */
    I2C_Write(0x40);

    delay(1);
}


/*------------------------------------------------
   Send Data / Character to LCD

   RS = 1
  ------------------------------------------------*/
void LCD_data(unsigned char ch)
{
    unsigned char temp;


    /*
     * HIGH NIBBLE
     */
    temp = (ch >> 4) & 0x0F;


    /*
     * RS = 1
     */
    temp |= 0x10;


    /*
     * Backlight ON
     */
    temp |= 0x40;


    /*
     * Send HIGH nibble
     */
    I2C_Write(temp);

    LCD_strobe();


    /*
     * LOW NIBBLE
     */
    temp = ch & 0x0F;


    /*
     * RS = 1
     */
    temp |= 0x10;


    /*
     * Backlight ON
     */
    temp |= 0x40;


    /*
     * Send LOW nibble
     */
    I2C_Write(temp);

    LCD_strobe();
}


/*------------------------------------------------
   Send Command to LCD

   RS = 0
  ------------------------------------------------*/
void LCD_cmd(unsigned char ch)
{
    unsigned char temp;


    /*
     * HIGH NIBBLE
     */
    temp = (ch >> 4) & 0x0F;


    /*
     * RS = 0
     */


    /*
     * Backlight ON
     */
    temp |= 0x40;


    /*
     * Send HIGH nibble
     */
    I2C_Write(temp);

    LCD_strobe();


    /*
     * LOW NIBBLE
     */
    temp = ch & 0x0F;


    /*
     * RS = 0
     */


    /*
     * Backlight ON
     */
    temp |= 0x40;


    /*
     * Send LOW nibble
     */
    I2C_Write(temp);

    LCD_strobe();


    /*
     * Delay after command
     */
    delay(2);
}


/*------------------------------------------------
   LCD Initialization
  ------------------------------------------------*/
void LCD_init(void)
{
    /*
     * Initialize I2C
     */
    I2C_Init();


    /*
     * Wait for LCD power-up
     */
    delay(50);


    /*
     * LCD initialization sequence
     */
    LCD_cmd(0x33);

    LCD_cmd(0x32);


    /*
     * 4-bit mode
     * 2 lines
     * 5x8 font
     */
    LCD_cmd(0x28);


    /*
     * Entry mode
     */
    LCD_cmd(0x06);


    /*
     * Display ON
     * Cursor OFF
     */
    LCD_cmd(0x0C);


    /*
     * Clear display
     */
    LCD_cmd(0x01);

    delay(5);


    /*
     * Cursor at first position
     */
    LCD_cmd(0x80);
}


/*------------------------------------------------
   Display String

   row = 1 -> First row
   row = 2 -> Second row

   pos = Starting position
  ------------------------------------------------*/
void LCD_display(int row, int pos, unsigned char *ch)
{
    unsigned char temp;


    if(row == 1)
    {
        /*
         * First row starts at 0x80
         */
        temp = (unsigned char)(0x80 + pos - 1);
    }
    else
    {
        /*
         * Second row starts at 0xC0
         */
        temp = (unsigned char)(0xC0 + pos - 1);
    }


    /*
     * Set cursor position
     */
    LCD_cmd(temp);


    /*
     * Display string
     */
    while(*ch)
    {
        LCD_data(*ch);

        ch++;
    }
}