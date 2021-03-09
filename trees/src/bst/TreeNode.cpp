//
// Created by ojcch on 2/3/2020.
//

#include "bst/TreeNode.h"
#include <string>

using namespace std;

template<class Object>
TreeNode<Object>::TreeNode(Object element) {
    this->element = element;
}

template<class Object>
TreeNode<Object>::~TreeNode() {
    //the destructor destroys the node recursively, by destroying its children
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
    left = nullptr;
    right = nullptr;
}

//Declarations of different types of nodes.
//These need to be declared here, otherwise, there would be linker errors.
template class TreeNode<int>;
template class TreeNode<char>;
template class TreeNode<string>;
template class TreeNode<float>;
template class TreeNode<double>;
