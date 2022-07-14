#include "sort.h"

void recur_insertion_sort(int arr[], int length, int sorted_marker) {
    if (sorted_marker == length - 1 | length == 1 | length == 0) {
        return;
    }

    int num_to_check_idx = sorted_marker + 1;
    int prev_idx = sorted_marker;
    int temp;
    while (arr[num_to_check_idx] < arr[prev_idx] & prev_idx >= 0) {
        temp = arr[prev_idx];
        arr[prev_idx] = arr[num_to_check_idx];
        arr[num_to_check_idx] = temp;
        prev_idx--;
        num_to_check_idx--;
    }

    recur_insertion_sort(arr, length, sorted_marker + 1);
}
