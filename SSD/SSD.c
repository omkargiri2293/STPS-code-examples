#include "SSD_Lib.h"


int main(void)
{
    uint16_t count = 0;

    SevenSeg_Init();

    GPIO_Init_Clock(SWITCH_PORT);


    /* PF0 = SW1
       UP COUNT */

    GPIO_Init_Pin(SWITCH_PORT,
                  SW1,
                  INPUT,
                  PULL_ENABLE);


    /* PF4 = SW2
       DOWN COUNT */

    GPIO_Init_Pin(SWITCH_PORT,
                  SW2,
                  INPUT,
                  PULL_ENABLE);


    while(1)
    {
        /* Continuously refresh display */

        SevenSeg_Refresh(count);

        if(GPIO_Read_Pin(SWITCH_PORT, SW1) == 0)
        {
            /* Debounce delay */

            SevenSeg_Delay(20);


            /* Check again */

            if(GPIO_Read_Pin(SWITCH_PORT, SW1) == 0)
            {
                /* Maximum count = 15 */

                if(count < 15)
                {
                    count++;
                }


                /* Wait until switch is released */

                while(GPIO_Read_Pin(SWITCH_PORT,
                                   SW1) == 0)
                {
                    SevenSeg_Refresh(count);
                }
            }
        }

        if(GPIO_Read_Pin(SWITCH_PORT, SW2) == 0)
        {
            /* Debounce delay */

            SevenSeg_Delay(20);


            /* Check again */

            if(GPIO_Read_Pin(SWITCH_PORT, SW2) == 0)
            {
                /* Minimum count = 0 */

                if(count > 0)
                {
                    count--;
                }


                /* Wait until switch is released */

                while(GPIO_Read_Pin(SWITCH_PORT,
                                   SW2) == 0)
                {
                    SevenSeg_Refresh(count);
                }
            }
        }
    }
}