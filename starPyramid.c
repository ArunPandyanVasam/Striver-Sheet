
#include <stdio.h>

void printStarPyramidPattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        //space
        for (int j = 0; j < n- i - 1; j++)
        {
           printf(" ");
        }
        

        //star
        for (int j = 0; j < 2*i+1; j++)
        {
            printf("*");
        }

        //space
        for (int j = 0; j < n- i - 1; j++)
        {
            printf(" ");
        }
        puts("");
    }
    
}

int main()
{
    puts("\n");

    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    puts(" ");
    printStarPyramidPattern(n);

    puts("\n");
    return 0;
}