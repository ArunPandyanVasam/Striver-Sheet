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

// Main logic: find max subarray with at most 2 distinct elements
int maxSubarrayWithTwoDistinct(int arr[], int n) {
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

    return maxLen;
}

int main() {
    int arr[] = {1, 2, 1, 2, 3}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSubarrayWithTwoDistinct(arr, n);
    printf("Max subarray length with at most 2 distinct elements: %d\n", result);

    return 0;
}
