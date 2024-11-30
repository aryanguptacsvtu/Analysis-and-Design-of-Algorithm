// C program to implement Binary Search
#include <stdio.h>

void binarySearch(int a[], int key, int low, int high)
{
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            return;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Element not found.\n");
}

int main()
{
    int a[] = {12, 33, 56, 78, 100};
    int n = sizeof(a) / sizeof(a[0]);

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    binarySearch(a, key, 0, n - 1);
    return 0;
}