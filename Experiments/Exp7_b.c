// C program to implement GCD(Greatest Common Divisor)
#include<stdio.h>
int main()
{
    int n1, n2, i, GCD_Num;

    printf("Enter any two numbers: ");
    scanf("%d %d", &n1, &n2);

    for (i = 1; i <= n1 && i <= n2; ++i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            GCD_Num = i;
        }
    }

    printf("GCD of %d and %d is: %d", n1, n2, GCD_Num);
    return 0;
}