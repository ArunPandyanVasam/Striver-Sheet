#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printLinearlyFron1ToN_1(int i, int n)
{
    if (i > n)
    {
        return;
    }

    printf("%d ", i);
    printLinearlyFron1ToN_1(i + 1, n);
}

void printLinearlyFron1ToN_2(int i, int n)
{
    if (i < 1)
    {
        return;
    }

    printf("%d ", i);
    printLinearlyFron1ToN_2(i - 1, n);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("Print values from 1 to N: ");
    printLinearlyFron1ToN_1(1, n);
    puts(" ");
    printf("Print values from N to 1: ");
    printLinearlyFron1ToN_2(n, n);
    puts(" ");
    return 0;
}
