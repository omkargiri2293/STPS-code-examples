//write program to write character on LCD
#include<stdio.h>
int main(){
    char ch;
    printf("Enter a character to display on LCD: ");
    scanf(" %c", &ch);
    printf("Character displayed on LCD: %c\n", ch);
    return 0;
}