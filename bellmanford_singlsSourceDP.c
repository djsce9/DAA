#include <stdio.h>
#include <conio.h>

#define MAX 100
#define INF 9999

// Function to display the shortest path from source to a given vertex
void printPath(int predecessor[], int vertex) {
    if (vertex < 0) {
        return;
    }
    printPath(predecessor, predecessor[vertex]);
    printf("%d ", vertex);
}

// Function to implement Bellman-Ford algorithm
void bellmanFord(int graph[MAX][MAX], int V, int E, int source) {
    int distance[MAX], predecessor[MAX], i, j, u, v, w;
    struct Edge {
        int src, dest, weight;
    } edges[MAX];

    // Reading edges from the adjacency matrix
    int k = 0;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    // Initialize distances and predecessor array
    for (i = 0; i < V; i++) {
        distance[i] = INF;
        predecessor[i] = -1;
    }
    distance[source] = 0;

    // Relaxation step (V-1) times
    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            u = edges[j].src;
            v = edges[j].dest;
            w = edges[j].weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                predecessor[v] = u;
            }
        }
    }

    // Negative cycle detection
    for (j = 0; j < E; j++) {
        u = edges[j].src;
        v = edges[j].dest;
        w = edges[j].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("\nGraph contains a negative weight cycle!\n");
            return;
        }
    }

    // Display the shortest distances
    printf("\nShortest Distances from Source (Vertex %d):\n", source);
    for (i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, distance[i]);
    }

    // Display the predecessor array
    printf("\nPredecessor Array:\n");
    for (i = 0; i < V; i++) {
        printf("Vertex %d: %d\n", i, predecessor[i]);
    }

    // Display the shortest paths
    printf("\nShortest Paths from Source (Vertex %d):\n", source);
    for (i = 0; i < V; i++) {
        if (i == source) {
            printf("Vertex %d -> Vertex %d: Cost = 0, Path: %d\n", source, i, source);
        } else if (distance[i] == INF) {
            printf("Vertex %d -> Vertex %d: No Path\n", source, i);
        } else {
            printf("Vertex %d -> Vertex %d: Cost = %d, Path: ", source, i, distance[i]);
            printPath(predecessor, i);
            printf("\n");
        }
    }
}

void main() {
    int V, E, i, j, source;
    int graph[MAX][MAX];
    clrscr();

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize the graph with INF (No edge)
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0; // Distance to self is 0
            else
                graph[i][j] = INF; // No edge is INF
        }
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &E);

    // Input edges and their weights
    printf("\nEnter edges (source, destination, weight):\n");
    for (i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    // Run Bellman-Ford Algorithm
    bellmanFord(graph, V, E, source);

    getch();
}
