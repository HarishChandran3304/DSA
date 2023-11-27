#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int queue[100];
int capacity = 5;
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == capacity-1;
}

void enqueue(int val) {
    if (isFull()) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

int dequeue() {
    if (isEmpty()) printf("Queue Underflow\n");
    else {
        int val = queue[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
}


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Elements in the queue: ");
    while (!isEmpty()) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}