#include "float_accumulator.h"

float_accumulator::Accumulator::Accumulator(float acc) : acc_(acc) {}
void float_accumulator::Accumulator::Add(float x) {
    acc_ = acc_ + x;
}
void float_accumulator::Accumulator::Sub(float x) {
    acc_ = acc_ - x;
}
void float_accumulator::Accumulator::Mul(float x) {
    acc_ = acc_ * x;
}
void float_accumulator::Accumulator::Div(float x) {
    assert(x != 0 && "Divide-by-zero");
    acc_ = acc_ / x;
}
float float_accumulator::Accumulator::acc() {
    return acc_;
}
