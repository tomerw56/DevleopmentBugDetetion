#include <vector>
#include <iostream>

int main()
{
    std::vector<int> data = { 1, 2, 3, 4 };

    int sum = 0;
    for (size_t i = 0; i <= data.size(); ++i) // ❌ off-by-one
        sum += data[i];

    std::cout << "Should not work!! Sum = " << sum << "\n";
}
