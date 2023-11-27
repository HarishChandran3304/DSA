#include <stdio.h>
#include <stdlib.h>


int size = 0;
int minHeap[100];


int parent(int i) {
    if (i == 0) return 0;
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && minHeap[l] < minHeap[smallest]) smallest = l;
    if (r < size && minHeap[r] < minHeap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        heapify(smallest);
    }
}

void insert(int n) {
    minHeap[size++] = n;

    int i = size - 1;
    while (i != 0 && minHeap[parent(i)] > minHeap[i]) {
        swap(&minHeap[parent(i)], &minHeap[i]);
        i = parent(i);
    }
}

void delete(int n) {
    int i;
    for (i = 0; i < size; i++)
        if (minHeap[i] == n) break;

    swap(&minHeap[i], &minHeap[size - 1]);
    size--;

    heapify(i);
}

void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
}

void buildHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) minHeap[i] = arr[i];
    size = n;

    for (int i = n / 2 - 1; i >= 0; i--) heapify(i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&minHeap[0], &minHeap[i]);
        size--;
        heapify(0);
    }
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(val);
    }

    printf("Heap: ");
    printHeap();

    printf("Enter element to delete: ");
    int val;
    scanf("%d", &val);
    delete(val);

    printf("Heap: ");
    printHeap();
    
    return 0;
}