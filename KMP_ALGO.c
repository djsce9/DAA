#include <stdio.h>
#include <conio.h>

#define MAX 1000  // Maximum size for text input

// Function to compute the LPS (Longest Prefix Suffix) table
void computeLPS(char *pattern, int m, int lps[]) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;  // LPS[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];  // Use the previous longest prefix suffix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Print the LPS table
    printf("\nLPS Table (for pattern):\n");
    for (int i = 0; i < m; i++) {
        printf("lps[%d] = %d\n", i, lps[i]);
    }
}

// Function to perform KMP Pattern Search
void kmpSearch(char *pattern, char *text) {
    int m = 0, n = 0;
    while (pattern[m] != '\0') m++;  // Calculate the length of pattern
    while (text[n] != '\0') n++;  // Calculate the length of text

    int lps[MAX]; // max pattern length assumed to be 1000

    computeLPS(pattern, m, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern
    int found = 0;

    printf("\nSearching for pattern in text...\n");

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index: %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

// Main function
void main() {
    char text[MAX], pattern[MAX];

    clrscr();  // Clear the screen

    printf("Enter the text: ");
    scanf("%s", text);  // Reading the text (compatible with Turbo C)

    printf("Enter the pattern: ");
    scanf("%s", pattern);  // Reading the pattern (compatible with Turbo C)

    kmpSearch(pattern, text);  // Calling the KMP Search function

    getch();  // Wait for user input before closing
}
