#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int printSumFunctional(int n)
{
    if (n == 0) {
        return 0;
    }

    return n + printSumFunctional(n-1);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("Print sum N values: %d", printSumFunctional(n));

    puts(" ");
    return 0;
}
