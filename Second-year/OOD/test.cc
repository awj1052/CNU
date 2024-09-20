#include <iostream>

class A {
 public:
    int* x_;
};

int main() {
    A a1;
    A a2(a1);
    std::cout << *(a1.x_) << " " << a1.x_ << "\n";
    *(a1.x_) = 7;
    std::cout << *(a2.x_) << " " << a2.x_ << "\n";
    return 0;
}