#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

/*
    Function: maxLength_BruteForce
    Purpose: Finds the length of the longest substring without repeating characters.

    Time Complexity:
        - Outer loop runs 'n' times.
        - Inner loop runs up to 'n' times for each outer loop (worst case).
        - So, total time complexity = O(n^2)

    Space Complexity:
        - Uses a fixed-size hash array of size 256 (for ASCII characters).
        - So, space complexity = O(1) (constant space)
*/

void maxLength_OptimalApproach(char *s, int n)
{
    if (s == NULL || n <= 0)
    {
        printf("Max Length: 0\n");
        return;
    }

    int l = 0, r = 0, len = 0, maxLen = 0;
    int hash[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++)
    {
        hash[i] = -1;
    }

    while (r < n)
    {
        if (hash[s[r]] != -1 && hash[s[r]] >= l)
        {
            l = hash[s[r]] + 1;
        }
        len = r - l + 1;
        maxLen = (len > maxLen) ? len : maxLen;
        hash[s[r]] = r;
        r++;
    }

    printf("Max Length: %d\n", maxLen);
}


// Function to find the length of the longest substring without repeating characters
// Time Complexity: O(n) where n is the length of the input string
//   - Each character is visited at most twice (once by 'r', and possibly once by 'l').
// Space Complexity: O(1)
//   - Uses a fixed-size array of size 256 (constant space, independent of input size)

void maxLength_OptimalApproach(char *s, int n)
{

    int l = 0, r = 0, len = 0, maxLen = 0;

    int hash[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++)
    {
        hash[i] = -1;
    }

    while (r < n)
    {
        if (hash[s[r]] != -1)
        {
            if (hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
        }

        len = r - l + 1;
        maxLen = (len > maxLen) ? len : maxLen;
        hash[s[r]] = r;
        r = r + 1;
    }
    printf("Max Length: %d\n", maxLen);
}

int main(void)
{
    char str[] = "cadbzabcd";
    int n = strlen(str); // O(n) time
    maxLength_BruteForce(str, n);
    maxLength_OptimalApproach(str, n);
    return 0;
}
