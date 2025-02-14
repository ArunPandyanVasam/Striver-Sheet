#include <stdio.h>

int arrayLinearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key) {
            return i;  // Return first occurrence index
        }
    }
    return -1;  // Key not found
}

int main(void)
{
    printf("\n");

    int n;
    printf("Input the size of the Array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size. The array must contain at least one element.\n");
        return 1;
    }

    int arr[n];

    printf("Input the elements into the Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Input the value of key to search: ");
    scanf("%d", &key);

    int index = arrayLinearSearch(arr, n, key);
    if (index == -1)
    {
        printf("The key %d was not found in the array.\n", key);
    }
    else
    {
        printf("The first occurrence of key %d is at index: %d\n", key, index);
    }

    return 0;
}
