#include "list.h"

void List::FreeAll(List::Elem* cur) {
    if (cur == nullptr) {
        return;
    }
    FreeAll(cur->next);
    delete cur;
}
List::Elem* List::GetNode(int index) {
    assert((index >= 0 && index < size_) && "Out-of-bound");
    List::Elem* res = head;
    for (int i = 0; i < index; i++) {
        res = res->next;
    }
    return res;
}
List::Elem* List::CopyAll(List::Elem* cur) {
    if (cur == nullptr) {
        return nullptr;
    }
    List::Elem* copied = new List::Elem;
    copied->value = cur->value;
    copied->next = CopyAll(cur->next);
    return copied;
}
List::List() : head(nullptr), size_(0) {}
List::List(List& list) : size_(list.size_) {
    head = CopyAll(list.head);
}
List::~List() {
    FreeAll(head);
}
void List::operator=(List& list) {
    FreeAll(head);
    head = CopyAll(list.head);
    size_ = list.size_;
}
int List::size() const {
    return size_;
}
void List::PushBack(int elem) {
    Elem* node = new Elem;
    node->value = elem;
    node->next = nullptr;
    if (size_ == 0) {
        head = node;
    } else {
        GetNode(size_ - 1)->next = node;
    }
    size_++;
}
void List::PushFront(int elem) {
    Elem* node = new Elem;
    node->value = elem;
    node->next = head;
    head = node;
    size_++;
}
void List::PopBack() {
    assert(size_ > 0 && "Out-of-bound");
    if (size_ == 1) {
        head = nullptr;
        size_ = 0;
        return;
    }
    Elem* secondary = GetNode(size_ - 2);
    size_--;
    delete secondary->next;
    secondary->next = nullptr;
}
void List::PopFront() {
    assert(size_ > 0 && "Out-of-bound");
    if (size_ == 1) {
        delete head;
        head = nullptr;
        size_ = 0;
        return;
    }
    Elem* first = head;
    head = head->next;
    size_--;
    delete first;
}
int& List::At(int index) {
    return GetNode(index)->value;
}
bool List::IsEmpty() const {
    return size_ == 0;
}
