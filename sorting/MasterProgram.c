#include <stdio.h>
#include <conio.h>

void bubble(int ar[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j <= n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    printf("sorted array \n");
    for (int x = 0; x < n; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

void insertion(int ar[], int n)
{

    int i, j, key;
    for (j = 1; j < n; j++)
    {
        key = ar[j];
        i = j - 1;
        while (i >= 0 && ar[i] > key)
        {
            ar[i + 1] = ar[i];
            i = i - 1;
        }
        ar[i + 1] = key;
    }
    printf("sorted array after insertion sorting \n");
    for (int x = 0; x < n; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

void selection(int ar[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[min])
            {
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }
    printf("sorted array after Selection sorting \n");
    for (int x = 0; x < n; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

void merge(int ar[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];

    while (i <= mid && j <= high)
    {
        if (ar[i] < ar[j])
        {
            b[k] = ar[i];
            i++;
            k++;
        }
        else
        {
            b[k] = ar[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = ar[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = ar[j];
        j++;
        k++;
    }

    for (int m = 0; m <= high; m++)
    {
        ar[m] = b[m];
    }
}

void mergeSort(int ar[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(ar, low, mid);
        mergeSort(ar, mid + 1, high);
        merge(ar, mid, low, high);
    }
}
void display(int ar[], int n)
{

    printf("sorted array \n");
    for (int x = 0; x < n; x++)
    {
        printf("%d -> ", ar[x]);
    }
}

int main()
{

    int ch;
    int n;
    int ar[100];

    printf("Input size of array \n");
    scanf("%d", &n);

    printf("Input elements in array of size %d\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    printf("1---------- for bubble sort\n");
    printf("2---------- for selection sort\n");
    printf("3---------- for insertion sort\n");
    printf("4---------- for Merge sort\n");
    printf("5---------- for Quick sort sort\n5");

    printf("enter choice");

    scanf("%d", &ch);

    switch (ch)
    {

    case 1:
    {

        bubble(ar, n);
        break;
    }
    case 2:
    {
        selection(ar, n);
        break;
    }
    case 3:
    {
        insertion(ar, n);
        break;
    }
    case 4:
    {
        int low = 0;
        mergeSort(ar, low, n);
        display(ar, n);
        break;
    }
    default:
        printf("wrong choice");
        break;
    }
}