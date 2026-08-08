/*
1. Stack memory stores all the local variables and function calls (static memory).
Example: int a = 10;

2. Heap memory stores all the dynamically allocated variables.
Example: int *ptr = malloc(sizeof(int)); 
Here, memory will be allocated in the heap section. 
And the ptr resides in the stack section and receives the 
heap section memory address on successful memory allocation.

3. Address of the dynamic memory which will be assigned to the corresponding variable.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr;
    int value=10;
    ptr = (int *)malloc(value * sizeof(int));
    printf("Value stored in allocated memory: %d\n", *ptr);
    free(ptr);
    return 0;   
}