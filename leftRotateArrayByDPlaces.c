#include <stdio.h>

void leftRotateArrayByDPlacesUsingTemp(int arr[], int n, int k)
{

    k = k % n;

    if (k == 0) {
        return;
    }

    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
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

void leftRotateArrayByDPlacesUsingReversalAlgo(int arr[], int n, int k)
{
    k = k % n;

    if (k == 0) {
        return;
    }

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
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

    int arr[n], originalArray[n];

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
        originalArray[i] = arr[i];
    }

    int k = 0;
    printf("Enter how many places to rotate left by array: ");
    scanf("%d", &k);

    leftRotateArrayByDPlacesUsingTemp(arr, n, k);
    printf("\nRotated array using Temporary Array method: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }


    for (int i = 0; i < n; i++)
    {
        arr[i] = originalArray[i];
    }
    

    leftRotateArrayByDPlacesUsingReversalAlgo(arr, n, k);
    printf("\nRotated array using Reversal Algorithm: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
