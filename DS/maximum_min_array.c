#include <stdio.h>

void max_min(int ar[], int size)
{
    int max = ar[0];
    int min = ar[1];
    for (int i = 0; i < size; i++)
    {
        if (ar[i] >= max)
        {
            max = ar[i];
        }
        else if (ar[i] <= min)
        {
            min = ar[i];
        }
    }
    printf("greatest number is %d", max);
    printf("minimum number is %d", min);
}

int main()
{
    int arr[] = {66, 32, 2, 678, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    max_min(arr, n);
}