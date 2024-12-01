// C program to implement Shortest path in grid.
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

struct Cell
{
    int x, y, dist;
};

// Check if a cell is valid for movement
int isValid(int x, int y, int grid[ROW][COL], int visited[ROW][COL])
{
    return x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] && !visited[x][y];
}

// Find the shortest path using BFS
int shortestPath(int grid[ROW][COL], int startX, int startY, int endX, int endY)
{
    if (!grid[startX][startY] || !grid[endX][endY])
    {
        return -1;
    }

    int visited[ROW][COL] = {0};
    struct Cell queue[ROW * COL];
    int front = 0, rear = 0;

    visited[startX][startY] = 1;
    queue[rear++] = (struct Cell){startX, startY, 0};

    while (front < rear)
    {
        struct Cell curr = queue[front++];

        if (curr.x == endX && curr.y == endY)
            return curr.dist;

        for (int i = 0; i < 4; i++)
        {
            int newX = curr.x + dRow[i], newY = curr.y + dCol[i];

            if (isValid(newX, newY, grid, visited))
            {
                visited[newX][newY] = 1;
                queue[rear++] = (struct Cell){newX, newY, curr.dist + 1};
            }
        }
    }

    return -1; // Path not found
}

int main()
{
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1}};

    int startX = 0, startY = 0, endX = 4, endY = 4;

    int result = shortestPath(grid, startX, startY, endX, endY);
    printf(result != -1 ? "Shortest path length is: %d\n" : "No path exists.\n", result);

    return 0;
}
