#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX

int n; // Number of vertices in the graph
int graph[MAX][MAX]; // Adjacency matrix representation of the graph

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int k = 0; k < n; k++) {
        printf("%d \t %d\n", k, dist[k]);
    }
}

int main() {
    int edges, u, v, w, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int m = 0; m < edges; m++) {
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // If the graph is undirected
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(src);
    return 0;
}
