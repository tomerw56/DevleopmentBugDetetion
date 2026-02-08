// atomic_ordering_bug.cpp
#include <atomic>
#include <iostream>

std::atomic<bool> ready = false;
int data = 0;

void Producer()
{
    data = 42;
    ready.store(true, std::memory_order_relaxed); // no release
}

void Consumer()
{
    while (!ready.load(std::memory_order_relaxed)) {}
    std::cout << data << "\n"; //  may see stale data
}
