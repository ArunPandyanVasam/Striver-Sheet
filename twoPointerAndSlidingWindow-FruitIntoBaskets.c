#include <stdio.h>

#define MAX_N 1000

// Helper: check if value is in set
int isInSet(int *set, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (set[i] == val) return 1;
    }
    return 0;
}

// Helper: max function
int max(int a, int b) {
    return a > b ? a : b;
}

/*
Time Complexity:
- Outer loop runs n times.
- Inner loop can run up to n times in the worst case.
- Each isInSet call takes O(2) = O(1) time (since stSize <= 2).
- Overall time complexity = O(n^2)

Space Complexity:
- Constant space used (array `st[2]` and a few integers)
- So, space complexity = O(1)
*/
void fruitIntoBaskets_Brute(int arr[], int n) {
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int st[2];       // only need to track 2 unique elements
        int stSize = 0;

        for (int j = i; j < n; j++) {
            if (!isInSet(st, stSize, arr[j])) {
                if (stSize < 2) {
                    st[stSize++] = arr[j];
                } else {
                    break; // more than 2 distinct elements
                }
            }

            maxLen = max(maxLen, j - i + 1);
        }
    }
    printf("Max subarray length with at most 2 distinct elements: %d\n", maxLen);
}

void fruitIntoBaskets_Optimal(int arr[], int n) {
    int l = 0, r = 0, maxLen = 0;
}





int main() {
    int arr[] = {1, 2, 1, 2, 3}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    fruitIntoBaskets_Brute(arr, n);

    return 0;
}
