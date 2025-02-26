#include <stdio.h>

int maximumConsecutiveOnes(int arr[], int n)
{

    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            max = (count > max)? count: max;
        }
        else
        {
            count = 0;
        }
    }

    return max;
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

    printf("Maximum Consecutive Ones: %d", maximumConsecutiveOnes(arr, n));

    printf("\n");
    return 0;
}
