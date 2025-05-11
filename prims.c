#include <stdio.h>
#include <conio.h>
#define MAX 100
#define INF 9999

int cost[MAX][MAX], key[MAX], parent[MAX], visited[MAX];
int n;

// Adjacency list for MST
int mst[MAX][MAX];
int mstSize[MAX];

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < mstSize[node]; i++) {
        int next = mst[node][i];
        if (!visited[next])
            DFS(next);
    }
}

void prims() {
    int i, j, u, v, min, total_cost = 0;

    for (i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
        mstSize[i] = 0;
    }

    key[0] = 0;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (cost[u][v] != INF && !visited[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    // Build MST adjacency list from parent array
    for (i = 1; i < n; i++) {
        if (parent[i] != -1) {
            int u = parent[i];
            int v = i;
            mst[u][mstSize[u]++] = v;
            mst[v][mstSize[v]++] = u;
        }
    }

    // Print Key and Predecessor Arrays
    printf("\nKey Array:\nNode\tKey\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, key[i]);

    printf("\nPredecessor Array:\nNode\tPredecessor\n");
    for (i = 0; i < n; i++) {
        if (parent[i] != -1)
            printf("%d\t%d\n", i, parent[i]);
        else
            printf("%d\tNone\n", i);
    }

    // Print MST Edges
    printf("\nMinimum Spanning Tree Edges:\n");
    total_cost = 0;
    for (i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d -> %d (cost = %d)\n", parent[i], i, cost[i][parent[i]]);
            total_cost += cost[i][parent[i]];
        }
    }

    // DFS to print path from node 0
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nMinimum Spanning Tree Path from Node 0:\n");
    DFS(0);
    printf("\n");

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", total_cost);
}

void main() {
    int i, j;
    clrscr();
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (Enter 9999 for no direct edge between nodes):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j)
                cost[i][j] = INF;
        }

    prims();
    getch();
}
