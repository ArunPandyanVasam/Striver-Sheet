#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printBackTracking1_N(int i, int n)
{
    if (i < 1)
    {
        return;
    }

    printBackTracking1_N(i - 1, n);
    printf("%d ", i);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("Print values from 1 to N: ");
    printBackTracking1_N(n, n);

    puts(" ");
    return 0;
}
