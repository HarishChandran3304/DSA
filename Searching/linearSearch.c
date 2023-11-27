#include <stdio.h>


int linearSearch(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, val;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &val);

    int pos = search(arr, n, val);
    if (pos == -1) {
        printf("Value not found!\n");
    } else {
        printf("Value found at position %d\n", pos);
    }

    return 0;
}