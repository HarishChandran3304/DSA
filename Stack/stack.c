#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int stack[100];
int capacity = 5;
int top = -1;


bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == capacity-1 ;
}

void push(int val) {
    if (isFull()) printf("Stack Overflow\n");
    else stack[++top] = val; 
}

int pop() {
    if (isEmpty()) printf("Stack Underflow\n");
    else return stack[top--];
}


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        push(val);
    }

    printf("Elements in the stack: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}