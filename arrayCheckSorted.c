#include <stdio.h>
#include <stdbool.h>

bool arrayCheckSorted(int arr[], int n)
{
    int previous;
    int current;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }

        /*if (arr[i] < arr[i-1]) {
            return false;
        }*/ 
    }
    return true;
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

    if (arrayCheckSorted(arr, n))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    printf("\n");
    return 0;
}
