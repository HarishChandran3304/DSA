#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int queue[100];
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}

void enqueue(int n) {
    if (front == -1) front = 0;
    queue[++rear] = n;
}

int dequeue() {
    return queue[front++];
}

void bfs(int adj[][100], int n, int start) {
    bool visited[n];
    for (int i=0; i<n; i++) visited[i] = false;

    enqueue(start);
    visited[start] = true;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        for (int i=0; i<n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}


int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][100];
    printf("Enter adjacency matrix:\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(adj, n, start);
    printf("\n");

    return 0;
}