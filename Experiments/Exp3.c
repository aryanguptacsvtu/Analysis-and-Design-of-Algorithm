//C program to implement Heap Sort
#include <stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int greatest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[greatest])
    {
        greatest = left;
    }

    if (right < n && a[right] > a[greatest])
    {
        greatest = right;
    }

    if (greatest != i)
    {
        swap(&a[i], &a[greatest]);
        heapify(a, n, greatest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {57, 5, 78, 23, 788};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original Array:");
    printArray(a, n);

    heapSort(a, n);

    printf("\nSorted Array:");
    printArray(a, n);

    return 0;
}