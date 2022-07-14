#include "sort.h"

void insertion_sort(int arr[], int length) {
    int num_to_check_idx;
    int prev_idx;
    int temp;

    for (int i = 0; i < length - 1; i ++) {
        num_to_check_idx = i + 1;
        prev_idx = i;

        while (arr[num_to_check_idx] < arr[prev_idx] & prev_idx >= 0) {
            temp = arr[prev_idx];
            arr[prev_idx] = arr[num_to_check_idx];
            arr[num_to_check_idx] = temp;
            prev_idx--;
            num_to_check_idx--;
        }
    }
}
