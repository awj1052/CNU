#include <iostream>

#include "int_accumulator.h"
#include "float_accumulator.h"

int main() {
    int_accumulator::Accumulator intAcc(5);
    float_accumulator::Accumulator floatAcc(5.0);
    int operand = 3;

    intAcc.Add(operand);
    floatAcc.Div(operand);
    std::cout << intAcc.acc() << "\n" << floatAcc.acc() << "\n";
    return 0;
}
