#include <stdio.h>
#include <conio.h>

void NaiveStringMatching(char text[], char pattern[]) {
    int i, j;
    int n = 0, m = 0;
    int found = 0; // Flag to track if a match is found

    // Calculate length of text
    while (text[n] != '\0') {
        n++;
    }

    // Calculate length of pattern
    while (pattern[m] != '\0') {
        m++;
    }

    // Traverse the text and check for pattern match
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;  // If mismatch found, break out of inner loop
            }
        }

        // If the whole pattern matches
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;  // Set flag to 1 if a match is found
        }
    }

    // If no match is found, display "Pattern not found"
    if (!found) {
        printf("Pattern not found\n");
    }
}

void main() {
    char text[100], pattern[100];
    
    clrscr();
    printf("Enter the text: ");
    scanf("%s",&text);  // Reading the text
    printf("Enter the pattern: ");
    scanf("%s",&pattern);  // Reading the pattern
    
    NaiveStringMatching(text, pattern);  // Calling the Naive String Matching function
    
    getch();  // Wait for user input before closing
}
