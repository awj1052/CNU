#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <assert.h>
#include <string>

class Vector {
 public:
    explicit Vector(std::size_t capacity);
    Vector(const Vector& vector);
    virtual ~Vector();
    void operator=(const Vector& vector);
    int& operator[](const int index);
    int size() const;
    int capacity() const;
    void PushBack(int elem);
    void PopBack();
    bool IsEmpty() const;
 private:
    int* elements_;
    int capacity_;
    int size_;
};

#endif   // _VECTOR_H_
