#ifndef SORT_H_
#define SORT_H_

void selection_sort(int arr[], int length);

void bubble_sort(int arr[], int length);

void recur_bubble_sort(int arr[], int length);

void insertion_sort(int arr[], int length);

void recur_insertion_sort(int arr[], int length, int sorted_marker = 0);

void merge_sort(int arr[], int l, int r);

void quick_sort(int arr[], int l, int r);

void heap_sort(int arr[], int length);

void counting_sort(int arr[], int length);

void radix_sort(int arr[], int length);


#endif /* SORT_H_ */
