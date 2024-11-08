#include "vector.h"

Vector::Vector(std::size_t capacity) :
    elements_(new int[capacity]),
    capacity_(capacity),
    size_(0) {}
Vector::Vector(const Vector& vector) :
    elements_(new int[vector.capacity_]),
    capacity_(vector.capacity_),
    size_(vector.size_) {
    for (int i = 0; i < vector.size_; i++) {
        elements_[i] = vector.elements_[i];
    }
}
Vector::~Vector() {
    delete[] elements_;
}
void Vector::operator=(const Vector& vector) {
    delete[] elements_;
    elements_ = new int[vector.capacity_];
    for (int i = 0; i < vector.size_; i++) {
        elements_[i] = vector.elements_[i];
    }
    capacity_ = vector.capacity_;
    size_ = vector.size_;
}
int& Vector::operator[](const int index) {
    assert((index >= 0 && index < size_) && "Out-of-bound");
    return elements_[index];
}
int Vector::size() const {
    return size_;
}
int Vector::capacity() const {
    return capacity_;
}
void Vector::PushBack(int elem) {
    if (size_ == capacity_) {
        int* tmp = new int[capacity_ + 4];
        for (int i = 0; i < size_; i++) {
            tmp[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = tmp;
        capacity_ += 4;
    }
    elements_[size_] = elem;
    size_++;
}
void Vector::PopBack() {
    assert(size_ > 0 && "Out-of-bound");
    size_--;
}
bool Vector::IsEmpty() const {
    return size_ == 0;
}
