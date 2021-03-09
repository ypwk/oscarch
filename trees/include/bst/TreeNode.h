//
// Created by ojcch on 2/3/2020.
//

#ifndef NEXTDATE_TREENODE_H
#define NEXTDATE_TREENODE_H


/*
 * The node of a Binary Search Tree, which contains public members only.
 */
template <class Object>
class TreeNode {
public:
    Object element; //the element stored in the node
    TreeNode* left = nullptr; //the node's left child
    TreeNode* right = nullptr; //the node's right child
    /*
     * Creates a node storing key
     */
    explicit TreeNode(Object key);
    /*
     * Destroys the current node
     */
    virtual ~TreeNode();
};

#endif //NEXTDATE_TREENODE_H
