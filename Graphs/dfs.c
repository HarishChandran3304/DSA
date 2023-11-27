#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int stack[100];
int top = -1;


bool isEmpty() {
    return top == -1;
}

void push(int n) {
    stack[++top] = n;
}

int pop() {
    return stack[top--];
}


void dfs(int adj[][100], int n, int start) {
    bool visited[n];
    for (int i=0; i<n; i++) visited[i] = false;

    push(start);
    visited[start] = true;

    while (!isEmpty()) {
        int curr = pop();
        printf("%d ", curr);

        for (int i=0; i<n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                push(i);
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

    printf("DFS traversal: ");
    dfs(adj, n, start);
    printf("\n");

    return 0;
}