// C program to implement Bubble Sort
#include <stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {46, 78, 12, 89, 321, 90};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original Array:");
    printArray(a, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array:");
    printArray(a, n);

    return 0;
}