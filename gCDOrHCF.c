#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minimunm(int n1, int n2)
{
    (n1 < n2) ? n1 : n2;
}

void printGCDOrHCF1(int n1, int n2)
{

    int gcd = 1; // worst case like prime numbers
    for (int i = 1; i <= minimunm(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    printf("Print the GCD Or HCF: %d\n", gcd);
    //  TL-> O(min(n1,n2))
}

void printGCDOrHCF2(int n1, int n2)
{

    for (int i = minimunm(n1, n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            printf("Print the GCD Or HCF: %d\n", i);
            break;
        }
    }

    //  TL-> O(min(n1,n2)) worst case for prime numbers N1 = 11, N2 = 13
}

void printGCDOrHCF3(int n1, int n2)
{

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
        {
            n1 = n1 % n2;
        }
        else
        {
            n2 = n2 % n1;
        }
    }

    if (n1 == 0)
    {
        printf("GCD n2 - %d\n", n2);
    }
    else
    {
        printf("GCD n1 - %d\n", n1);
    }

    //  TL-> O(logpie(min(n1,n2))) --- Why log-
    //  whenever their is division happening the number iterations will be in Logrithm
    //  Pie -fluctuation
}

int main()
{
    int n1, n2;
    printf("Input the value of n1 and n2: ");
    scanf("%d %d", &n1, &n2);
    printGCDOrHCF1(n1, n2);
    printGCDOrHCF2(n1, n2);
    printGCDOrHCF3(n1, n2);

    return 0;
}
