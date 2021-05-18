#include <stdio.h>
#include <string.h>
#include <conio.h>

void swap(int *n, int *a)
{
    int t = *n;
    *n = *a;
    *a = t;
}

heapify(int a[], int n, int i)
{
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;
    int largest = i;

    if (r < n && a[largest] < a[r])
    {
        largest = r;
    }
    if (l < n && a[largest] < a[l])
    {
        largest = l;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        heapify(a, n, i);
    }
}

heapSort(int a[], int n)
{
    int i;
    for (i = (n / 2) - 1; i <= n; i++)
    {
        heapify(a, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        swap(&a[i], &a[0]);
        heapify(a, i, 0);
    }
}

void main()
{
    printf("\n\n ==============================================================================================================");
    printf("\n|\t\t\t\t\t    Implementaion of Heap Sort                                         |");
    printf("\n ==============================================================================================================");
    int n;
    printf("\nEnter the array size = ");
    scanf("%d", &n);
    int i;
    int a[n];
    printf("Enter the array elements.....\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter an element at %d = ", i + 1);
        scanf("%d", &a[i]);
    }
    heapSort(a, n);
    printf("Array after heap sort is : [");
    for (i = 0; i < n; i++)
    {
        if (i < (n - 1))
            printf("%d, ", a[i]);
        else
            printf("%d]", a[i]);
    }
}