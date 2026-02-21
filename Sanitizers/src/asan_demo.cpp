#include <iostream>

int main() {
    int* arr = new int[3];
    arr[5] = 42;   // heap buffer overflow
    delete[] arr;
}