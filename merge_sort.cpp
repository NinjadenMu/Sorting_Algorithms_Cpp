#include "sort.h"

void merge(int arr[], int l, int m, int r) {
    int l_compare = l;
    int r_compare = m + 1;

    int merge_slice_copy[r - l + 1];
    for (int i = l; i < r + 1; i++) {
        merge_slice_copy[i - l] = arr[i];
    }

    for (int i = l; i < r + 1; i++) {
        if (l_compare <= m & r_compare <= r) {
            if (merge_slice_copy[l_compare - l] <= merge_slice_copy[r_compare - l]) {
                arr[i] = merge_slice_copy[l_compare - l];
                l_compare++;
            }

            else{
                arr[i] = merge_slice_copy[r_compare - l];
                r_compare++;
            }
        }

        else if (l_compare > m) {
            arr[i] = merge_slice_copy[r_compare - l];
            r_compare++;
        }

        else {
            arr[i] = merge_slice_copy[l_compare - l];
            l_compare++;
        }
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l == r) {
        return;
    }

    merge_sort(arr, l, int((l + r) / 2));
    merge_sort(arr, int((l + r) / 2) + 1, r);
    merge(arr, l, int((l + r) / 2), r);
}
