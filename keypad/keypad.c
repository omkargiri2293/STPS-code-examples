#include <stdint.h>

/* =========================================================
   CLOCK CONTROL REGISTERS
   ========================================================= */

#define SYSCTL_RCGCGPIO_R    (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCUART_R    (*((volatile uint32_t *)0x400FE618))


/* =========================================================
   GPIO PORT A REGISTERS - UART0
   ========================================================= */

#define GPIO_PORTA_DATA_R    (*((volatile uint32_t *)0x400043FC))
#define GPIO_PORTA_DIR_R     (*((volatile uint32_t *)0x40004400))
#define GPIO_PORTA_AFSEL_R   (*((volatile uint32_t *)0x40004420))
#define GPIO_PORTA_DEN_R     (*((volatile uint32_t *)0x4000451C))
#define GPIO_PORTA_PCTL_R    (*((volatile uint32_t *)0x4000452C))


/* =========================================================
   GPIO PORT C REGISTERS - KEYPAD COLUMNS
   ========================================================= */

#define GPIO_PORTC_DATA_R    (*((volatile uint32_t *)0x400063FC))
#define GPIO_PORTC_DIR_R     (*((volatile uint32_t *)0x40006400))
#define GPIO_PORTC_DEN_R     (*((volatile uint32_t *)0x4000651C))
#define GPIO_PORTC_PDR_R     (*((volatile uint32_t *)0x40006514))


/* =========================================================
   GPIO PORT E REGISTERS - KEYPAD ROWS
   ========================================================= */

#define GPIO_PORTE_DATA_R    (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTE_DIR_R     (*((volatile uint32_t *)0x40024400))
#define GPIO_PORTE_DEN_R     (*((volatile uint32_t *)0x4002451C))


/* =========================================================
   UART0 REGISTERS
   ========================================================= */

#define UART0_DR_R           (*((volatile uint32_t *)0x4000C000))
#define UART0_FR_R           (*((volatile uint32_t *)0x4000C018))
#define UART0_IBRD_R         (*((volatile uint32_t *)0x4000C024))
#define UART0_FBRD_R         (*((volatile uint32_t *)0x4000C028))
#define UART0_LCRH_R         (*((volatile uint32_t *)0x4000C02C))
#define UART0_CTL_R          (*((volatile uint32_t *)0x4000C030))
#define UART0_CC_R           (*((volatile uint32_t *)0x4000CFC8))


/* =========================================================
   FUNCTION PROTOTYPES
   ========================================================= */

void UART0_Init(void);
void UART0_WriteChar(char data);

void Keypad_Init(void);
char Keypad_GetKey(void);

void Delay(uint32_t delay);


/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main(void)
{
    char key;

    /* Initialize UART */
    UART0_Init();

    /* Initialize Keypad */
    Keypad_Init();

    /* Print startup message */
    UART0_WriteChar('\r');
    UART0_WriteChar('\n');

    while(1)
    {
        /* Wait until a key is pressed */
        key = Keypad_GetKey();

        /* Send pressed key to UART terminal */
        UART0_WriteChar(key);

        /* New line after every key press */
        UART0_WriteChar('\r');
        UART0_WriteChar('\n');

        /* Wait for key release */
        while((GPIO_PORTC_DATA_R & 0xF0) != 0)
        {
        }

        /* Small debounce delay */
        Delay(50000);
    }
}


/* =========================================================
   UART0 INITIALIZATION
   115200 Baud, 8-bit, No Parity, 1 Stop bit
   ========================================================= */

void UART0_Init(void)
{
    /* Enable clock for UART0 */
    SYSCTL_RCGCUART_R |= 0x01;

    /* Enable clock for GPIO Port A */
    SYSCTL_RCGCGPIO_R |= 0x01;


    /* Disable UART before configuration */
    UART0_CTL_R = 0;


    /*
       UART Clock = 16 MHz

       Baud Rate = 115200

       IBRD = 8
       FBRD = 44
    */

    UART0_IBRD_R = 8;
    UART0_FBRD_R = 44;


    /* 8-bit data, FIFO enabled */
    UART0_LCRH_R = 0x70;


    /* Use system clock */
    UART0_CC_R = 0x0;


    /*
       Configure PA0 = UART0 RX
       Configure PA1 = UART0 TX
    */

    GPIO_PORTA_AFSEL_R |= 0x03;

    GPIO_PORTA_DEN_R |= 0x03;

    GPIO_PORTA_PCTL_R =
        (GPIO_PORTA_PCTL_R & 0xFFFFFF00)
        | 0x00000011;


    /* Enable UART, TX and RX */
    UART0_CTL_R = 0x301;
}


/* =========================================================
   SEND ONE CHARACTER THROUGH UART
   ========================================================= */

void UART0_WriteChar(char data)
{
    /* Wait until UART transmit FIFO is not full */
    while(UART0_FR_R & 0x20)
    {
    }

    UART0_DR_R = data;
}


/* =========================================================
   KEYPAD INITIALIZATION
   ========================================================= */

void Keypad_Init(void)
{
    /*
       Enable clocks:

       Port C = 0x04
       Port E = 0x10
    */

    SYSCTL_RCGCGPIO_R |= 0x14;


    /* -------------------------------
       PORT C
       PC4-PC7 = INPUT
       Columns
       ------------------------------- */

    GPIO_PORTC_DEN_R |= 0xF0;

    GPIO_PORTC_DIR_R &= ~0xF0;

    /* Enable Pull-Down Resistors */
    GPIO_PORTC_PDR_R |= 0xF0;


    /* -------------------------------
       PORT E
       PE0-PE3 = OUTPUT
       Rows
       ------------------------------- */

    GPIO_PORTE_DEN_R |= 0x0F;

    GPIO_PORTE_DIR_R |= 0x0F;

    /* Initially all rows LOW */
    GPIO_PORTE_DATA_R &= ~0x0F;
}


/* =========================================================
   KEYPAD SCANNING FUNCTION
   ========================================================= */

char Keypad_GetKey(void)
{
    /* Keypad layout */

    char keypad[4][4] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };


    while(1)
    {
        /* Scan each row */

        for(int row = 0; row < 4; row++)
        {
            /* Make all rows LOW */
            GPIO_PORTE_DATA_R &= ~0x0F;

            /* Make current row HIGH */
            GPIO_PORTE_DATA_R |= (1 << row);


            /* Small delay */
            Delay(1000);


            /* Check Column 1 - PC4 */
            if(GPIO_PORTC_DATA_R & 0x10)
            {
                return keypad[row][0];
            }


            /* Check Column 2 - PC5 */
            if(GPIO_PORTC_DATA_R & 0x20)
            {
                return keypad[row][1];
            }


            /* Check Column 3 - PC6 */
            if(GPIO_PORTC_DATA_R & 0x40)
            {
                return keypad[row][2];
            }


            /* Check Column 4 - PC7 */
            if(GPIO_PORTC_DATA_R & 0x80)
            {
                return keypad[row][3];
            }
        }
    }
}


/* =========================================================
   SIMPLE DELAY
   ========================================================= */

void Delay(uint32_t delay)
{
    volatile uint32_t i;

    for(i = 0; i < delay; i++)
    {
        __asm("NOP");
    }
}