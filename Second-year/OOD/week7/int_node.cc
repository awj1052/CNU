#include "int_node.h"

IntNode::IntNode(int value, const Node* left, const Node* right) :
    value_(value),
    Node(left, right) {}
const std::string IntNode::value() const {
    return std::to_string(value_);
}
