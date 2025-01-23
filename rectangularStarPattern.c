
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

    int n , m;
    printf("Input the value of n and m(give space between each value using space/tab button): ");
    scanf("%d %d", &n, &m);
    puts(" ");
    printRectangularStarPattern(n);
    puts(" ");
    printRectangularStarPattern(m);

    puts("\n");
    return 0;
}