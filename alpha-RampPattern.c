
#include <stdio.h>

void printAlphaRampPattern(int n)
{

    for (int i = 0; i < n; i++)
    {
            char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            printf("%C ", ch);
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
    printAlphaRampPattern(n);

    puts("\n");
    return 0;
}