#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define d 256  // Number of characters in the input alphabet (here we assume ASCII)
#define q 101  // A prime number used for hashing

// Function to calculate hash value for a given string
int hash(char str[], int end, int p) {
    int hash_val = 0;
    for (int i = 0; i < end; i++) {
        hash_val = (hash_val * d + str[i]) % q;
    }
    return hash_val;
}

// Function to implement Rabin-Karp algorithm
void RabinKarp(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int pattern_hash = hash(pattern, m, q);  // Hash of the pattern
    int text_hash = hash(text, m, q);        // Hash of the first window of text
    int h = (int)pow(d, m - 1) % q;         // The value of d^(m-1) % q

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            // If the hash values match, check the actual strings
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            text_hash = (d * (text_hash - text[i] * h) + text[i + m]) % q;
            if (text_hash < 0)
                text_hash = text_hash + q;
        }
    }
}

void main() {
    char text[100], pattern[100];
    clrscr();
    
    printf("Enter the text: ");
    scanf("%s", &text);
    
    printf("Enter the pattern: ");
    scanf("%s", &pattern);
    
    RabinKarp(text, pattern);
    
    getch();
}
