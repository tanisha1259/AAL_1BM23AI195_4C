#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else if (subsets[rootX].rank > subsets[rootY].rank) {
            subsets[rootY].parent = rootX;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void Kruskal(struct Graph* graph) {
    struct Edge result[graph->V]; 
    int e = 0; 
    int i = 0; 
    struct Subset* subsets = (struct Subset*)malloc(graph->V * sizeof(struct Subset));

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    for (i = 0; i < graph->V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0; 

    while (e < graph->V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edge[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the MST:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);

    free(subsets);
}

int main() {
    int V = 4; 
    int E = 5;  

    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0; graph->edge[0].dest = 1; graph->edge[0].weight = 10;
    graph->edge[1].src = 0; graph->edge[1].dest = 2; graph->edge[1].weight = 6;
    graph->edge[2].src = 0; graph->edge[2].dest = 3; graph->edge[2].weight = 5;
    graph->edge[3].src = 1; graph->edge[3].dest = 3; graph->edge[3].weight = 15;
    graph->edge[4].src = 2; graph->edge[4].dest = 3; graph->edge[4].weight = 4;

    Kruskal(graph);

    free(graph->edge);
    free(graph);
}

