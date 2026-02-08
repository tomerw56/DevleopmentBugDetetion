#include <vector>
#include <chrono>
#include <iostream>

int main()
{
    const int N = 5'000'000;
    std::vector<int> data;
    //uncomment and comment the push for better performance;
    //data.reserve(N);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
        data.push_back(i); // ❌ repeated reallocations
        //data[i] = i;
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Time: "
        << std::chrono::duration<double>(end - start).count()
        << " seconds\n";
}
