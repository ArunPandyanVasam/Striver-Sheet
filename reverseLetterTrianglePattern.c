
#include <stdio.h>

void printReverseLetterTrianglePattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
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
    printReverseLetterTrianglePattern(n);

    puts("\n");
    return 0;
}