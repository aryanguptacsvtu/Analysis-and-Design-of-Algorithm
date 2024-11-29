// C program to implement Merge Sort
#include <stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            i++;
            k++;
        }
        else
        {
            B[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = B[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[] = {12, 45, 22, 66, 88, 97, 34};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original Array:");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("\nSorted Array:");
    printArray(a, n);

    return 0;
}