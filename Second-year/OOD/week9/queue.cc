#include "queue.h"

Queue::Queue() : List() {}
Queue::Queue(Queue& queue) : List(queue) {}
void Queue::operator=(Queue& queue) {
    (*this) = queue;
}
int Queue::size() const {
    return List::size();
}
void Queue::Add(int elem) {
    List::PushBack(elem);
}
int Queue::Poll() {
    int poll = List::At(0);
    List::PopFront();
    return poll;
}
bool Queue::IsEmpty() const {
    return List::IsEmpty();
}
