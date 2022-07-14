#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "sort.h"

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

    recur_insertion_sort(arr, length); //replace with desired sorting algorithm

    cout << "Sorted Array: ";
    print_array(arr, length);
}
