#include <iostream>

int* GetPointer()
{
    int x = rand();
    std::cout<<"random value "<< x<<std::endl;
    return &x;  //returning pointer to stack memory
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        int* p = GetPointer();
        std::cout<<"test "<<i<<" - " << *p << "\n";  // UB
    }
}
