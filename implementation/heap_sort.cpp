#include "../sort.h"

void heapify(int arr[], int root, int end) {
    int l = root * 2 + 1;
    int r = root * 2 + 2;
    int largest_idx = root;

    if (l <= end && arr[l] > arr[largest_idx]) {
        largest_idx = l;
    }

    if (r <= end && arr[r] > arr[largest_idx]) {
        largest_idx = r;
    }

    if (largest_idx != root) {
    	int temp = arr[root];
    	arr[root] = arr[largest_idx];
    	arr[largest_idx] = temp;

        heapify(arr, largest_idx, end);
    }
}

void heap_sort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, i, length - 1);
    }

    int temp;
    for (int i = length - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, 0, i - 1);
    }
}
