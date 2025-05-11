#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

// Function to find LCS length and fill the DP table
void lcs(char X[], char Y[], int m, int n) {
    int dp[MAX][MAX], direction[MAX][MAX], i, j;

    // Initialize the DP table and direction table
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] = 0;
            direction[i][j] = 0; // No direction at the beginning
        }
    }

    // Fill the DP and direction tables
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = 'D'; // Diagonal move (match case)
            } else {
                if(dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    direction[i][j] = 'U'; // Up move (exclude character from Y)
                } else {
                    dp[i][j] = dp[i][j - 1];
                    direction[i][j] = 'L'; // Left move (exclude character from X)
                }
            }
        }
    }

    // Print the DP Table (Cost Table)
    printf("\nCost Table (DP Table):\n");
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    // Print the Direction Table with updated convention (D=Diagonal, U=Up, L=Left)
    printf("\nDirection Table (D=Diagonal, U=Up, L=Left):\n");
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                printf("-\t");
            } else {
                printf("%c\t", direction[i][j]);
            }
        }
        printf("\n");
    }

    // Display LCS length
    printf("\nLength of Longest Common Subsequence: %d\n", dp[m][n]);

    // Backtrack to find the LCS
    char lcsSequence[MAX];
    int index = dp[m][n]; // Length of LCS
    lcsSequence[index] = '\0'; // Null-terminate the LCS string

    i = m;
    j = n;
    while(i > 0 && j > 0) {
        if(direction[i][j] == 'D') { // Diagonal move
            lcsSequence[--index] = X[i - 1];
            i--;
            j--;
        } else if(direction[i][j] == 'L') { // Left move
            j--;
        } else { // Up move
            i--;
        }
    }

    // Print the LCS
    printf("\nLongest Common Subsequence: %s\n", lcsSequence);
}

void main() {
    char X[MAX], Y[MAX];
    clrscr();

    // Input strings X and Y
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Call LCS function
    lcs(X, Y, m, n);

    getch();
}
