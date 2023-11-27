#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int deque[100];
int capacity = 5;
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear+1)%capacity == front;
}

void addFront(int val) {
    if (isFull()) printf("Deque Overflow\n");
    else {
        if (front == -1) front = rear = 0;
        else front = (front - 1 + capacity) % capacity;
        deque[front] = val;
    }
}

void addRear(int val) {
    if (isFull()) printf("Deque Overflow\n");
    else {
        if (front == -1) front = rear = 0;
        else rear = (rear + 1) % capacity;
        deque[rear] = val;
    }
}

int removeFront() {
    if (isEmpty()) printf("Deque Underflow\n");
    else {
        int val = deque[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        return val;
    }
}

int removeRear() {
    if (isEmpty()) printf("Deque Underflow\n");
    else {
        int val = deque[rear];
        if (front == rear) front = rear = -1;
        else rear = (rear - 1 + capacity) % capacity;
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
        addRear(val);
    }

    printf("Elements in the deque: ");
    while (!isEmpty()) {
        printf("%d ", removeFront());
    }
    printf("\n");

    return 0;
}