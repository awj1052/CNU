#ifndef _STACK_H_
#define _STACK_H_

#include "vector.h"

class Stack : private Vector {
 public:
    explicit Stack(std::size_t capacity);
    Stack(const Stack& stack);
    void operator=(const Stack& stack);
    int size() const;
    int capacity() const;
    void Push(int elem);
    int Pop();
    bool IsEmpty() const;
};

#endif   // _STACK_H_
