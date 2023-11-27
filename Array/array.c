#include <stdio.h>


void insert(int arr[], int n) {
    int pos, val;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &val);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete(int arr[], int n) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int arr[], int n) {
    int val;
    printf("Enter the value to search: ");
    scanf("%d", &val);

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Value found at position %d\n", i);
            return;
        }
    }
    printf("Value not found!\n");
}

void display(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Enter the operation to be performed:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, n);
                break;
            case 2:
                delete(arr, n);
                break;
            case 3:
                search(arr, n);
                break;
            case 4:
                display(arr, n);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}