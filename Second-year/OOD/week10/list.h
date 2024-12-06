#ifndef _LIST_H_
#define _LIST_H_

#include <assert.h>

template <typename T>
class List {
 public:
    List() : head(nullptr), size_(0) {}
    List(const List& list) : size_(list.size_) {
        head = CopyAll(list.head);
    }
    virtual ~List() {
        FreeAll(head);
    }
    void operator=(const List& list) {
        FreeAll(head);
        head = CopyAll(list.head);
        size_ = list.size_;
    }
    int size() const {
        return size_;
    }
    void PushBack(T elem) {
        Elem* node = new Elem;
        node->value = elem;
        node->next = nullptr;
        if (size_ == 0) {
            head = node;
        } else {
            GetElem(size_ - 1)->next = node;
        }
        size_++;
    }
    void PushFront(T elem) {
        Elem* node = new Elem;
        node->value = elem;
        node->next = head;
        head = node;
        size_++;
    }
    void PopBack() {
        assert(size_ > 0 && "Out-of-bound");
        if (size_ == 1) {
            head = nullptr;
            size_ = 0;
            return;
        }
        Elem* secondary = GetElem(size_ - 2);
        size_--;
        delete secondary->next;
        secondary->next = nullptr;
    }
    void PopFront() {
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
    T& At(int index) {
        return GetElem(index)->value;
    }
    bool IsEmpty() const {
        return size_ == 0;
    }

 private:
    struct Elem {
        T value;
        Elem* next;
    };
    void FreeAll(Elem* cur) {
        if (cur == nullptr) {
            return;
        }
        FreeAll(cur->next);
        delete cur;
    }
    Elem* GetElem(int index) {
        assert((index >= 0 && index < size_) && "Out-of-bound");
        Elem* res = head;
        for (int i = 0; i < index; i++) {
            res = res->next;
        }
        return res;
    }
    Elem* CopyAll(Elem* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        Elem* copied = new Elem;
        copied->value = cur->value;
        copied->next = CopyAll(cur->next);
        return copied;
    }
    Elem* head;
    int size_;
};

#endif   // _LIST_H_
