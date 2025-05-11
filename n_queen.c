#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 20  // Maximum number of queens supported

int x[MAX]; // Array to store queen positions
int n;      // Number of queens
int solution_count = 0;

// Function to check if it's safe to place a queen at row k and column i
int isSafe(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        // Check if any queen in previous rows threatens this position
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Recursive function to solve N-Queen using backtracking
void Nqueen(int k) {
    int i, m;
    for (i = 1; i <= n; i++) {
        if (isSafe(k, i)) {
            x[k] = i;
            if (k == n) {
                solution_count++;
                // Display solution as solution array format
                printf("\nSolution %d (Solution Array):\n", solution_count);
                for (m = 1; m <= n; m++) {
                    printf("Row %d -> Column %d\n", m, x[m]);
                }
            } else {
                Nqueen(k + 1); // Recur for next row
            }
        }
    }
}

void main() {
    clrscr();
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("\nPlease enter a valid number between 1 and %d", MAX);
        getch();
        return;
    }

    printf("\nSolutions:\n");
    Nqueen(1);

    if (solution_count == 0) {
        printf("\nNo solutions exist for %d-Queens.\n", n);
    } else {
        printf("\n\nTotal Solutions: %d\n", solution_count);
    }

    getch();
}
