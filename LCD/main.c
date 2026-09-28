#include "LCD_lib.h"


int main(void)
{
    
    LCD_init();
    LCD_display(1,1,
        (unsigned char *)"omkar"  );

    LCD_display(
        2,
        1,
        (unsigned char *)"MIS no.- 5"
    );

    while(1)
    {
    }
}


