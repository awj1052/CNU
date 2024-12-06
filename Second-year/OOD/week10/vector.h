#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <assert.h>
#include <string>

template <typename T>
class Vector {
 public:
    explicit Vector(std::size_t capacity) :
        elements_(new T[capacity]),
        capacity_(capacity),
        size_(0) {}
    Vector(const Vector& vector) :
        elements_(new T[vector.capacity_]),
        capacity_(vector.capacity_),
        size_(vector.size_) {
        for (int i = 0; i < vector.size_; i++) {
            elements_[i] = vector.elements_[i];
        }
    }
    virtual ~Vector() {
        delete[] elements_;
    }
    void operator=(const Vector& vector) {
        delete[] elements_;
        elements_ = new int[vector.capacity_];
        for (int i = 0; i < vector.size_; i++) {
            elements_[i] = vector.elements_[i];
        }
        capacity_ = vector.capacity_;
        size_ = vector.size_;
    }
    T& operator[](const int index) {
        assert((index >= 0 && index < size_) && "Out-of-bound");
        return elements_[index];
    }
    int size() const {
        return size_;
    }
    int capacity() const {
        return capacity_;
    }
    void PushBack(T elem) {
        if (size_ == capacity_) {
        T* tmp = new int[capacity_ + 4];
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
    void PopBack() {
        assert(size_ > 0 && "Out-of-bound");
        size_--;
    }
    bool IsEmpty() const {
        return size_ == 0;
    }

 private:
    T* elements_;
    int capacity_;
    int size_;
};

#endif   // _VECTOR_H_