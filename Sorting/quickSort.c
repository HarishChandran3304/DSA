#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int pivot = l;

    while (1) {
        while (arr[l] < arr[pivot]) l++;
        while (arr[r] > arr[pivot]) r--;
        if (l >= r) return r;
        swap(&arr[l], &arr[r]);
    }
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;

    int p = partition(arr, l, r);
    quickSort(arr, l, p);
    quickSort(arr, p+1, r);
}


int main() {
    int arr[100], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);

    printf("Array after sorting: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}