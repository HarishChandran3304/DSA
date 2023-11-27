#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


void dijkstras(int n, int adj[n][n], int src) {
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX;
        int minIndex;

        // Find the minimum distance vertex not yet processed
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min) {
                min = dist[j];
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        // Update the distances of adjacent vertices
        for (int j = 0; j < n; j++) {
            if (!visited[j] && !adj[minIndex][j] && dist[minIndex] != INT_MAX && dist[minIndex] + adj[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + adj[minIndex][j];
            }
        }
    }
}


int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstras(n, adj, src);

    return 0;
}