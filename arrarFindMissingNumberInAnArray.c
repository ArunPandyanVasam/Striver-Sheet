#include <stdio.h>



int findMissingNumber(int arr[], int n) {
    int sum = (n*(n+1))/2;

    int s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s2 += arr[i];
    }

    int missingNumber = sum - s2;
    return missingNumber;
    

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

    printf("Missing Number: %d", findMissingNumber(arr, n));

    printf("\n");
    return 0;
}
