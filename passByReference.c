
#include <stdio.h>

void doSomething(int *num1)
{

    *num1 = 2;
}

int main()
{
    puts("\n");

    int num1 = 10;
    printf("Before - %d\n", num1);
    doSomething(&num1);
    printf("After - %d\n", num1);

    puts("\n");
    return 0;
}