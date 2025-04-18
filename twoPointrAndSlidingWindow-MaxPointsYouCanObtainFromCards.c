#include <stdio.h>

/*
Time Complexity: O(k) <- O(2k) => dropped constant 2
- First loop runs k times to calculate lSum.
- Second loop runs k times to shift left and add right elements.

Space Complexity: O(1)
- Constant space is used regardless of input size.
*/

int maxPoints(int arr[], int n, int k)
{
    int lSum = 0, rSum = 0, maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        lSum = lSum + arr[i];  // O(k)
    }

    maxSum = lSum;

    int rIndex = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lSum = lSum - arr[i];  // O(k)
        rSum = rSum + arr[rIndex];
        rIndex = rIndex - 1;
        maxSum = (lSum + rSum > maxSum) ? lSum + rSum : maxSum;
    }

    return maxSum;
}

int main(void)
{
    int arr[] = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = maxPoints(arr, n, k);
    printf("Maximum Points You Can Obtain from Cards: %d\n", result);

    return 0;
}
