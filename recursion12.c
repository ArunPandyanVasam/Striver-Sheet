#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

bool printPalindrome(int i, int n, char str[])
{

    if (i >= n/2) {
        return true;
    }

    if (str[i] != str[n-1-i]) {
        return false;
    }

    return printPalindrome(i+1, n, str);
}

int main()
{
    puts(" ");

    char str[SIZE];
    printf("Input the value of str: ");
    fgets(str, sizeof str, stdin);
    if (str[strlen(str)-1 == '\n']) {
        str[strlen(str)-1] = '\0';
    }

    int n = strlen(str);
    printf("%d", n);
    if (printPalindrome(0, n, str)) {
        printf ("\nTrue");
    } else {
        printf ("\nFalse");
    }

    puts(" ");
    return 0;
}
