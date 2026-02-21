

#include <iostream>

int compute(int* ptr) {
    if (ptr == nullptr)
        std::cout << "Null pointer\n";

    return *ptr;  // possible null dereference
}

int main() {
    int* p = nullptr;
    compute(p);

    int x;
    if (x > 5) {  // uninitialized variable
        std::cout << "big\n";
    }

    return 0;
}
