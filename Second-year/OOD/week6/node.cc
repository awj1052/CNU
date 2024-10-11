#include "node.h"

Node::Node(const Node* left, const Node* right) : left_(left), right_(right) {}
const Node* Node::left() const {
    return left_;
}
const Node* Node::right() const {
    return right_;
}
Node::~Node() {
    delete left_;
    delete right_;
}
