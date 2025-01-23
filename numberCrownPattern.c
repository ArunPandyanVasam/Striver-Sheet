
#include <stdio.h>

void printNumberCrownPattern(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }

        for (int j = 1; j <= 2 * (n - i); j++)
        {
            printf("-");
        }

        for (int j = i; j >= 1; j--)
        {
            printf("%d", j);
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
    printNumberCrownPattern(n);

    puts("\n");
    return 0;
}