#ifndef _FLOAT_ACCUMULATOR_H_
#define _FLOAT_ACCUMULATOR_H_

#include <assert.h>

namespace float_accumulator {
class Accumulator {
 public:
    explicit Accumulator(float acc);
    void Add(float x);
    void Sub(float x);
    void Mul(float x);
    void Div(float x);
    float acc();
 private:
    float acc_;
};
};   // namespace float_accumulator

#endif
