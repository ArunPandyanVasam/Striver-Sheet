
#include <stdio.h>

void printinvertedNumberRightPyramidPattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%d ", j + 1);
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
    printinvertedNumberRightPyramidPattern(n);
    puts(" ");
    printinvertedNumberRightPyramidPattern(m);

    puts("\n");
    return 0;
}