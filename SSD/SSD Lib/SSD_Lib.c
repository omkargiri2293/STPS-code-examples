#include "SSD_Lib.h"


/* ========================================
   COMMON ANODE SEGMENT MAP

   PB0 -> a
   PB1 -> b
   PB2 -> c
   PB3 -> d
   PB4 -> e
   PB5 -> f
   PB6 -> g

   Common Anode:

   0 = Segment ON
   1 = Segment OFF

   Only 0 and 1 are required.
   ======================================== */

static const unsigned char seg_map[2] =
{
    0x40,       /* 0 */
    0x79        /* 1 */
};


/* ========================================
   DELAY FUNCTION
   ======================================== */

void SevenSeg_Delay(unsigned int ms)
{
    volatile unsigned int i;
    volatile unsigned int j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 3180; j++)
        {
        }
    }
}


/* ========================================
   INITIALIZE SSD
   ======================================== */

void SevenSeg_Init(void)
{
    /* Enable Port B clock */

    GPIO_Init_Clock(SEG_PORT);


    /* Enable Port E clock */

    GPIO_Init_Clock(DISPLAY_PORT);


    /* Configure PB0-PB6 as outputs */

    GPIO_Init_Pin(SEG_PORT, SEG_A,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_B,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_C,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_D,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_E,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_F,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(SEG_PORT, SEG_G,
                  OUTPUT, PULL_DISABLE);
									
		GPIO_Init_Pin(SEG_PORT, SEG_DP,
                  OUTPUT, PULL_DISABLE);
 

    /* Configure PE0-PE3 as outputs */

    GPIO_Init_Pin(DISPLAY_PORT, DISPLAY1,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(DISPLAY_PORT, DISPLAY2,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(DISPLAY_PORT, DISPLAY3,
                  OUTPUT, PULL_DISABLE);

    GPIO_Init_Pin(DISPLAY_PORT, DISPLAY4,
                  OUTPUT, PULL_DISABLE);


    /* Common Anode:
       All segments OFF = HIGH */

    GPIO_Write_Pin(SEG_PORT, SEG_A, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_B, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_C, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_D, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_E, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_F, 1);
    GPIO_Write_Pin(SEG_PORT, SEG_G, 1);
		GPIO_Write_Pin(SEG_PORT, SEG_DP, 1);


    /* Disable all displays */

    SevenSeg_DisableAll();
}


/* ========================================
   WRITE ONE DIGIT

   value = 0 or 1
   ======================================== */

void SevenSeg_Write(unsigned char value)
{
    unsigned char data;

    if(value > 1)
    {
        value = 0;
    }

    data = seg_map[value];


    GPIO_Write_Pin(SEG_PORT,
                   SEG_A,
                   data & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_B,
                   (data >> 1) & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_C,
                   (data >> 2) & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_D,
                   (data >> 3) & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_E,
                   (data >> 4) & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_F,
                   (data >> 5) & 0x01);

    GPIO_Write_Pin(SEG_PORT,
                   SEG_G,
                   (data >> 6) & 0x01);
									 
		GPIO_Write_Pin(SEG_PORT, SEG_DP, 1);
									 
}


/* ========================================
   DISABLE ALL 4 DISPLAYS
   ======================================== */

void SevenSeg_DisableAll(void)
{
    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY1,
                   0);

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY2,
                   0);

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY3,
                   0);

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY4,
                   0);
}


/* ========================================
   ENABLE DISPLAY 1
   ======================================== */

void SevenSeg_Enable1(void)
{
    SevenSeg_DisableAll();

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY1,
                   1);
}


/* ========================================
   ENABLE DISPLAY 2
   ======================================== */

void SevenSeg_Enable2(void)
{
    SevenSeg_DisableAll();

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY2,
                   1);
}


/* ========================================
   ENABLE DISPLAY 3
   ======================================== */

void SevenSeg_Enable3(void)
{
    SevenSeg_DisableAll();

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY3,
                   1);
}


/* ========================================
   ENABLE DISPLAY 4
   ======================================== */

void SevenSeg_Enable4(void)
{
    SevenSeg_DisableAll();

    GPIO_Write_Pin(DISPLAY_PORT,
                   DISPLAY4,
                   1);
}


/* ========================================
   DISPLAY 4-BIT BINARY NUMBER

   Example:

   number = 5

   Binary = 0101

   Display1 = 0
   Display2 = 1
   Display3 = 0
   Display4 = 1
   ======================================== */

void SevenSeg_Display(uint16_t number)
{
    unsigned char digit1;
    unsigned char digit2;
    unsigned char digit3;
    unsigned char digit4;


    /* Extract 4 bits */

    digit1 = (number >> 3) & 0x01;

    digit2 = (number >> 2) & 0x01;

    digit3 = (number >> 1) & 0x01;

    digit4 = number & 0x01;


    /* ---------- DISPLAY 1 ---------- */

    SevenSeg_DisableAll();

    SevenSeg_Write(digit1);

    SevenSeg_Enable1();

    SevenSeg_Delay(2);


    /* ---------- DISPLAY 2 ---------- */

    SevenSeg_DisableAll();

    SevenSeg_Write(digit2);

    SevenSeg_Enable2();

    SevenSeg_Delay(2);


    /* ---------- DISPLAY 3 ---------- */

    SevenSeg_DisableAll();

    SevenSeg_Write(digit3);

    SevenSeg_Enable3();

    SevenSeg_Delay(2);


    /* ---------- DISPLAY 4 ---------- */

    SevenSeg_DisableAll();

    SevenSeg_Write(digit4);

    SevenSeg_Enable4();

    SevenSeg_Delay(2);


    /* Disable after scanning */

    SevenSeg_DisableAll();
}


/* ========================================
   REFRESH DISPLAY

   Multiplex the display repeatedly.
   ======================================== */

void SevenSeg_Refresh(uint16_t number)
{
    unsigned int i;

    for(i = 0; i < 5; i++)
    {
        SevenSeg_Display(number);
    }
}