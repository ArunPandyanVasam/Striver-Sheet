
#include <stdio.h>

void printHollowRectanglePattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("*");
            } else {
                printf("-");
            }
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
    printHollowRectanglePattern(n);

    puts("\n");
    return 0;
}