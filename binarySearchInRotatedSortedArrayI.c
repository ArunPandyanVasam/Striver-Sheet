#include <stdio.h>
#include <stdlib.h>

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

int searchInRotatedArray(int arr[], int n, int target)
{
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
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

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sortArraySelection(arr, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

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

    int target = 0;
    printf("Please give the target element: ");
    scanf("%d", &target);
    int index = searchInRotatedArray(arr, n, target);
    printf("The in dex of target is: %d", index);

    free(arr);

    printf("\n");
    return 0;
}
