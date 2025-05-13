#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

void createGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 1;
}

void topologicalSortUtil(struct Graph* g, int v, int visited[], int* stack, int* topIndex) {
    visited[v] = 1;
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] == 1 && !visited[i]) {
            topologicalSortUtil(g, i, visited, stack, topIndex);
        }
    }
    stack[*topIndex] = v;
    (*topIndex)++;
}

void topologicalSort(struct Graph* g) {
    int visited[MAX] = {0};
    int stack[MAX];
    int topIndex = 0;
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(g, i, visited, stack, &topIndex);
        }
    }
    printf("Topological Sort: ");
    for (int i = topIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    struct Graph g;
    createGraph(&g, 6);
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);
    topologicalSort(&g);
    return 0;
}
