
#include <stdio.h>

int main()
{
    puts("\n");

    //  while
    int i = 1;
    while (i <= 5)
    {
        printf("Arun - %d\n", i);
        i = i + 1;
    }

    printf("%d", i);

    puts("\n");
    //  Do While
    int j = 2;
    do {
        printf("Arun - %d\n", j);
        j = j + 1;
    } while (j <= 1);

    printf("%d", j);
    

    puts("\n");
    return 0;
}