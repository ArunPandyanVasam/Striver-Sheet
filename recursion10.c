#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printFactorialParameterized(int m, int multiply)
{
    if (m == 0)
    {
        printf("%d", multiply);
        return;
    }
    printFactorialParameterized(m - 1, multiply * m);
}

int main()
{
    puts(" ");

    int m;
    printf("Input the value of m: ");
    scanf("%d", &m);
    printf("Print factorial of N values: ");
    printFactorialParameterized(m, 1);

    puts(" ");
    return 0;
}
