#include "../sort.h"

void recur_bubble_sort(int arr[], int length) {
    if (length == 1) {
        return;
    }

    int swaps = 0;
    int temp;

    for (int i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swaps++;
        }
    }

    if (swaps == 0) {
        return;
    }

    recur_bubble_sort(arr, length - 1);
}
