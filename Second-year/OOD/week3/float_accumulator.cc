#include "float_accumulator.h"

namespace float_accumulator {
Accumulator::Accumulator(float acc) : acc_(acc) {}
void Accumulator::Add(float x) {
    acc_ = acc_ + x;
}
void Accumulator::Sub(float x) {
    acc_ = acc_ - x;
}
void Accumulator::Mul(float x) {
    acc_ = acc_ * x;
}
void Accumulator::Div(float x) {
    assert(x != 0 && "Divide-by-zero");
    acc_ = acc_ / x;
}
float Accumulator::acc() {
    return acc_;
}
}   // namespace float_accumulator
