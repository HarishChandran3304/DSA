#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char stack[100];
int top = -1;


void push(char val) {
    stack[++top] = val;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

char* infixToPostfix(char* infix) {
    char* postfix = (char*)malloc(sizeof(char) * 100);

    int i=0, j=0;
    while (infix[i] != '\0') {
        if (infix[i] == '(') push(infix[i]);

        else if (infix[i] == ')') {
            while (stack[top] != '(') postfix[j++] = pop();
            pop();
        }

        else if (isOperator(infix[i])) {
            while (precedence(stack[top]) >= precedence(infix[i])) postfix[j++] = pop();
            push(infix[i]);
        }

        else postfix[j++] = infix[i];

        i++;
    }

    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;
}


int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}