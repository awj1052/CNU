#include "int_accumulator.h"

namespace int_accumulator {
Accumulator::Accumulator(int acc) : acc_(acc) {}
void Accumulator::Add(int x) {
    acc_ = acc_ + x;
}
void Accumulator::Sub(int x) {
    acc_ = acc_ - x;
}
void Accumulator::Mul(int x) {
    acc_ = acc_ * x;
}
void Accumulator::Div(int x) {
    assert(x != 0 && "Divide-by-zero");
    acc_ = acc_ / x;
}
int Accumulator::acc() {
    return acc_;
}
}   // namespace int_accumulator