// example of quick sort
// 
#include <stdio.h>

void quick_sort(int a[], int l, int r);
int partition(int a[], int l, int r);

int main()
{
    int i;
    //int a[] = {11, 22, 66, 44, 99, 33, 77, 55, 88};

    int a[]={7,12,1,-2,0,15,4,11,9};
    printf("Unsorted array: ");

    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }

    quick_sort(a, 0, 8);

    printf("\nSorted array: ");

    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}


void quick_sort(int a[], int l, int r)
{
    int j;
   

    if (l < r)
    {
        j = partition(a, l, r);
         printf("\npartition array j=%d r=%d l=%d ",j,r,l);
         for(int k=0;k<9;k++){
            //printf("%d",a[j]);
         }

        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
    }
}


int partition(int a[], int l, int r)
{
    int i, j, pivot, temp;

    pivot = a[l];

    i = l;
    j = r;

    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    /* Put pivot in its correct position */
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}