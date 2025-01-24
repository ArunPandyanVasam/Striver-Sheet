
#include <stdio.h>

void printIncreasingLetterTrianglePattern(int n)
{


    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
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
    printIncreasingLetterTrianglePattern(n);

    puts("\n");
    return 0;
}