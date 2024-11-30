// C program to implement Matrix Multiplication
#include <stdio.h>

int main()
{
    int row1, col1, row2, col2;

    printf("Enter rows & columns for first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows & columns for second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2)
    {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
        }
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nFirst Matrix:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant matrix after multiplication:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
