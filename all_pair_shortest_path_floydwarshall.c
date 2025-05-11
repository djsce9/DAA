#include <stdio.h>
#include <conio.h>

#define INF 99

// Function to print the adjacency matrix
void printMatrix(int n, int matrix[100][100], int iteration) {
    int i, j;
    
    if (iteration == -1)
        printf("\nFinal Shortest Travel Time Matrix:\n");
    else
        printf("\nA%d:\n", iteration);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm implementation
void floydWarshall(int n, int graph[100][100]) {
    int dist[100][100];
    int i, j, k;

    // Initialize distance matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Print initial matrix A0
    printMatrix(n, dist, 0);

    // Apply Floyd-Warshall Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        // Print matrix after each iteration
        printMatrix(n, dist, k + 1);
    }

    // Print final shortest distance matrix
    printMatrix(n, dist, -1);
}

void main() {
    int n, i, j;
    int graph[100][100];

    clrscr();
    printf("Enter the number of warehouses (nodes): ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (enter %d for no direct path):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(n, graph);
    getch();
}
