// stl_bounds_demo.cpp
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1,2,3};

    std::cout << "Size = " << v.size() << "\n";

    // ❌ Out of bounds
    v[5] = 123;

    std::cout << "Done\n";
    return 0;
}
