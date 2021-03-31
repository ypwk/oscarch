

#include <string>
#include <iostream>
#include "bst/BinarySearchTree.h"

void runBSTTest();

void runSplayingWithNumbers();

void runSplayingWithStrings();

template<class Object>
void printTreeNode(string prefix, TreeNode<Object> *node) {
    if (node != nullptr) {
        cout << prefix << " found: " << node->element << endl;
    } else
        cout << prefix << " not found" << endl;
}


int main() {

    runSplayingWithNumbers();
    runSplayingWithStrings();

    //runBSTTest();

    return 0;
}

void runSplayingWithStrings() {
    auto *tree = new BinarySearchTree<string>();
    string keys[10] = {"a", "l", "g", "o", "r", "i", "t", "h", "m", "s"};
    for (string &key  : keys) {
        cout << "Inserting " << key << ": " << endl;
        tree->insertWithSplaying(key);
        tree->printTree();
        cout << endl;
    }

    cout << "Deleting r: " << endl;
    tree->removeWithSplaying("r");
    tree->printTree();
    cout << endl;

    cout << "Deleting m: " << endl;
    tree->removeWithSplaying("m");
    tree->printTree();
    cout << endl;

    cout << "Finding min: " << endl;
    TreeNode<string> *node = tree->findMinWithSplaying();
    printTreeNode("Node ", node);
    tree->printTree();
    cout << endl;

    cout << "Finding max: " << endl;
    node = tree->findMaxWithSplaying();
    printTreeNode("Node ", node);
    tree->printTree();
    cout << endl;

    delete tree;
}

void runSplayingWithNumbers() {
    auto *tree = new BinarySearchTree<int>();
    int keys[12] = {5, 4, 3, 6, 7, 8, 9, 18, 17, 16, 15, 14};
    for (int &key  : keys) {
        cout << "Inserting " << key << ": " << endl;
        tree->insertWithSplaying(key);
        tree->printTree();
        cout << endl;
    }

    cout << "Deleting 17: " << endl;
    tree->removeWithSplaying(17);
    tree->printTree();
    cout << endl;

    cout << "Finding 45: " << endl;
    TreeNode<int> *node = tree->findWithSplaying(45);
    printTreeNode("Node ", node);
    tree->printTree();
    cout << endl;

    cout << "Finding min: " << endl;
    node = tree->findMinWithSplaying();
    printTreeNode("Node ", node);
    tree->printTree();
    cout << endl;

    cout << "Finding max: " << endl;
    node = tree->findMaxWithSplaying();
    printTreeNode("Node ", node);
    tree->printTree();
    cout << endl;

    delete tree;

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
