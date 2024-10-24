#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"
#include <iostream>

int main() {
    IntNode* a = new IntNode(1, NULL, NULL);
    IntNode* b = new IntNode(2, a, NULL);
    IntNode* c = new IntNode(3, NULL, NULL);
    IntNode* d = new IntNode(4, b, c);
    TreeUtil* tree_util = TreeUtil::GetInstance();
    std::cout << a->value() << "\n";
    std::cout << tree_util->PreOrderTraversal(d) << "\n";
    std::cout << tree_util->InOrderTraversal(d) << "\n";
    std::cout << tree_util->PostOrderTraversal(d) << "\n";
    delete d;
    return 0;
}
