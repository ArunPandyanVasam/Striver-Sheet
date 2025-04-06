#include <stdio.h>

int maxSlidingWindowSum(int arr[], int n, int k)
{
    int windowSum = 0;

    // Step 1: calculate sum of first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: slide the window
    for (int i = k; i < n; i++)
    {
        windowSum = windowSum + arr[i] - arr[i - k]; // Add new, remove old
        if (windowSum > maxSum)
        {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main()
{
    int arr[] = {-1, 2, 3, 3, 4, 5, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = maxSlidingWindowSum(arr, n, k);
    printf("Maximum sum of %d consecutive elements is: %d\n", k, result);

    return 0;
}
