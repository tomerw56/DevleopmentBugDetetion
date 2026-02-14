#include <iostream>
#include <vector>
using namespace std;

class MyClass {
   public:
    int SOME_value;
    explicit MyClass(int x) : SOME_value(x) { }
    static void doStuff() {
        for (int i = 0; i < 10; i++) {
            cout << "number:" << i << endl;
        }
    }
};

auto addNumbers(int A, int b) -> int { return A + b; }

auto main() -> int {
    MyClass obj(5);
    obj.doStuff();
    int result = addNumbers(10, 20);
    if (result > 10) {
        cout << "big" << endl;
    } else {
        cout << "small" << endl;
}
    return 0;
}
