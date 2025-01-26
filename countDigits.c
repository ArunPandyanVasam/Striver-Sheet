#include <stdio.h>
#include <stdlib.h>

void printCountDigits(int n)
{
    int count = 0;
    printf("\nDigits in a number: ");
    while (n > 0)
    {
        int lastDigit = n%10;
        printf("%d ", lastDigit);
        n = n/10;
        count = count + 1;
    }

    printf("\nNumber of digits in a number: %d", count);
    
}

int main()
{
    puts("\n");

    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    puts(" ");
    printCountDigits(n);

    puts("\n");
    return 0;
}