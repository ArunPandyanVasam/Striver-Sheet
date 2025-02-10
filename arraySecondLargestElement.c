#include <stdio.h>
#include <limits.h>

int secondLargestElement(int arr[], int n)
{
    if (n < 2)
    {
        return INT_MIN;
    }

    int largest = arr[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest == INT_MIN ? INT_MIN : secondLargest;
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

    int secondLargest = secondLargestElement(arr, n);

    if (secondLargest == INT_MIN)
        printf("No second largest element exists.\n");
    else
        printf("Second largest element in the Array: %d\n", secondLargest);

    printf("\n");
    return 0;
}
