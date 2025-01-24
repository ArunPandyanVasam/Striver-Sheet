
#include <stdio.h>

void printAlphaHillPattern(int n)
{
    
    for (int i = 0; i < n; i++)
    {
        
        // space
        for (int j = 0; j < n - i -1; j++)
        {
            printf("-");
        }

        // Alphabet
        char ch = 'A';
        int breakPoint = (2*i+1)/2;
        for (int j = 1; j <= (2*i)+1; j++)
        {
            printf("%c", ch);
            if (j <= breakPoint) {
                ch++;
            } else {
                ch--;
            }
        }
        
        // space
        for (int j = 0; j < n - i -1; j++)
        {
            printf("-");
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
    printAlphaHillPattern(n);

    puts("\n");
    return 0;
}