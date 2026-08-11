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

/* Selection Sort */
void sel_sort(int arr[], int size)
{
    int k, m, temp;
    int i;

    for (k = 0; k < size - 1; k++)
    {
        m = min_loc(arr, k, size);

        temp = arr[k];
        arr[k] = arr[m];
        arr[m] = temp;

        /* i loop count */
        for (i = 0; i < size; i++)
        {
            // only counting
        }

        printf("Iteration %2d : i = %2d, j = %2d\n",
               k + 1, i, size - k - 1);
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

    return 0;
}