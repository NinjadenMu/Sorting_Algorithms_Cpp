#include "../sort.h"

void counting_sort(int arr[], int length) {
    int max = arr[0];
    int min = arr[0];
    for (int i  = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int count[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < max - min + 1; i++) {
        count[i] += count[i - 1];
    }

    int sorted_arr[length];
    for (int i = 0; i < length; i++) {
        sorted_arr[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < length; i++) {
        arr[i] = sorted_arr[i];
    }
}
