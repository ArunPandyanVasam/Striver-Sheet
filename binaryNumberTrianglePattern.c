
#include <stdio.h>

void printBinaryNumberTrianglePattern(int n)
{
    int start;
    for (int i = 0; i < n; i++)
    {

        if (i%2 == 0) {
            start = 1;
        } else {
            start = 0;
        }

        for (int j = 0; j <= i; j++)
        {
            printf("%d ", start);
            start = 1-start;
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
    printBinaryNumberTrianglePattern(n);

    puts("\n");
    return 0;
}