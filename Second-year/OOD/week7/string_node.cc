#include "string_node.h"

StringNode::StringNode(std::string value, const Node* left, const Node* right) :
    value_(value),
    Node(left, right) {}
const std::string StringNode::value() const {
    return value_;
}
