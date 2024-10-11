#include "tree_util.h"
#include "string_node.h"
#include "int_node.h"
#include <iostream>

std::string GetValue(const Node* node) {
    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
        return std::to_string(intNode->value());
    }
    if (const StringNode* stringNode = dynamic_cast<const StringNode*>(node)) {
        return stringNode->value();
    }
    return "";
}
TreeUtil* TreeUtil::instance_ = nullptr;
TreeUtil* TreeUtil::GetInstance() {
    return instance_;
}
const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
    if (node == nullptr) {
        return "";
    }
    std::string res = GetValue(node);
    std::string left = PreOrderTraversal(node->left());
    if (left != "") {
        res = res + "," + left;
    }
    std::string right = PreOrderTraversal(node->right());
    if (right != "") {
        res = res + "," + right;
    }
    return res;
}
const std::string TreeUtil::InOrderTraversal(const Node* node) const {
    if (node == nullptr) {
        return "";
    }
    std::string res = "";
    std::string left = InOrderTraversal(node->left());
    if (left != "") {
        res = left;
    }
    std::string root = GetValue(node);
    if (res != "") {
        res = res + "," + root;
    } else {
        res = root;
    }
    std::string right = InOrderTraversal(node->right());
    if (right != "") {
        res = res + "," + right;
    }
    return res;
}
const std::string TreeUtil::PostOrderTraversal(const Node* node) const {
    if (node == nullptr) {
        return "";
    }
    std::string res = "";
    std::string left = PostOrderTraversal(node->left());
    if (left != "") {
        res = left;
    }
    std::string right = PostOrderTraversal(node->right());
    if (res != "") {
        if (right != "") {
            res = res + "," + right;
        }
    } else {
        res = right;
    }
    std::string root = GetValue(node);
    if (res != "") {
        res = res + "," + root;
    } else {
        res = root;
    }
    return res;
}
