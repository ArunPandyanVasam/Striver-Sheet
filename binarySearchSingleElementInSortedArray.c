#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sortArraySelection(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int singleElement(int arr[], int n)
{
    
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;

    while (low <= high)
    {
        int mid = low+(high-low)/2;
        if (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }

        if ((mid%2 == 0 && arr[mid] == arr[mid+1]) || (mid%2 == 1 && arr[mid] == arr[mid-1])) {
            low = mid+1;
        } else {
            high = mid-1;
        }

    }
    return -1;
}

int main(void)
{
    printf("\n");

    int n = 0;
    printf("\nInput the size of the Array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size. The array must contain at least one element.\n");
        return 1;
    }

    // Declare a Pointer Array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input Array Values
    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Sort Array
    sortArraySelection(arr, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value = singleElement(arr, n);
    printf("Single Element is: %d", value);

    free(arr);

    printf("\n");
    return 0;
}
