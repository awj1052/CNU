#include <iostream>
#include <string>

#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

int main() {
    // Vector* vector = new Vector(5);
    // vector->PushBack(5);
    // vector->PushBack(2);
    // std::cout << (*vector)[0] << " " << (*vector)[1] << "\n";
    Stack stack = Stack(5);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    std::cout << stack.Pop() << " " << stack.Pop() << "\n";
    List lst = List();
    lst.PushBack(2);
    lst.PushFront(1);
    lst.PushBack(3);
    List nlst = List(lst);
    nlst.PushFront(0);
    std::cout << nlst.At(1) << " " << nlst.At(2) << "\n";
    return 1;
}
