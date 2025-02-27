#include <stdio.h>
#include <stdlib.h>




void sortArray (int arr[], int n) {

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int binarySearchUsingIterative(int arr[], int n, int target) {

    int low = 0, high = n-1;

    while (low <= high)
    {
        int mid = low+(high-low)/2;
        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
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
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sortArray(arr, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target = 0;
    printf("Please give the target element: ");
    scanf("%d", &target);

    int index = binarySearchUsingIterative(arr, n, target);
    if (index == -1) {
        printf("The target is not present. ");
    } else {
        printf("The target is at index: %d", index);
    }
    
    free(arr);

    printf("\n");
    return 0;
}
