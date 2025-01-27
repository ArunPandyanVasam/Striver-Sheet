#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int power(int base, int exponent) {

    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result = result*base;
    }
    return result;
    
}

void printArmstrongNumbers(int n)
{
    int original_1 = n;
    int original_2 = n;
    int lastDigit = 0;
    int sum = 0;
    int count = 0;

    while (original_1 > 0)
    {
        count++;
        original_1 = original_1 / 10;
    }

    while (original_2 > 0)
    {
        lastDigit = original_2 % 10;
        sum = sum + power(lastDigit, count);
        original_2 = original_2 / 10;
    }

    if (sum == n) {
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
    printArmstrongNumbers(n);

    puts("\n");
    return 0;
}
