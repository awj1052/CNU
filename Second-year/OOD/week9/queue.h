#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "list.h"

class Queue : private List {
 public:
    Queue();
    Queue(Queue& queue);
    void operator=(Queue& queue);
    int size() const;
    void Add(int elem);
    int Poll();
    bool IsEmpty() const;
};

#endif   // _QUEUE_H_
