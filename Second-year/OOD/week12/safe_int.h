#ifndef _SAFE_INT_H_
#define _SAFE_INT_H_

#include <limits>

#include "empty_container_exception.h"
#include "divide_by_zero_exception.h"

class SafeInt {
 public:
    SafeInt();
    explicit SafeInt(int n);
    SafeInt operator+(const SafeInt& x) const;
    SafeInt operator-(const SafeInt& x) const;
    SafeInt operator*(const SafeInt& x) const;
    SafeInt operator/(const SafeInt& x) const;
    SafeInt operator%(const SafeInt& x) const;
    int value() const;
 private:
    int value_;
};

#endif   // _SAFE_INT_H_
