// C program to implement multiplication of two numbers.
#include<stdio.h>
#include <math.h>

int countDigits(int n)   // Function to count the number of digits in a number
{
    if (n == 0)
    {
        return 1;
    }
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int multiply(int x, int y)  // Function to multiply two numbers using divide and conquer
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }

    int n = fmax(countDigits(x), countDigits(y));   // Calculate the number of digits in the largest number
    int half = n / 2;

    // Divide the numbers into two halves
    int power = pow(10, half);
    int xHigh = x / power;
    int xLow = x % power;
    int yHigh = y / power;
    int yLow = y % power;

    int z0 = multiply(xLow, yLow);
    int z1 = multiply((xLow + xHigh), (yLow + yHigh));
    int z2 = multiply(xHigh, yHigh);

    return z2 * pow(10, 2 * half) + (z1 - z2 - z0) * power + z0;
}

int main()
{
    int num1, num2;

    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);

    int result = multiply(num1, num2);
    printf("The product of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
