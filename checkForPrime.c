#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void printCheckForPrime(int n)
{
    // Time Complexity: O(sqrt(n))
    int counter = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
            if (n / i != i)
            {
                counter++;
            }
        }
    }

    if (counter == 2)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    printf("\n");
}

int main()
{
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);

    printf("Divisors using O(sqrt(n)) method:\n");
    printCheckForPrime(n);

    return 0;
}
