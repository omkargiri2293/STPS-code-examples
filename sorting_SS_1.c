#include <stdio.h>

/* Find the location of minimum element */
int min_loc(int arr[], int k, int size)
{
    int j, pos;

    pos = k;

    for (j = k + 1; j < size; j++)
    {
        if (arr[j] < arr[pos])
        {
            pos = j;
        }
    }

    return pos;
}


/* Sort arr[0..size-1] in non-decreasing order */
void sel_sort(int arr[], int size)
{
    int k, m, temp;


    for (k = 0; k < size - 1; k++)
    {
        m = min_loc(arr, k, size);

        temp = arr[k];
        arr[k] = arr[m];
        arr[m] = temp;

        printf("\niteration %d: ",k+1);

        for(int i =0;i<size;i++){
            printf("%d ",arr[i]);
        }
    }
}


int main()
{
    int arr[20] = {
        65, 55, 12, 22, 21,
        90, 34, 56, 78, 30,
        69, 47, 89, 1, 5,
        32, 76, 8, 50, 77
    };


    sel_sort(arr, 20);

    printf("\nSorted array:");

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}