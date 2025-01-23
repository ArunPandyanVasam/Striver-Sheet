
#include <stdio.h>

void printrightAngledNumberPyramid2Pattern(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", i);
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
    printrightAngledNumberPyramid2Pattern(n);
    puts(" ");
    printrightAngledNumberPyramid2Pattern(m);

    puts("\n");
    return 0;
}