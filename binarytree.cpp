#include "binarytree.h"

BinaryTree::TreeNode::TreeNode():left(nullptr), right(nullptr), data(0)
{
}

BinaryTree::TreeNode::TreeNode(int data):left(nullptr), right(nullptr), data(data)
{

}

BinaryTree::TreeNode::TreeNode(const BinaryTree::TreeNode & obj)
{
    this->left = obj.left;
    this->right = obj.right;
    this->data = obj.data;
}

BinaryTree::TreeNode::TreeNode(TreeNode &&other):left(nullptr), right(nullptr), data(0)
{
    this->left = other.left;
    this->right = other.right;
    this->data = other.data;

    other.left = nullptr;
    other.right = nullptr;
    other.data = 0;
}

BinaryTree::TreeNode::~TreeNode()
{
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
}

void BinaryTree::TreeNode::push(int data)
{
    if(data < this->data)
    {
        if(left == nullptr)
        {
            left = new TreeNode(data);
        }
        else
        {
            left->push(data);
        }
    }
    else if(data >= this->data)
    {
        if(right == nullptr)
        {
            right = new TreeNode(data);
        }
        else
        {
            right->push(data);
        }
    }
}

/**
    BST methods initialization
*/

BinaryTree::BinaryTree():root(nullptr)
{
}

BinaryTree::BinaryTree(const BinaryTree &obj)
{
    copy(this->root, obj.root);
}

/**
    Don't understand though the use of move semantics and how it should be organized
*/
BinaryTree::BinaryTree(BinaryTree &&other):root(nullptr)
{
    copy(this->root, other.root);

}

BinaryTree::~BinaryTree()
{
    clear(this->root);
}

void BinaryTree::copy(TreeNode *&copiedNode, TreeNode *otherNode)
{
    if(otherNode == nullptr)
    {
        copiedNode = otherNode;
    }
    else
    {
        copiedNode = new TreeNode(otherNode->data);
        copy(copiedNode->left, otherNode->left);
        copy(copiedNode->right, otherNode->right);
    }
}

void BinaryTree::clear(TreeNode *&root)
{
    if(root != nullptr)
    {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

void BinaryTree::push(int data)
{
    if(root == nullptr)
    {
        root = new TreeNode(data);
    }
    else
    {
        root->push(data);
    }
}

BinaryTree::TreeNode * BinaryTree::rightMost(TreeNode *node)
{
    if(node != nullptr && node->right != nullptr)
    {
        return rightMost(node->right);
    }
    return node;
}

void BinaryTree::inorder(TreeNode *node, TreeNode *rightMost, std::ostream & out)
{
    if(node == nullptr)
    {
        return;
    }
    if(node->left)
    {
        inorder(node->left, rightMost, out);
    }
    out << node->data;
    if(node != rightMost)
    {
        out << ", ";
    }
    if(node->right)
    {
        inorder(node->right, rightMost, out);
    }
}

bool BinaryTree::isEmpty() const
{
    return this->root == nullptr ? true : false;
}

std::ostream & operator << (std::ostream & out, BinaryTree & obj)
{
    BinaryTree::TreeNode * node = obj.rightMost(obj.root);
    obj.inorder(obj.root, node, out);
    return out;
}



std::istream & operator >> (std::istream & in, BinaryTree & obj)
{
    int data;
    in >> data;
    obj.push(data);
    return in;
}


