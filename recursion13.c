#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

int printFibonacci(int m)
{
    if (m <= 1) {
        return m;
    }

    int last = printFibonacci(m-1);
    int secondLast = printFibonacci(m-2);

    return last + secondLast;
}

int main()
{
    puts(" ");
    int m;
    printf("Input the value of m: ");
    scanf("%d", &m);
    printf("Print fibonacci place: %d", printFibonacci(m));

    puts(" ");
    return 0;
}
