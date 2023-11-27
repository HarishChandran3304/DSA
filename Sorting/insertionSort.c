#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int j = i;
        while (j>=0 && arr[j] < arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}


int main() {
    int arr[100], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Array after sorting: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}