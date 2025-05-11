#include <stdio.h>
#include <conio.h>

#define MAX 20

int graph[MAX][MAX]; // Adjacency matrix
int color[MAX];      // Color assigned to each vertex
int solutions = 0;   // Counter for total solutions

// Function to check if the current color assignment is safe
int isSafe(int vertex, int colors, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && color[i] == colors) {
            return 0; // If any adjacent vertex has the same color
        }
    }
    return 1; // Safe to color
}

// Function to calculate the chromatic number for the current solution
int calculateChromaticNumber(int V) {
    int maxColor = 0;
    for (int i = 0; i < V; i++) {
        if (color[i] > maxColor) {
            maxColor = color[i];
        }
    }
    return maxColor;
}

// Recursive function to generate all possible solutions using state space tree
void stateSpaceTree(int V, int m, int vertex) {
    // Base case: If all vertices are colored, display solution
    if (vertex == V) {
        solutions++;
        int chromaticNumber = calculateChromaticNumber(V);
        printf("\nSolution %d (Chromatic Number: %d):\n", solutions, chromaticNumber);
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
        return;
    }

    // Try assigning each color (from 1 to m)
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, c, V)) {
            color[vertex] = c;
            stateSpaceTree(V, m, vertex + 1); // Recur for the next vertex
            color[vertex] = 0; // Backtrack
        }
    }
}

void main() {
    int V, E, i, j, m;
    clrscr();

    // Input: Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize the graph as an adjacency matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &E);

    // Input: Edges of the undirected graph
    printf("\nEnter the edges (u v) format:\n");
    for (i = 0; i < E; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Constructing undirected graph (bi-directional edges)
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Input: Number of colors
    printf("\nEnter the number of colors available: ");
    scanf("%d", &m);

    // Initialize all vertex colors to 0
    for (i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Generate all possible solutions using state space tree
    printf("\nAll Possible Solutions Using State Space Tree:\n");
    stateSpaceTree(V, m, 0);

    // If no solutions found
    if (solutions == 0) {
        printf("\nNo valid solutions found with %d colors.\n", m);
    } else {
        printf("\nTotal Solutions Found: %d\n", solutions);
    }

    getch();
}
