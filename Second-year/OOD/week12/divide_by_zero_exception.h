#ifndef _DIVIDE_BY_ZERO_EXCEPTION_H_
#define _DIVIDE_BY_ZERO_EXCEPTION_H_

#include <stdexcept>

class DivideByZeroException : public std::runtime_error {
 public:
    explicit DivideByZeroException(const char* what) :
        std::runtime_error(what) {}
};

#endif    // _DIVIDE_BY_ZERO_EXCEPTION_H_
