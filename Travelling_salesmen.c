#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n;
int dist[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];

int calculate_cost(int path[]) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += dist[path[i]][path[i + 1]];
    }
    cost += dist[path[n - 1]][path[0]];  
    return cost;
}

void tsp(int current_city, int count, int path[], int* min_cost, int best_path[]) {
    if (count == n) {
        int cost = calculate_cost(path);
        if (cost < *min_cost) {
            *min_cost = cost;
            for (int i = 0; i < n; i++) {
                best_path[i] = path[i];
            }
        }
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[count] = i;
            tsp(i, count + 1, path, min_cost, best_path);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    
    int path[MAX_CITIES], best_path[MAX_CITIES];
    int min_cost = INT_MAX;
    
    visited[0] = 1;
    path[0] = 0;
    tsp(0, 1, path, &min_cost, best_path);
    
    printf("Minimum cost: %d\n", min_cost);
    printf("Best path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\n");
    
    return 0;
}
