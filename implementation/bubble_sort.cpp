#include "../sort.h"

void bubble_sort(int arr[], int length) {
    int swaps;
    int temp;

    do {
        swaps = 0;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swaps++;
            }
        }

    } while (swaps > 0);
}
