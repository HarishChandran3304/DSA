#include <stdio.h>


int binarySearch(int arr[], int l, int r, int val) {
    if (l>r) return -1;

    int m = (l+r)/2;
    if (arr[m] == val) return m;

    if (val < arr[m]) binarySearch(arr, l, m-1, val);
    else binarySearch(arr, m+1, r, val);
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

    int pos = binarySearch(arr, 0, n-1, val);
    if (pos == -1) {
        printf("Value not found!\n");
    } else {
        printf("Value found at position %d\n", pos);
    }

    return 0;
}