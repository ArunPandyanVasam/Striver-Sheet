#include <stdio.h>

/*
 * Function: maxConsecutiveOnes_BruteForce
 * ---------------------------------------
 * Finds the maximum length of a subarray with at most 'k' zeros that can be flipped to ones.
 *
 * Time Complexity: O(n^2) - due to the nested loops (i and j)
 * Space Complexity: O(1)  - constant space used for variables only
 */
void maxConsecutiveOnes_BruteForce(int arr[], int n, int k)
{
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
            {
                zeros++;
            }

            if (zeros > k)
            {
                break;
            }

            int len = j - i + 1;
            if (len > maxLen)
            {
                maxLen = len;
            }
        }
    }

    printf("Max Length: %d\n", maxLen);
}

int main(void)
{
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    maxConsecutiveOnes_BruteForce(arr, n, k);

    return 0;
}
