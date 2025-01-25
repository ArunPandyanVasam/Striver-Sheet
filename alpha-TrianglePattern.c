
#include <stdio.h>

void printAlphaTrianglePattern(int n)
{

    char chEnd = 'A' + (n - 1);
    for (int i = 0; i < n; i++)
    {
        // Alphabet
        for (char ch = 'A' + (n - i - 1); ch <= chEnd; ch++)
        {
            printf("%c", ch);
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
    printAlphaTrianglePattern(n);

    puts("\n");
    return 0;
}