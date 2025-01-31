#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100


void swap (int *l, int *r) {
    int temp = *r;
    *r = *l;
    *l = temp;
}

void printReverseAnArray(int i, int arr[], int n)
{
    if (i >= n/2) {
        return;
    }
    swap(&arr[i], &arr[n-i-1]); // write a function swap
    printReverseAnArray(i+1, arr, n);
}


// Try to do using with two pointer variables

int main()
{
    puts(" ");

    int arr[SIZE], n;
    printf("Input the size of array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Input the value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Print Reverse Array of N values: ");
    printReverseAnArray(0, arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    puts(" ");
    return 0;
}
