#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b)) // macros new concept

/*
    //condition ? expression_if_true : expression_if_false;

    s
    int a = 10, b = 20, c = 5;
    int min = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    printf("Minimum value: %d\n", min); // nested ternary operator

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
*/

void printtheNumberPattern(int n)
{

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int bottom = 2 * n - 2 - i;
            int right = 2 * n - 2 - j;

            printf("%d", n - min(min(top, bottom), min(left, right)));
        }

        puts(" ");
    }
}

int main()
{
    puts("\n");

    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    puts(" ");
    printtheNumberPattern(n);

    puts("\n");
    return 0;
}