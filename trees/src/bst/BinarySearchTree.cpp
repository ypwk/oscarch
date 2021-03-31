//
// Created by ojcch on 2/3/2020.
//

#include "bst/BinarySearchTree.h"
#include <iostream>
#include <vector>

template<class Object>
BinarySearchTree<Object>::BinarySearchTree() {
    this->root = nullptr;
}

template<class Object>
BinarySearchTree<Object>::BinarySearchTree(Object element) {
    root = new TreeNode<Object>(element);
}

template<class Object>
BinarySearchTree<Object>::~BinarySearchTree() {
    delete this->root;
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::find(Object element) {
    return find(this->root, element);
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::find(TreeNode<Object> *node, Object key) {
    if (node == nullptr) //nothing to do here
        return nullptr;
    else if (node->element == key) //element found!
        return node;
    else if (node->element < key) //the key might be in the right subtree
        return find(node->right, key);
    else //the key might be in the left subtree
        return find(node->left, key);
}

template<class Object>
void BinarySearchTree<Object>::insert(Object element) {
    this->root = this->insert(root, element);
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::insert(TreeNode<Object> *node, Object key) {
    if (node == nullptr)
        return new TreeNode<Object>(key); //create and return the node
    else if (node->element < key) //the insertion should be done in the right subtree
        node->right = insert(node->right, key);
    else if (node->element > key) //the insertion should be done in the left subtree
        node->left = insert(node->left, key);

    return node;
}

template<class Object>
void BinarySearchTree<Object>::printTree() {
    printTree(this->root, "R:", 0); //print the tree starting from the node
}

template<class Object>
void BinarySearchTree<Object>::printTree(TreeNode<Object> *node, string prefix, int level) {

    if (node == nullptr) return;//nothing to do here

    //indentation string
    string levelStr;
    for (int i = 0; i < level; ++i) {
        levelStr.append("  ");
    }

    //print the node
    cout << levelStr << prefix << node->element << endl;

    //print the children
    printTree(node->left, "Lf:", level + 1);
    printTree(node->right, "Rg:", level + 1);

}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMin() {
    return findMin(this->root);
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMax() {
    return findMax(this->root);
}


template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMin(TreeNode<Object> *node) {
    if (node == nullptr) return nullptr; //nothing to do here
    if (node->left == nullptr) return node; //the smallest node was found!
    return findMin(node->left); //keep looking for the smallest node
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMax(TreeNode<Object> *node) {
    if (node == nullptr) return nullptr; //nothing to do here
    if (node->right == nullptr) return node;//the largest node was found!
    return findMax(node->right); //keep looking for the largest node
}

template<class Object>
void BinarySearchTree<Object>::remove(Object element) {
    this->root = this->remove(this->root, element);
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::remove(TreeNode<Object> *node, Object key) {
    //nothing to do here
    if (node == nullptr) return nullptr;

    //if node < key --> the key is in the right subtree, remove it recursively
    if (node->element < key)
        node->right = remove(node->right, key);

        //if node > key --> the key is in the left subtree, remove it recursively
    else if (node->element > key)
        node->left = remove(node->left, key);

        //if node == key then remove it
    else {
        //temporal variable
        TreeNode<Object> *temp = nullptr;

        //case when the node has two children:
        //replace the node with the smallest element in its right subtree and then remove it recursively
        if (node->left != nullptr && node->right != nullptr) {
            temp = findMin(node->right);
            node->element = temp->element;
            node->right = remove(node->right, temp->element);
        } else {
            //if no left child, then node should be the right child, otherwise, it should be left one
            if (node->left == nullptr) {
                temp = node->right;
                node->right = nullptr;
            } else {
                temp = node->left;
                node->left = nullptr;
            }
            delete (node); //free up memory
            node = temp;
        }
    }
    return node;
}

//-----------------------------------------------


template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findWithSplaying(Object key) {
    TreeNode<Object> *splayedNode = splay(this->root, key);
    if(splayedNode != nullptr) this->root = splayedNode;
    return splayedNode;
}


template<class Object>
TreeNode<Object> *performSplaying(vector<TreeNode<Object> *> &visitedNodes) {

    //double check that there is a path
    if (visitedNodes.empty()) return nullptr;

    //the last element is the node we want to splay
    TreeNode<Object> *nodeToSplay = visitedNodes[visitedNodes.size() - 1];

    for (int i = visitedNodes.size() - 1; i > 0;) {

        // identify the grandparent and the parent of the node
        TreeNode<Object> *grandParent = i > 1 ? visitedNodes[i - 2] : nullptr;
        TreeNode<Object> *parent = visitedNodes[i - 1];

        //directions taken to navigate down from the parent and grandparent: (1: right, -1: left)
        //0 means, the node does have a grandparent
        const short toGrandParent = grandParent != nullptr ? (grandParent->element < nodeToSplay->element ? 1 : -1) : 0;
        const short toParent = parent->element < nodeToSplay->element ? 1 : -1;

        if (toGrandParent == 0) { // no grandparent --> single zig
            if (toParent == 1) { //zig left
                TreeNode<Object> *bNode = nodeToSplay->left;
                nodeToSplay->left = parent;
                parent->right = bNode;
            } else { //zig right
                TreeNode<Object> *bNode = nodeToSplay->right;
                nodeToSplay->right = parent;
                parent->left = bNode;
            }

            i--;
        } else { //we have parent and grandparent, then we do double rotations
            if (toParent == 1 && toGrandParent == -1) { //we need to do zig left and zig right

                TreeNode<Object> *leftSubtree = nodeToSplay->left;
                TreeNode<Object> *rightSubtree = nodeToSplay->right;

                nodeToSplay->right = grandParent;
                nodeToSplay->left = parent;

                parent->right = leftSubtree;
                grandParent->left = rightSubtree;

            } else if (toParent == 1 && toGrandParent == 1) {//we need to do zig left and zig left

                TreeNode<Object> *leftSubtree = nodeToSplay->left;
                nodeToSplay->left = parent;

                TreeNode<Object> *parentLeftSubtree = parent->left;
                parent->right = leftSubtree;
                parent->left = grandParent;

                grandParent->right = parentLeftSubtree;

            } else if (toParent == -1 && toGrandParent == -1) {//we need to do zig right and zig right

                TreeNode<Object> *rightSubtree = nodeToSplay->right;
                nodeToSplay->right = parent;

                TreeNode<Object> *parentRightSubtree = parent->right;
                parent->right = grandParent;
                parent->left = rightSubtree;

                grandParent->left = parentRightSubtree;

            } else if (toParent == -1 && toGrandParent == 1) {//we need to do zig right and zig left

                TreeNode<Object> *leftSubtree = nodeToSplay->left;
                TreeNode<Object> *rightSubtree = nodeToSplay->right;

                nodeToSplay->right = parent;
                nodeToSplay->left = grandParent;

                parent->left = rightSubtree;
                grandParent->right = leftSubtree;
            }
            i = i - 2;
        }

    }
    return nodeToSplay;
}

//O(n) worst-case runtime complexity
//O(log n) amortized worst-case runtime complexity
template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::splay(TreeNode<Object> *node, Object key) {

    TreeNode<Object> *currentNode = node;

    //visited nodes
    std::vector<TreeNode<Object> *> visitedNodes;

    //find the key and track the visited nodes
    bool keyIsFound = false;
    while (!keyIsFound) {

        if (currentNode == nullptr) //key is definitely not found
            break;

        visitedNodes.push_back(currentNode); //visiting this node

        if (currentNode->element == key) { //the key is found!
            keyIsFound = true;
        } else { //otherwise, keep looking for the key

            if (currentNode->element < key) {    //it might be in the right subtree
                currentNode = currentNode->right;
            } else { //it might be in the left subtree
                currentNode = currentNode->left;
            }

        }

    }

    //------------------------------

    if (!keyIsFound) return nullptr; //it was not found!

    //------------------------

    return performSplaying(visitedNodes);
}

//O(n) worst-case runtime complexity
//O(log n) amortized worst-case runtime complexity
template<class Object>
void BinarySearchTree<Object>::insertWithSplaying(Object element) {
    this->root = this->insert(this->root, element); //insert
    this->root = this->splay(this->root, element); //then splay
}

//O(n) worst-case runtime complexity
//O(log n) amortized worst-case runtime complexity
template<class Object>
void BinarySearchTree<Object>::removeWithSplaying(Object element) {

    //splay the element
    TreeNode<Object> *splayedNode = this->splay(this->root, element);
    if (splayedNode == nullptr) return; //not found (nothing to do)

    //make it the root
    this->root = splayedNode;

    //find max in left subtree
    TreeNode<Object> *maxInLeftSubtree = this->findMax(this->root->left);

    //if found
    if (maxInLeftSubtree != nullptr) {
        //splay the max as the root of the left subtree
        this->root->left = this->splay(this->root->left, maxInLeftSubtree->element);
        //make the right subtree of the max element the right subtree of the root
        maxInLeftSubtree->right = this->root->right;
    }

    //delete the root of the tree.
    //I need to make the children null first before destroying the root.
    //Otherwise, the C++ delete will destroy all the nodes of this tree recursively.
    this->root->left = nullptr;
    this->root->right = nullptr;
    delete this->root;

    //this is the new root
    this->root = maxInLeftSubtree;
}

//O(n) worst-case runtime complexity
//O(log n) amortized worst-case runtime complexity
template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMaxWithSplaying() {

    TreeNode<Object> *currentNode = this->root;

    //visited nodes
    std::vector<TreeNode<Object> *> visitedNodes;

    //traverse the right subtrees until finding the leaf
    while (currentNode != nullptr) {
        visitedNodes.push_back(currentNode); //visiting this node
        currentNode = currentNode->right; //going to the right child
    }

    //splay the max element
    this->root = performSplaying(visitedNodes);
    return this->root;
}

//O(n) worst-case runtime complexity
//O(log n) amortized worst-case runtime complexity
template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMinWithSplaying() {

    TreeNode<Object> *currentNode = this->root;

    //visited nodes
    std::vector<TreeNode<Object> *> visitedNodes;

    //traverse the left subtrees until finding the leaf
    while (currentNode != nullptr) {
        visitedNodes.push_back(currentNode); //visiting this node
        currentNode = currentNode->left; //going to the left
    }

    //splay the min element
    this->root = performSplaying(visitedNodes);
    return this->root;
}


//Declarations of BSTs that store ints, chars, strings, floats and doubles.
//These need to be declared here, otherwise, there would be linker errors.
template class BinarySearchTree<int>;
template class BinarySearchTree<char>;
template class BinarySearchTree<string>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;