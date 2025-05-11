#include <stdio.h>
#include<conio.h>
#include <limits.h>

#define MAX_NODES 100

int findMinDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src) {
    int dist[MAX_NODES];  // Stores the shortest distance from src to each node
    int visited[MAX_NODES] = {0};  // Keeps track of visited nodes
    int parent[MAX_NODES]; // Stores the parent node for each vertex

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1; // Initialize parent of each node as -1
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nVertex\tDistance\tParent\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t", i, dist[i], parent[i]);
        printPath(parent, i);
        printf("\n");
    }
}

void main() {
    int n, src;
    int graph[MAX_NODES][MAX_NODES];
    clrscr();
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no direct edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    getch();
}


