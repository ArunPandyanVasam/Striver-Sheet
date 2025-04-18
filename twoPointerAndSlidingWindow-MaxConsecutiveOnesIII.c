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

/*
-----------------------------------------------------------
Time Complexity: O(n)
-----------------------------------------------------------
- The algorithm uses a sliding window approach with two pointers: `l` and `r`.
- In the worst case, each pointer moves across the array once.
  - `r` moves from 0 to n-1 → O(n)
  - `l` also moves forward as needed → up to O(n)
- Therefore, total operations can be up to 2n, but in Big-O notation we drop constants.
- Final time complexity: O(n)

-----------------------------------------------------------
Space Complexity: O(1)
-----------------------------------------------------------
- Only a constant number of variables are used (`maxLen`, `l`, `zeros`, `r`).
- No extra space proportional to input size is used.
- Final space complexity: O(1)
*/
void maxConsecutiveOnes_Better(int arr[], int n, int k)
{
    int maxLen = 0, left = 0, right = 0, zeroCount = 0;

    while (right < n)
    {
        if (arr[right] == 0)
            zeroCount++;

        while (zeroCount > k)
        {
            if (arr[left] == 0)
                zeroCount--;
            left++;
        }

        int len = right - left + 1;
        if (len > maxLen)
            maxLen = len;

        right++;
    }

    printf("Max Length: %d\n", maxLen);
}

/*
    Finds the maximum length of a subarray with at most 'k' zeros flipped to 1s
    using a Sliding Window (Two Pointer) approach.

    Time Complexity:
        O(n) - Each element is processed at most twice:
              once when 'right' moves forward,
              and at most once when 'left' moves forward.
              So the overall time complexity is linear in the size of the array.

    Space Complexity:
        O(1) - Constant space is used. Only a few integer variables are maintained
              regardless of the input size.
*/
void maxConsecutiveOnes_Optimal(int arr[], int n, int k)
{
    int l = 0, r = 0, maxLen = 0, zeros = 0;

    while (r < n)
    {
        if (arr[r] == 0)
        {
            zeros++;
        }

        if (zeros > k)
        {
            if (arr[l] == 0)
            {
                zeros--;
            }
            l++;
        }

        int len = r - l + 1;
        if (len > maxLen)
        {
            maxLen = len;
        }

        r++;
    }

    printf("Max Length: %d\n", maxLen);
}

int main(void)
{
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    maxConsecutiveOnes_BruteForce(arr, n, k);
    maxConsecutiveOnes_Better(arr, n, k);
    maxConsecutiveOnes_Optimal(arr, n, k);

    return 0;
}
