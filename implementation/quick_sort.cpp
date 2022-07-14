#include "../sort.h"

int partition(int arr[], int l, int r) {
    int pivot = r;

    int last_smaller_idx = l - 1;
    int temp;
    for (int i = l; i < r; i++) {
        if (arr[i] < arr[pivot]) {
            last_smaller_idx++;
            temp = arr[last_smaller_idx];
            arr[last_smaller_idx] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[last_smaller_idx + 1];
    arr[last_smaller_idx + 1] = arr[pivot];
    arr[pivot] = temp;

    return last_smaller_idx + 1;
}

void quick_sort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}
