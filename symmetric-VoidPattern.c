
#include <stdio.h>

void printSymmetricVoidPatternTop(int n)
{
    int spaces = 0;
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 0; j < n - i; j++)
        {
            printf("*");
        }

        // space
        for (int j = 0; j < spaces; j++)
        {
            printf("-");
        }

        // star
        for (int j = 0; j < n - i; j++)
        {
            printf("*");
        }
        spaces += 2;

        puts(" ");
    }
}

void printSymmetricVoidPatternBottom(int n)
{
    int spaces = 2 * (n - 1);
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }

        // space
        for (int j = 0; j < spaces; j++)
        {
            printf("-");
        }

        // star
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        if (spaces >= 0)
        {
            spaces -= 2;
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
    printSymmetricVoidPatternTop(n);
    printSymmetricVoidPatternBottom(n);

    puts("\n");
    return 0;
}