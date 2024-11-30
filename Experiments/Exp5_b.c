// C program to implement Linear Search
#include <stdio.h>

void linearSearch(int a[], int n, int key)
{
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("Element not found.\n");
    }
}

int main()
{
    int a[] = {13, 543, 23, 66, 1};
    int n = sizeof(a) / sizeof(a[0]);

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    linearSearch(a, n, key);
    return 0;
}