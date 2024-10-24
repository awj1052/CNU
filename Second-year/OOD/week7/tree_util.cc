#include "tree_util.h"
#include "string_node.h"
#include "int_node.h"
#include <iostream>

TreeUtil* TreeUtil::instance_ = nullptr;
TreeUtil* TreeUtil::GetInstance() {
    return instance_;
}
const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
    if (node == nullptr) {
        return "";
    }
    std::string res = node->value();
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
    std::string root = node->value();
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
    std::string root = node->value();
    if (res != "") {
        res = res + "," + root;
    } else {
        res = root;
    }
    return res;
}
