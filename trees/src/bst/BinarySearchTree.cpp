//
// Created by ojcch on 2/3/2020.
//

#include "bst/BinarySearchTree.h"
#include <iostream>

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
TreeNode<Object> *BinarySearchTree<Object>::splay(TreeNode<Object> *node, Object key) {
    //TODO: implement this method
    return nullptr;
}


template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findWithSplaying(Object key) {
    //TODO: implement this method
    return nullptr;
}

template<class Object>
void BinarySearchTree<Object>::insertWithSplaying(Object element) {
    //TODO: implement this method
}

template<class Object>
void BinarySearchTree<Object>::removeWithSplaying(Object element) {
    //TODO: implement this method
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMaxWithSplaying() {
    //TODO: implement this method
    return nullptr;
}

template<class Object>
TreeNode<Object> *BinarySearchTree<Object>::findMinWithSplaying() {
    //TODO: implement this method
    return nullptr;
}


//Declarations of BSTs that store ints, chars, strings, floats and doubles.
//These need to be declared here, otherwise, there would be linker errors.
template class BinarySearchTree<int>;
template class BinarySearchTree<char>;
template class BinarySearchTree<string>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;