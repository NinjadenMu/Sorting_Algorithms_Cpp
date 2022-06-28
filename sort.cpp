#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

void random_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 101;
    }
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

void selection_sort(int arr[], int length) {
    int min;
    int temp;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            } 
        }

        temp = arr[i];
        arr[i] = arr[min]; 
        arr[min] = temp;
    }
}

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
        swap(arr[root], arr[largest_idx]);
        heapify(arr, largest_idx, end);
    }
}

void heap_sort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, i, length - 1);
    }

    for (int i = length - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i - 1);
    }
    cout << endl;
}

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

int main() {
    srand(time(NULL));
    srand(rand());

    int length;
    cout << "Length of array? ";
    cin >> length;

    int arr[length];
    random_array(arr, length);

    cout << "Unsorted Array: ";
    print_array(arr, length);
    cout << endl;

    radix_sort(arr, length);

    cout << "Sorted Array: ";
    print_array(arr, length);
}