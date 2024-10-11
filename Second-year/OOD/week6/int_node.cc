#include "int_node.h"

IntNode::IntNode(int value, const Node* left, const Node* right) :
    value_(value),
    Node(left, right) {}
const int IntNode::value() const {
    return value_;
}
