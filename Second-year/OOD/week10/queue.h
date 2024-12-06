#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "list.h"

template <typename T>
class Queue : private List<T> {
 public:
    Queue() : List<T>() {}
    Queue(const Queue& queue) : List<T>(queue) {}
    void operator=(const Queue& queue) {
        List<T>::operator=(queue);
    }
    int size() const {
        return List<T>::size();
    }
    void Add(T elem) {
        List<T>::PushBack(elem);
    }
    T Poll() {
        T poll = List<T>::At(0);
        List<T>::PopFront();
        return poll;
    }
    bool IsEmpty() const {
        return List<T>::IsEmpty();
    }
};

#endif   // _QUEUE_H_
