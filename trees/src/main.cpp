

#include <string>
#include <iostream>
#include "bst/BinarySearchTree.h"

void runBSTTest();

void printTreeNode(string prefix, TreeNode<int> *node);

int main() {

    runBSTTest();

    return 0;
}

void printTreeNode(string prefix, TreeNode<int> *node) {
    if (node != nullptr) {
        cout << prefix << " found: " << node->element << endl;
    } else
        cout << prefix << " not found" << endl;
}

void runBSTTest() {

    auto *tree = new BinarySearchTree<int>();
    tree->insert(10);
    tree->insert(2);
    tree->insert(1);
    tree->insert(6);
    tree->insert(7);
    tree->insert(5);
    tree->insert(11);

    cout << "The tree:" << endl;
    tree->printTree();

    int key = 8;
    cout << "Finding " << key << "..." << endl;
    TreeNode<int> *node = tree->find(key);
    printTreeNode("Node", node);

    cout << "Finding min..." << endl;
    node = tree->findMin();
    printTreeNode("Min", node);

    cout << "Finding max..." << endl;
    node = tree->findMax();
    printTreeNode("Max", node);

    int elem = 2;
    cout << "Removing " << elem << "..." << endl;
    tree->remove(elem);
    tree->printTree();

    node = tree->find(elem);
    cout << "Finding " << elem << "..." << endl;
    printTreeNode("Node", node);

    delete (tree);
}
