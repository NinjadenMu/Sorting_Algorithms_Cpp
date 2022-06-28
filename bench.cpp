#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void random_array(int length, int array[]) {
    for (int i = 0; i < length; i++) {
        srand(time(NULL));
        array[i] = rand() % 101;
    }
}

int main() {
    
}