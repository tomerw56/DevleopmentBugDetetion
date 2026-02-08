#include <iostream>

int main()
{
    int arr[4] = { 1, 2, 3, 4 };

    std::cout << "Writing out of bounds...\n";
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = 42;  // ❌ out-of-bounds write
    }
    std::cout << "Done\n";
    return 0;
}
