#include "int_set.h"

IntSet::IntSet(int capacity) :
    capacity_(capacity),
    size_(0),
    elements_(new int[capacity]) {}
IntSet::IntSet(const IntSet &int_set) :
    capacity_(int_set.capacity_),
    size_(int_set.size_),
    elements_(new int[capacity_]) {
    for (int i = 0; i < size_; i++) {
        elements_[i] = int_set.elements_[i];
    }
}
int IntSet::capacity() const {
    return capacity_;
}
int IntSet::size() const {
    return size_;
}
int *IntSet::elements() const {
    return elements_;
}
void IntSet::Add(int value) {
    for (int i = 0; i < size_; i++) {
        if (elements_[i] == value)
            return;
    }
    assert(size_ < capacity_ && "Exceeded capacity");
    elements_[size_++] = value;
}
void IntSet::Add(const IntSet &int_set) {
    for (int i = 0; i < int_set.size_; i++) {
        bool flag = true;
        for (int j = 0; j < size_; j++) {
            if (elements_[j] == int_set.elements_[i]) {
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;
        assert(size_ < capacity_ && "Exceeded capacity");
        elements_[size_++] = int_set.elements_[i];
    }
}
void IntSet::Map(std::function<int(int)> f) {
    for (int i = 0; i < size_; i++) {
        elements_[i] = f(elements_[i]);
    }
}
bool IntSet::ForAll(std::function<bool(int)> f) {
    for (int i = 0; i < size_; i++) {
        if (!f(elements_[i]))
            return false;
    }
    return true;
}

