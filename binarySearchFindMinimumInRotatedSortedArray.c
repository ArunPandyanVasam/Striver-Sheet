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

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateToLeft(int arr[], int n, int k)
{
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

void rotateToRight(int arr[], int n, int k)
{
    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-1);
}


int minimum(int x, int y) {

   return (x < y)? x: y;

}


int findMinimum (int arr[], int n) {
    int low = 0, high = n-1;
    int ans = INT_MAX;
    
    while (low <= high)
    {
        int mid = low+(high-low)/2;
        if (arr[low] <= arr[mid]) {
            ans = minimum(ans, arr[low]);
            low = mid+1;
        } else {
            ans = minimum(ans, arr[mid]);
            high = mid-1;
        }
    }
    
    return ans;

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

    // Rotate Array
    int k = 0;
    printf("Please give the value, how many times array should rotate on left: ");
    scanf("%d", &k);
    rotateToRight(arr, n, k);
    printf("\nRotated Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min = findMinimum(arr, n);
    printf("Minimum Value: %d", min);

    free(arr);

    printf("\n");
    return 0;
}
