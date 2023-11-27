#include <stdio.h>
#include <stdlib.h>


int stack[100];
int top = -1;


void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i=0;
    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') push(postfix[i] - '0');
        else {
            int op1 = pop();
            int op2 = pop();
            switch (postfix[i]) {
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1); break;
                case '*': push(op2 * op1); break;
                case '/': push(op2 / op1); break;
            }
        }
        i++;
    }

    return pop();
}


int main() {
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}