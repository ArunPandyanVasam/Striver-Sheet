#include <stdio.h>

void leftRotateArrayByDPlacesUsingTemp(int arr[], int n, int k)
{

    k = k % n;
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

void leftRotateArrayByDPlacesUsingReversalAlgo(int arr[], int n, int k)
{

    
    
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

    int arr[n];

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int k = 0;
    printf("Enter how many places to rotate left by array: ");
    scanf("%d", &k);

    leftRotateArrayByDPlacesUsingTemp(arr, n, k);

    printf("\nPrint the rotated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
