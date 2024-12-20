#include "queue.h"

Queue::Queue() : List() {}
Queue::Queue(const Queue& queue) : List(queue) {}
void Queue::operator=(const Queue& queue) {
    List::operator=(queue);
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
