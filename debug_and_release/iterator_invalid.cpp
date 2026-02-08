// iterator_invalid.cpp
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3};

    auto it = v.begin();
    v.push_back(4);   // invalidates iterators

    *it = 10;         // ❌ invalid iterator
}
