#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printSumParameterized(int n, int sum)
{
    if (n < 1)
    {
        printf("%d", sum);
        return;
    }

    printSumParameterized(n-1, sum+n);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("Print sum N values: ");
    printSumParameterized(n, 0);

    puts(" ");
    return 0;
}
