#include "util.h"

int Util::Add(int x, int y) {
    return x + y;
}

int Util::Sub(int x, int y) {
    return x - y;
}

int Util::Mul(int x, int y) {
    return x * y;
}

int Util::Div(int x, int y) {
    assert(y != 0 && "Divide-by-Zero");
    return x / y;
}
