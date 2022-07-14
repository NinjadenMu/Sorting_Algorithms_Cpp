#include "../sort.h"
#include <cmath>

void radix_sort_helper(int arr[], int length, int place) {
    int place_arr[length];

    for (int i = 0; i < length; i++) {
        place_arr[i] = arr[i] / pow(10, place);
        place_arr[i] %= 10;
    }

    int max = place_arr[0];
    int min = place_arr[0];
    for (int i  = 0; i < length; i++) {
        if (place_arr[i] > max) {
            max = place_arr[i];
        }

        if (place_arr[i] < min) {
            min = place_arr[i];
        }
    }

    int count[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[place_arr[i] - min]++;
    }

    for (int i = 1; i < max - min + 1; i++) {
        count[i] += count[i - 1];
    }

    int sorted_arr[length];
    for (int i = length - 1; i >= 0; i--) {
        sorted_arr[count[place_arr[i] - min] - 1] = arr[i];
        count[place_arr[i] - min]--;
    }

    for (int i = 0; i < length; i++) {
        arr[i] = sorted_arr[i];
    }
}

void radix_sort(int arr[], int length) {
    int max = arr[0];
    for (int i  = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int max_places = log10(max) + 1;

    for (int i = 0; i < max_places; i++) {
        radix_sort_helper(arr, length, i);
    }
}
