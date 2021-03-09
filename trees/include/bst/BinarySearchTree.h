//
// Created by ojcch on 2/3/2020.
//

#ifndef TREES_BINARYSEARCHTREE_H
#define TREES_BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <string>

using namespace std;

/*
 * A class that represents a Binary Search Tree (BST).
 */
template<class Object>
class BinarySearchTree {

public:

    /*
     * Creates a empty BST
     */
    explicit BinarySearchTree();

    /*
     * Creates a BST with key as root
     */
    explicit BinarySearchTree(Object key);

    /*
     * Destroys the BST from memory
     */
    virtual ~BinarySearchTree();

    //--------------------------------------------------------------------

    /*
     * Finds key in the current BST
     */
    TreeNode<Object> *find(Object key);

    /*
     * Inserts key in the current BST
     */
    void insert(Object key);

    /*
     * Deletes key from the current BST
     */
    void  remove(Object key);

    /*
     * Finds the smallest element in the current BST
     */
    TreeNode<Object> * findMin();

    /*
     * Finds largest in the current BST
     */
    TreeNode<Object> * findMax();

    /*
     * Prints the current BST in the terminal
     */
    void printTree();

    //--------------------------------------------------------------------

    /*
     * Finds key in current BST and it splays it if found
     */
    TreeNode<Object> *findWithSplaying(Object key);

    /*
     * Inserts and splays key in current BST. It splays key after the insertion
     */
    void insertWithSplaying(Object key);

    /*
     * Deletes key from current BST with splaying.
     */
    void removeWithSplaying(Object key);

    /*
     * Finds the smallest element in the current BST and splays it
     */
    TreeNode<Object> * findMinWithSplaying();

    /*
     * Finds largest in the current BST
     */
    TreeNode<Object> * findMaxWithSplaying();

    //--------------------------------------------------------------------

private:

    //the root of the current BST
    TreeNode<Object> *root;

    /*
     * Finds key in the BST pointed by node
     */
    TreeNode<Object> *find(TreeNode<Object> *node, Object key);

    /*
     * Inserts key in the BST pointed by node
     */
    TreeNode<Object>* insert(TreeNode<Object> *node, Object key);

    /*
     * Finds the smallest element in the BST pointed by node
     */
    TreeNode<Object> * findMin(TreeNode<Object> *node);

    /*
     * Finds the largest element in the BST pointed by node
     */
    TreeNode<Object> * findMax(TreeNode<Object> *node);

    /*
     * Deletes key from the BST pointed by node
     */
    TreeNode<Object> * remove(TreeNode<Object> *node, Object key);

    /*
     * Prints the BST pointed by node in the terminal.
     * It receives a prefix that is used to label the current node.
     * It receives a tree level that is used for indentation.
     * It prints the left and right children, respectively, with the following prefixes: Lf: and Rg:
     */
    void printTree(TreeNode<Object> *node, string prefix, int level);

    /*
     * Splays key to the root of the BST pointed by node
     */
    TreeNode<Object> * splay(TreeNode<Object> *node, Object key);

};

#endif //TREES_BINARYSEARCHTREE_H
