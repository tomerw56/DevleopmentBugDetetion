#include <iostream>

int main() {
    std::cout << "About to crash...\n";
    int* p = nullptr;
    *p = 42;   // access violation
}