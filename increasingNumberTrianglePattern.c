
#include <stdio.h>

void printIncreasingNumberTrianglePattern(int n)
{

    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", num);
            num = num + 1;
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
    printIncreasingNumberTrianglePattern(n);

    puts("\n");
    return 0;
}