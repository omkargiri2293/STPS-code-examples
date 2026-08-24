/*insert node at end of an array
case 1- Array is not full
case 2- Array is full

*/

//case 1-array is not full
//time complexity = O(1)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10];
    int i,n,freepos;

    printf("enter no of elements = ");
    scanf("%d",&n);
    printf("enter %d elements = ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    freepos=n;
    freepos=add_at_end(a,freepos,22);

    for(i=0;i<freepos;i++){
        printf("no of elements in array = ",a[i]);
    }
    return 0;

}

int add_at_end(int a[],int freepos,int value){
    a[freepos]=value;
    freepos++;
    return freepos;
}