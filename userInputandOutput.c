
#include <stdio.h>

int main() {
    puts("\n");

    int x;
    int y;
    printf("Please input the values of x and y: (use space or tab after one value): ");
    scanf("%d %d", &x, &y);
    printf("X = %d, Y = %d", x, y);

    puts("\n");
    return 0;
}