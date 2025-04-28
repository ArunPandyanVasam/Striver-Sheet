#include <stdio.h>
#include <string.h>

void longestRepeatingCharacterReplacement_Brute(char *str, int n, int k) {
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int hash[26] = {0};  // To count occurrences of each uppercase letter
        int maxFrequency = 0; // Most frequent character count in current window

        for (int j = i; j < n; j++) {
            hash[str[j] - 'A']++;  // Map 'A' to index 0, 'B' to 1, etc.
            
            // Update the maximum frequency in the current window
            maxFrequency = (hash[str[j] - 'A'] > maxFrequency) ? hash[str[j] - 'A'] : maxFrequency;

            // Number of changes needed to make all letters same in window [i..j]
            int changes = (j - i + 1) - maxFrequency;

            if (changes <= k) {
                maxLen = ((j - i + 1) > maxLen) ? (j - i + 1) : maxLen;
            } else {
                break; // If changes exceed k, no need to expand this window further
            }
        }
    }
    printf("Max Length: %d\n", maxLen);
}

int main(void) {
    char str[] = "AABABBA";
    int n = strlen(str);
    int k = 2;

    longestRepeatingCharacterReplacement_Brute(str, n, k);

    return 0;
}
