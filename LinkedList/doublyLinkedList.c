#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};


void printList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

bool search(struct Node* head, int val) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->val == val) return true;
        ptr = ptr->next;
    }
    return false;
}

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) *head = newNode;
    else {
        struct Node* ptr = *head;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

void delete(struct Node** head, int val) {
    if (*head == NULL) printf("List is empty\n");
    else {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        while (curr != NULL && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) printf("Element not found\n");
        else {
            if (prev == NULL) *head = curr->next;
            else prev->next = curr->next;
            free(curr);
        }
    }
}


int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        insert(&head, val);
    }

    printf("Elements in the list: ");
    printList(head);
    printf("\n");

    printf("Enter the element to be deleted: ");
    int val;
    scanf("%d", &val);
    delete(&head, val);

    printf("Elements in the list: ");
    printList(head);
    printf("\n");

    return 0;
}