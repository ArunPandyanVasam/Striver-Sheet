
#include <stdio.h>

void printinvertedRightPyramidPattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf("* ");
        }
        puts(" ");
    }
}

int main()
{
    puts("\n");

    int n, m;
    printf("Input the value of n and m(give space between each value using space/tab button): ");
    scanf("%d %d", &n, &m);
    puts(" ");
    printinvertedRightPyramidPattern(n);
    puts(" ");
    printinvertedRightPyramidPattern(m);

    puts("\n");
    return 0;
}