#include "int_set.h"

int main() {
    std::cout << "Hello World!" << "\n";
    IntSet a = IntSet(5);
    a.Add(1);
    a.Add(2);
    a.Add(2);
    a.Add(3);
    std::cout << a.size() << "\n";
    IntSet b = IntSet(a);
    b.Add(5);
    b.Add(2);
    b.Add(100);
    std::cout << b.size() << "\n";
    return 0;
}

