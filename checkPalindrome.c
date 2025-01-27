#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printCheckPalindrome(int n)
{
    int original = n;
    int reverseNumber = 0;
    int lastDigit = 0;

    while (n > 0)
    {
        lastDigit = n % 10;
        reverseNumber = (reverseNumber*10) + lastDigit;
        n = n / 10;
    }

    if (reverseNumber == original) {
        printf("True");
    } else {
        printf("False");
    }

}

int main()
{
    puts("\n");

    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    puts(" ");
    printCheckPalindrome(n);

    puts("\n");
    return 0;
}
