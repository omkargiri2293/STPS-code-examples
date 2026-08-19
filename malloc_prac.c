//malloc() =allocates requested no of bytes
//calloc() =allocates space for array of elements,initialize all of them to zero
//free() = frees previously allocated space
//realloc()=modifies prv allocated space

#include<stdio.h>
#include<stdint.h>

void main(){

    int i,N;
    float *height;

    int sum=0,avg;
    printf("enter no of students=");
    scanf("%d",&N);

    height=(float *)malloc(N * sizeof(float));

    printf("enter height of %d students : ",N);
    for(i=1;i<N;i++){
        scanf("%d",&height[i]);
    }
    for(i=1;i<N;i++){
        sum+=height[i];
    }
    avg=sum/(float)N;
printf("average height of %d students =%f",N,avg);

}