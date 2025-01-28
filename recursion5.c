#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printBackTrackingN_1(int i, int n)
{
    if (i > n)
    {
        return;
    }

    printBackTrackingN_1(i + 1, n);
    printf("%d ", i);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("Print values from 1 to N: ");
    printBackTrackingN_1(1, n);

    puts(" ");
    return 0;
}
