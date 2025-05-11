#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define MAX 10
#define INF 1000000

// Distance matrix to store the distances between cities
int distance[MAX][MAX];

// dp[current][count] to store the minimum cost and path
int dp[MAX][MAX];

// visited array to keep track of visited cities
int visited[MAX];

// n is the number of cities
int n;

// minCost stores the minimum cost of visiting all cities
int minCost = INF;

// tempPath stores the current path in recursion
int tempPath[MAX + 1];

// finalPath stores the optimal path
int finalPath[MAX + 1];

// Function to return the minimum of two integers
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Function to copy the current path to finalPath
void copyPath(int count) {
    int i;
    for (i = 0; i < n; i++) {
        finalPath[i] = tempPath[i];
    }
    finalPath[n] = 0; // return to starting point
}

// Recursive function to solve TSP and store optimal path
void tspRecursive(int current, int count, int costSoFar) {
    int i;
    // If all cities are visited, return to the start city
    if (count == n) {
        int totalCost = costSoFar + distance[current][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            copyPath(count);
        }
        return;
    }

    // Try visiting each city from the current city
    for (i = 0; i < n; i++) {
        if (!visited[i] && i != current) {  // If city i is not visited and not the current city
            visited[i] = 1;
            tempPath[count] = i;
            tspRecursive(i, count + 1, costSoFar + distance[current][i]);
            visited[i] = 0; // backtrack
        }
    }
}

void main() {
    int i, j;

    clrscr();  // Clear the screen (Turbo C specific)

    // Input the number of cities
    printf("Enter the number of cities (max %d): ", MAX);
    scanf("%d", &n);

    // Check for valid number of cities
    if (n > MAX || n < 2) {
        printf("Invalid number of cities.\n");
    }

    // Input the distance matrix
    printf("Enter the distance matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &distance[i][j]);
        }
    }

    // Initialize visited array and dp array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    visited[0] = 1; // Start from city 0
    tempPath[0] = 0; // Start from city 0

    // Call the recursive TSP function
    tspRecursive(0, 1, 0);

    // Output the minimum cost and optimal path
    printf("\nMinimum cost to visit all cities: %d\n", minCost);
    printf("Optimal Path: ");
    for (i = 0; i <= n; i++) {
        printf("%d", finalPath[i]);
        if (i != n) {
            printf(" -> ");
        }
    }
    printf("\n");

    getch();  // Wait for a key press (Turbo C specific)
}
