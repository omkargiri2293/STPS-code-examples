#include <stdio.h>

//Find minimum element location
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

//Selection Sort 
void sel_sort(int arr[], int size)
{
    int k, m, temp;

    for (k = 0; k < size - 1; k++)
    {
        m = min_loc(arr, k, size);

        printf("\nIteration %d", k + 1);
        printf(" : arr[%d] = %d, arr[%d] = %d",
               k, arr[k], m, arr[m]);

        // Swap 
        temp = arr[k];
        arr[k] = arr[m];
        arr[m] = temp;

        printf("\nArray: ");

        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
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

    printf("\nSorted array:\n");

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}