
#include <stdio.h>

void printRightAngledTrianglePattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
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
    printRightAngledTrianglePattern(n);

    puts("\n");
    return 0;
}