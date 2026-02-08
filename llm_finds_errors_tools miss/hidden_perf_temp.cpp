// hidden_perf_temp.cpp
#include <vector>

struct BigObject
{
    int payload[1024];
};

BigObject Transform(int x)
{
    BigObject obj{};
    obj.payload[0] = x;
    return obj;   // returns large object
}

void Process(const std::vector<int>& items)
{
    std::vector<BigObject> result;

    for (int item : items)
    {
        result.push_back(Transform(item)); // temporary + move/copy
    }
}
