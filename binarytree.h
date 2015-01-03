#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

class BinaryTree
{
private:

    class TreeNode {
    public:
        TreeNode * left;
        TreeNode * right;
        int data;

        TreeNode();
        TreeNode(int data);
        TreeNode(const TreeNode & obj);
        TreeNode(TreeNode && other);
        ~TreeNode();

        TreeNode & operator = (const TreeNode & obj);
        TreeNode & operator = (TreeNode && other);

        void push(int data);
    } * root;

    void clear(TreeNode *& root);
    void copy(TreeNode *& copiedNode, TreeNode * otherNode);

    /** Detects rightmost node*/
    TreeNode * rightMost(TreeNode * node);
    void inorder(TreeNode * node, TreeNode * rightMost, std::ostream & out);

public:
    BinaryTree();
    BinaryTree(const BinaryTree & obj);
    BinaryTree(BinaryTree && other);
    ~BinaryTree();

    BinaryTree & operator = (const BinaryTree & obj);
    BinaryTree & operator = (BinaryTree && other);

    void push(int data);
    void remove(int data);
    bool isEmpty() const;

    friend std::ostream & operator << (std::ostream & out, BinaryTree & obj);
    friend std::istream & operator >> (std::istream & in, BinaryTree & obj);
};

#endif // BINARYTREE_H
