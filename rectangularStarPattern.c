
#include <stdio.h>

void printRectangularStarPattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("* ");
        }
        puts(" ");
    }
}

int main()
{
    puts("\n");

    int n = 5;
    printRectangularStarPattern(n);

    puts("\n");
    return 0;
}