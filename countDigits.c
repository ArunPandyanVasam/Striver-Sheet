#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printCountDigits(int n)
{
    int count = 0;
    int original = n;  // Store the original value of n for later use

    printf("\nDigits in a number: ");
    while (n > 0)
    {
        int lastDigit = n % 10;
        printf("%d ", lastDigit);
        n = n / 10;
        count = count + 1;
    }

    printf("\nNumber of digits in a number: %d", count);

    if (original > 0) {
        int counter = (int)(log10(original) + 1);
        printf("\nCounter: %d", counter);
    } else {
        printf("\nCounter: 1");  // Handling the case when n = 0
    }
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
