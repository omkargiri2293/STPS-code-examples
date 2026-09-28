#include "LCD_lib.h"


/*------------------------------------------------
   LCD Initialization Nibble

   Used only during initial 4-bit mode setup
  ------------------------------------------------*/
static void LCD_send_nibble(unsigned char ch)
{
    Clear_datapin();

    Setdata(ch);

    LCD_strobe();
}


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
   Clear LCD Data Pins

   PB0 -> D4
   PB1 -> D5
   PB2 -> D6
   PB3 -> D7
  ------------------------------------------------*/
void Clear_datapin(void)
{
    GPIO_Write_Pin(GPIO_PORTB_BASE, PIN0, 0);
    GPIO_Write_Pin(GPIO_PORTB_BASE, PIN1, 0);
    GPIO_Write_Pin(GPIO_PORTB_BASE, PIN2, 0);
    GPIO_Write_Pin(GPIO_PORTB_BASE, PIN3, 0);
}


/*------------------------------------------------
   Set LCD Data Pins

   PB0 -> D4
   PB1 -> D5
   PB2 -> D6
   PB3 -> D7
  ------------------------------------------------*/
void Setdata(unsigned char ch)
{
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN0,
        ch & 0x01
    );

    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN1,
        (ch >> 1) & 0x01
    );

    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN2,
        (ch >> 2) & 0x01
    );

    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN3,
        (ch >> 3) & 0x01
    );
}


/*------------------------------------------------
   LCD Enable Strobe
  ------------------------------------------------*/
void LCD_strobe(void)
{
    delay(1);

    /* EN = 1 */
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN5,
        1
    );

    delay(1);

    /* EN = 0 */
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN5,
        0
    );

    delay(1);
}


/*------------------------------------------------
   Send Data / Character

   RS = 1
  ------------------------------------------------*/
void LCD_data(unsigned char ch)
{
    /* RS = 1 */
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN4,
        1
    );


    /* HIGH NIBBLE */
    Clear_datapin();

    Setdata((ch >> 4) & 0x0F);

    LCD_strobe();


    /* LOW NIBBLE */
    Clear_datapin();

    Setdata(ch & 0x0F);

    LCD_strobe();
}


/*------------------------------------------------
   Send Command

   RS = 0
  ------------------------------------------------*/
void LCD_cmd(unsigned char ch)
{
    /* RS = 0 */
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN4,
        0
    );


    /* HIGH NIBBLE */
    Clear_datapin();

    Setdata((ch >> 4) & 0x0F);

    LCD_strobe();


    /* LOW NIBBLE */
    Clear_datapin();

    Setdata(ch & 0x0F);

    LCD_strobe();


    delay(2);
}


/*------------------------------------------------
   LCD Initialization
  ------------------------------------------------*/
void LCD_init(void)
{
    /*--------------------------------------------
       Initialize GPIO Port B
      --------------------------------------------*/
    GPIO_Init_Clock(GPIO_PORTB_BASE);


    /*--------------------------------------------
       PB0 -> D4
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN0,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       PB1 -> D5
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN1,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       PB2 -> D6
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN2,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       PB3 -> D7
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN3,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       PB4 -> RS
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN4,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       PB5 -> EN
      --------------------------------------------*/
    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        PIN5,
        OUTPUT,
        PULL_DISABLE
    );


    /*--------------------------------------------
       Initial states
      --------------------------------------------*/
    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN4,
        0
    );

    GPIO_Write_Pin(
        GPIO_PORTB_BASE,
        PIN5,
        0
    );


    /*--------------------------------------------
       Wait for LCD power-up
      --------------------------------------------*/
    delay(100);


    /*--------------------------------------------
       Force LCD into 4-bit mode

       LCD initially starts in 8-bit mode.

       Send 0x03 three times.
      --------------------------------------------*/

    LCD_send_nibble(0x03);

    delay(10);

    LCD_send_nibble(0x03);

    delay(10);

    LCD_send_nibble(0x03);

    delay(10);


    /*--------------------------------------------
       Select 4-bit mode
      --------------------------------------------*/
    LCD_send_nibble(0x02);

    delay(10);


    /*--------------------------------------------
       Function Set

       4-bit mode
       2 lines
       5x8 font
      --------------------------------------------*/
    LCD_cmd(0x28);


    /*--------------------------------------------
       Display ON
       Cursor OFF
       Blink OFF
      --------------------------------------------*/
    LCD_cmd(0x0C);


    /*--------------------------------------------
       Entry Mode

       Cursor moves right
      --------------------------------------------*/
    LCD_cmd(0x06);


    /*--------------------------------------------
       Clear Display
      --------------------------------------------*/
    LCD_cmd(0x01);

    delay(10);


    /*--------------------------------------------
       Cursor at first position
      --------------------------------------------*/
    LCD_cmd(0x80);
}


/*------------------------------------------------
   Display String

   row = 1 -> First row
   row = 2 -> Second row

   pos = Starting position
  ------------------------------------------------*/
void LCD_display(
    int row,
    int pos,
    unsigned char *ch
)
{
    unsigned char temp;


    if(row == 1)
    {
        /* First row */
        temp = (unsigned char)(0x80 + pos - 1);
    }
    else
    {
        /* Second row */
        temp = (unsigned char)(0xC0 + pos - 1);
    }


    /* Set cursor position */
    LCD_cmd(temp);


    /* Display string */
    while(*ch)
    {
        LCD_data(*ch);

        ch++;
    }
}