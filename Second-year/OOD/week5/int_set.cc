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
IntSet::~IntSet() {
    delete[] elements_;
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
int IntSet::operator[] (int index) {
    assert(index >= 0 && "Out-of-bound");
    assert(index < size_ && "Out-of-bound");
    return elements_[index];
}
void IntSet::Add(int value) {
    for (int i = 0; i < size_; i++) {
        if (elements_[i] == value)
            return;
    }
    if (size_ < capacity_) {
        elements_[size_++] = value;
        return;
    }
    capacity_ += 4;
    int *tmp = new int[capacity_];
    for (int i = 0; i < size_; i++) {
        tmp[i] = elements_[i];
    }
    tmp[size_++] = value;
    delete[] elements_;
    elements_ = tmp;
}
void IntSet::Add(const IntSet &int_set) {
    for (int i = 0; i < int_set.size_; i++) {
        Add(int_set.elements_[i]);
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

