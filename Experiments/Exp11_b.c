// C program to implement Counting Inversions.
#include <stdio.h>


int merge(int arr[], int temp[], int left, int mid, int right) // Merge function that merges two sorted subarrays & counts the inversions
{
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // All remaining elements in left subarray are greater than arr[j]
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeAndCount(int arr[], int temp[], int left, int right)   // Merge function to merge two halves of the array
{
    int mid, i, j, k;
    int inv_count = 0;

    if (left < right)
    {
        mid = (left + right) / 2;

        inv_count += mergeAndCount(arr, temp, left, mid);      // Count inversions in left half
        inv_count += mergeAndCount(arr, temp, mid + 1, right); // Count inversions in right half

        inv_count += merge(arr, temp, left, mid, right); // Count and merge the two halves
    }

    return inv_count;
}

int countInversions(int arr[], int n) // Wrapper function that initiates merge sort and counts inversions
{
    int temp[n];
    return mergeAndCount(arr, temp, 0, n - 1);
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, n);
    printf("Number of inversions: %d\n", result);

    return 0;
}
