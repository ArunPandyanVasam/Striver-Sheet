#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int printFactorialFunctional(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * printFactorialFunctional(n - 1);
}

// Do parameterized

int main()
{
    puts(" ");

    int n, m;
    printf("Input the value of n: ");
    scanf("%d", &n);
    m = n;
    printf("Print sum N values: %d", printFactorialFunctional(n));

    puts(" ");
    return 0;
}
