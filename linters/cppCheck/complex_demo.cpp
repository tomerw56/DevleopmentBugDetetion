#include <iostream>
#include <cstring>

class Buffer {
public:
    Buffer(size_t size) {
        data = new char[size];
        length = size;
    }

    ~Buffer() {
        delete data;   // ❌ BUG: should be delete[]
    }

    void write(const char* input) {
        if (strlen(input) > length) {
            std::cout << "Too long\n";
        }
        std::strcpy(data, input);  // ❌ possible overflow
    }

private:
    char* data;
    size_t length;
};

int compute(bool flag) {
    int value;

    if (flag)
        value = 42;

    return value;   // ❌ maybe uninitialized
}

int main() {
    Buffer buf(5);
    buf.write("hello world");

    std::cout << compute(false) << "\n";

    return 0;
}
