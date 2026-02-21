#include <iostream>

int main() {
    int x = 2147483647;
    int y = x + 1;  // signed overflow UB

    std::cout << y << "\n";
    return 0;
}