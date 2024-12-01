// C program to implement range minima problem.
#include <stdio.h>
#include <limits.h>

void buildSegmentTree(int arr[], int segTree[], int start, int end, int node)
{
    if (start == end)
    {
        segTree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildSegmentTree(arr, segTree, start, mid, 2 * node + 1);
        buildSegmentTree(arr, segTree, mid + 1, end, 2 * node + 2);
        segTree[node] = (segTree[2 * node + 1] < segTree[2 * node + 2]) ? segTree[2 * node + 1] : segTree[2 * node + 2];
    }
}

int rangeMinQuery(int segTree[], int start, int end, int L, int R, int node)
{
    if (R < start || L > end)
    {
        return INT_MAX;
    }

    if (L <= start && end <= R)
    {
        return segTree[node];
    }

    int mid = (start + end) / 2;
    int leftMin = rangeMinQuery(segTree, start, mid, L, R, 2 * node + 1);
    int rightMin = rangeMinQuery(segTree, mid + 1, end, L, R, 2 * node + 2);
    return (leftMin < rightMin) ? leftMin : rightMin;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int segTree[4 * n];
    buildSegmentTree(arr, segTree, 0, n - 1, 0);

    int queries;
    printf("Enter the number of queries: ");
    scanf("%d", &queries);

    while (queries--)
    {
        int L, R;
        printf("Enter the range (L R): ");
        scanf("%d %d", &L, &R);

        if (L < 0 || R >= n || L > R)
        {
            printf("Invalid range.\n");
        }
        else
        {
            int minVal = rangeMinQuery(segTree, 0, n - 1, L, R, 0);
            printf("Minimum in range [%d, %d] is: %d\n", L, R, minVal);
        }
    }

    return 0;
}
