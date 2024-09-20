#ifndef _INT_ACCUMULATOR_H_
#define _INT_ACCUMULATOR_H_

#include <assert.h>

namespace int_accumulator {
class Accumulator {
 public:
    explicit Accumulator(int acc);
    void Add(int x);
    void Sub(int x);
    void Mul(int x);
    void Div(int x);
    int acc();
 private:
    int acc_;
};
};   // namespace int_accumulator

#endif
