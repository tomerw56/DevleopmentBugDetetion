#include <thread>
#include <iostream>

int counter = 0;

void Worker()
{
    for (int i = 0; i < 1'000'000; ++i)
        counter++;   // ❌ unsynchronized access
}

int main()
{
    std::thread t1(Worker);
    std::thread t2(Worker);

    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << "\n";
}
