#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printAllDivisors1(int n)
{
    // Time Complexity: O(n)
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int squareRoot(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
        {
            return i;
        }
    }
}

void printAllDivisors2(int n)
{
    // Time Complexity: O(sqrt(n))
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            if (i != n / i) // To avoid printing duplicates
            {
                printf("%d ", n / i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);

    printf("Divisors using O(n) method:\n");
    printAllDivisors1(n);

    printf("Divisors using O(sqrt(n)) method:\n");
    printAllDivisors2(n);

    return 0;
}
