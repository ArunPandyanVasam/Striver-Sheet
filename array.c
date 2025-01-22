
#include <stdio.h>

int main() {
    puts("\n");
    //  1D-Array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array Value- %d", arr[2]);

    puts(" ");

    //  2D-Array
    int mat[2][3] = {{1, 2, 3}, {
                      4, 5, 6}};

    printf("Matrix Value- %d", mat[1][1]);

    puts("\n");
    return 0;
}