#include <stdio.h>

void bubble_sort(int x[], int size)
{
    int i, j, t;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                // Swap x[j] and x[j+1]
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}

int main()
{
    int x[20] = {
        65, 55, 12, -22, 21,
        90, 34, 56, 78, 30,
        69, 47, 89, 1, 5,
        32, 76, 8, 50, 77
    };

    bubble_sort(x, 20);

    printf("Sorted array: ");

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}