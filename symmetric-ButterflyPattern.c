
#include <stdio.h>

void printSymmetricButterflyPattern(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= (2 * n) - 1; i++)
    {
        // star
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }

        for (int j = 1; j <= stars; j++)
        {
            printf("*");
        }

        // space
        for (int j = 1; j <= spaces; j++)
        {
            printf("-");
        }

        // star
        for (int j = 1; j <= stars; j++)
        {
            printf("*");
        }

        if (i < n)
        {
            spaces -= 2;
        }
        else
        {
            spaces += 2;
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
    printSymmetricButterflyPattern(n);

    puts("\n");
    return 0;
}