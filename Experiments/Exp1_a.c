// C program to implement Insertion Sort
#include <stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void insertionSort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {12, 45, 22, 66, 88, 97, 34};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original Array:");
    printArray(a, n);

    insertionSort(a, n);

    printf("\nSorted Array:");
    printArray(a, n);

    return 0;
}