#include "safe_int.h"

SafeInt::SafeInt(int n) : value_(n) {}
SafeInt::SafeInt() : SafeInt(0) {}
SafeInt SafeInt::operator+(const SafeInt& x) const {
    const int kMin = std::numeric_limits<int>::min();
    const int kMax = std::numeric_limits<int>::max();
    if (value_ > 0 && x.value_ > 0) {
        if (value_ > kMax - x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " + "
                + std::to_string(x.value_));
        }
    } else if (value_ < 0 && x.value_ < 0) {
        if (value_ < kMin - x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " + "
                + std::to_string(x.value_));
        }
    }
    return SafeInt(value_ + x.value_);
}
SafeInt SafeInt::operator-(const SafeInt& x) const {
    const int kMin = std::numeric_limits<int>::min();
    const int kMax = std::numeric_limits<int>::max();
    if (value_ > 0 && x.value_ < 0) {
        if (value_ > kMax + x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " - "
                + std::to_string(x.value_));
        }
    } else if (value_ < 0 && x.value_ > 0) {
        if (value_ < kMin + x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " - "
                + std::to_string(x.value_));
        }
    }
    return SafeInt(value_ - x.value_);
}
SafeInt SafeInt::operator*(const SafeInt& x) const {
        if (value_ > 0 && x.value_ > 0
            && value_ > std::numeric_limits<int>::max() / x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " * " + std::to_string(x.value_));
        }
        if (value_ < 0 && x.value_ < 0
            && value_ < std::numeric_limits<int>::max() / x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " * " + std::to_string(x.value_));
        }
        if ((value_ > 0 && x.value_ < 0 || value_ < 0 && x.value_ > 0) &&
            value_ < std::numeric_limits<int>::min() / x.value_) {
            throw std::overflow_error(
                "Integer overflow occurs in "
                + std::to_string(value_) + " * " + std::to_string(x.value_));
        }
    return SafeInt(value_ * x.value_);
}
SafeInt SafeInt::operator/(const SafeInt& x) const {
    if (x.value_ == 0) {
        throw DivideByZeroException(
            ("Divide-by-zero exception occurs in "
            + std::to_string(value_) + "/0").c_str());
    }
    return SafeInt(value_ / x.value_);
}
SafeInt SafeInt::operator%(const SafeInt& x) const {
    if (x.value_ == 0) {
        throw DivideByZeroException(
            ("Divide-by-zero exception occurs in "
            + std::to_string(value_) + "%0").c_str());
    }
    return SafeInt(value_ % x.value_);
}
int SafeInt::value() const {
    return value_;
}
