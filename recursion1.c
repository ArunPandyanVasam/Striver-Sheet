#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int counter = 0;
void printSomethingNTimes()
{
    if (counter == 3)
    {
        return;
    }

    printf("%d ", counter);
    counter++;
    printSomethingNTimes();
}

int main()
{
    puts(" ");
    printSomethingNTimes();
    puts(" ");
    return 0;
}
