#include "int_accumulator.h"

int_accumulator::Accumulator::Accumulator(int acc) : acc_(acc) {}
void int_accumulator::Accumulator::Add(int x) {
    acc_ = acc_ + x;
}
void int_accumulator::Accumulator::Sub(int x) {
    acc_ = acc_ - x;
}
void int_accumulator::Accumulator::Mul(int x) {
    acc_ = acc_ * x;
}
void int_accumulator::Accumulator::Div(int x) {
    assert(x != 0 && "Divide-by-zero");
    acc_ = acc_ / x;
}
int int_accumulator::Accumulator::acc() {
    return acc_;
}
