//write code to display digit on 7 segment display
#include <stdio.h>
int main() { 
    
    int digit;
    printf("Enter a digit (0-9): ");
    scanf("%d", &digit);

    switch(digit) {
        case 0:
            printf("7-segment display: 0\n");
            break;
        case 1:
            printf("7-segment display: 1\n");
            break;
        case 2:
            printf("7-segment display: 2\n");
            break;
        case 3:
            printf("7-segment display: 3\n");
            break;
        case 4:
            printf("7-segment display: 4\n");
            break;
        case 5:
            printf("7-segment display: 5\n");
            break;
        case 6:
            printf("7-segment display: 6\n");
            break;
        case 7:
            printf("7-segment display: 7\n");
            break;
        case 8:
            printf("7-segment display: 8\n");
            break;
        case 9:
            printf("7-segment display: 9\n");
            break;
        default:
            printf("Invalid input. Please enter a digit between 0 and 9.\n");
    }

    return 0;
}