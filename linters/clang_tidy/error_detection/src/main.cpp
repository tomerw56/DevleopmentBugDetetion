#call with PS D:\DevleopmentBugDetetion\linters\clang_tidy> clang-tidy .\src\main.cpp -- -std=c++20
#include <iostream>
#include <vector>

int* CreateValue()
{
    int x = 42;
    return &x;  // ❌ bugprone-return-stack-address
}

void Process(std::vector<int> v)  // ❌ performance: pass-by-value
{
    for (int i = 0; i < v.size(); i++)  // ❌ signed/unsigned mismatch
    {
        std::cout << v[i] << std::endl;
    }
}

int main()
{
    std::vector<int> values = {1, 2, 3};

    Process(values);

    int* p = CreateValue();
    std::cout << *p << std::endl;  // UB

    return 0;
}

