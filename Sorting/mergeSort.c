#include <stdio.h>


void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int j=0; j<n2; j++) R[j] = arr[m+1+j];

    int i=0, j=0, k=l;
    while (i < n1 && j < n2) arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;

    int m = (l+r)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    
    merge(arr, l, m, r);
}


int main() {
    int arr[100], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("Array after sorting: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}