// C program to implement majority element problem.
#include <stdio.h>

// Function to find the candidate for majority element
int findCandidate(int arr[], int n)
{
    int candidate = arr[0], count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

// Function to check if the candidate is a majority element
int isMajority(int arr[], int n, int candidate)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    return count > n / 2;
}

// Function to find the majority element
void findMajorityElement(int arr[], int n)
{
    int candidate = findCandidate(arr, n);

    if (isMajority(arr, n, candidate))
    {
        printf("Majority element is: %d\n", candidate);
    }
    else
    {
        printf("No majority element exists.\n");
    }
}

// Main function
int main()
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajorityElement(arr, n);

    return 0;
}
