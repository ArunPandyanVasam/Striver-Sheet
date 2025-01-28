#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printNameNTimes(int i, int n)
{
    if (i > n)
    {
        return;
    }

    printf("Hey!, arun\n");
    printNameNTimes(i+1, n);
}

int main()
{
    puts(" ");
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printNameNTimes(1, n);
    puts(" ");
    return 0;
}
