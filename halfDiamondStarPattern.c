
#include <stdio.h>

void printHalfDiamondStarPattern(int n)
{

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            printf("* ");
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
    printHalfDiamondStarPattern(n);

    puts("\n");
    return 0;
}