// C program to find a local minima in grid
#include <stdio.h>

int findLocalMinima(int grid[][100], int rows, int cols)
{
    int midCol = cols / 2; // Middle column

    // Find the row with the minimum value in the middle column
    int minRow = 0;
    for (int i = 1; i < rows; i++)
    {
        if (grid[i][midCol] < grid[minRow][midCol])
        {
            minRow = i;
        }
    }

    // Check if the middle column's minimum is a local minima
    int left = (midCol > 0) ? grid[minRow][midCol - 1] : __INT_MAX__;

    int right = (midCol < cols - 1) ? grid[minRow][midCol + 1] : __INT_MAX__;

    if (grid[minRow][midCol] < left && grid[minRow][midCol] < right)
    {
        return grid[minRow][midCol]; // Local minima found
    }

    // Recurse on the left or right half based on the neighboring values
    if (left < grid[minRow][midCol])
    {
        int newGrid[rows][100];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < midCol; j++)
            {
                newGrid[i][j] = grid[i][j];
            }
        }
        return findLocalMinima(newGrid, rows, midCol);
    }
    else
    {
        int newGrid[rows][100];
        for (int i = 0; i < rows; i++)
        {
            for (int j = midCol + 1; j < cols; j++)
            {
                newGrid[i][j - midCol - 1] = grid[i][j];
            }
        }
        return findLocalMinima(newGrid, rows, cols - midCol - 1);
    }
}

int main()
{
    int grid[100][100];
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter grid elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("The grid is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int localMinima = findLocalMinima(grid, rows, cols);

    printf("The local minima is: %d\n", localMinima);

    return 0;
}
