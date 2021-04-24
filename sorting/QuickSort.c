#include <stdio.h>
#include <conio.h>

int partition(int a[], int low, int high)
{

    int pivot = a[low];
    int i = low + 1;
    int j = high;

    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    } while (i < j);

    temp = a[j];
    a[j] = a[low];
    a[low] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{

    int partitionIndex;

    if (low < high)
    {

        partitionIndex = partition(a, low, high);

        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

void display(int ar[], int h)
{
    printf("sorted array \n");
    for (int x = 0; x <= h; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

int main()
{

    int ar[] = {434, 5, 6, 33, 2, 23, 1};
    int l = 0;
    int h = 6;

    quickSort(ar, l, h);
    display(ar, h);
}
