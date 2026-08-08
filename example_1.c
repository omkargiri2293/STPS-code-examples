// write code to read keypad inputs
#include <stdio.h>

int main() {
    char input;
    printf("Press a key on the keypad (0-9, A-D, *, #): ");
    scanf(" %c", &input);

    switch(input) {
        case '0':
            printf("You pressed 0\n");
            break;
        case '1':
            printf("You pressed 1\n");
            break;
        case '2':
            printf("You pressed 2\n");
            break;
        case '3':
            printf("You pressed 3\n");
            break;
        case '4':
            printf("You pressed 4\n");
            break;
        case '5':
            printf("You pressed 5\n");
            break;
        case '6':
            printf("You pressed 6\n");
            break;
        case '7':
            printf("You pressed 7\n");
            break;
        case '8':
            printf("You pressed 8\n");
            break;
        case '9':
            printf("You pressed 9\n");
            break;
        case 'A':
        case 'a':
            printf("You pressed A\n");
            break;
        case 'B':
        case 'b':
            printf("You pressed B\n");
            break;
        case 'C':
        case 'c':
            printf("You pressed C\n");
            break;
        case 'D':
        case 'd':
            printf("You pressed D\n");
            break;
        case '*':
            printf("You pressed *\n");
            break;
        case '#':
            printf("You pressed #\n");
            break;
        default:
            printf("Invalid key pressed!\n");
    }

    return 0;
}