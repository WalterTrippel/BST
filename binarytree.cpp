#include "binarytree.h"

BinaryTree::TreeNode::TreeNode():left(nullptr), right(nullptr), data(0)
{
}

BinaryTree::TreeNode::TreeNode(int data):left(nullptr), right(nullptr), data(data)
{
}

BinaryTree::TreeNode::TreeNode(const BinaryTree::TreeNode & obj):left(obj.left), right(obj.right), data(obj.data)
{
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

BinaryTree::BinaryTree(std::initializer_list<int> list):root(nullptr)
{
    for(unsigned i = 0; i < list.size(); ++i)
    {
        this->push(*(list.begin() + i));
    }
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
    //???
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

void BinaryTree::remove(int data)
{
    bool found = false;
    if(isEmpty())
    {
        return;
    }
    TreeNode * curr;
    TreeNode * parent;
    curr = root;

    while(curr != nullptr)
    {
        if(curr->data == data)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
    }
    if(!found)
    {
        throw BSTException();
    }

    if((curr->left == nullptr && curr->right != nullptr) || (curr->left != nullptr && curr->right == nullptr))
    {
        if(curr->left == nullptr && curr->right != nullptr)
        {
            if(parent->left == curr)
            {
                parent->left = curr->right;
            }
            else
            {
                parent->right = curr->right;
            }
        }
        else
        {
            if(parent->left == curr)
            {
                parent->left = curr->left;
            }
            else
            {
                parent->right = curr->left;
            }
        }
        delete curr;
        return;
    }

    if(curr->left == nullptr && curr->right == nullptr)
    {
        if(parent->left == curr)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete curr;
        return;
    }

    if(curr->left != nullptr && curr->right != nullptr)
    {
        TreeNode * ncurr;
        ncurr = curr->right;
        if((ncurr->left == nullptr) && (ncurr->right == nullptr))
        {
            curr = ncurr;
            delete ncurr;
            curr->right = nullptr;
        }
        else
        {
            if((curr->right)->left != nullptr)
            {
                TreeNode * lcurr;
                TreeNode * lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != nullptr)
                {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = nullptr;
            }
            else
            {
                TreeNode * tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->right = tmp->right;
                delete tmp;
            }
        }
        return;
    }
}

BinaryTree::TreeNode * BinaryTree::findMin(TreeNode *node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(node->left == nullptr)
    {
        return node;
    }
    return findMin(node->left);
}

BinaryTree & BinaryTree::operator = (const BinaryTree &obj)
{
    copy(this->root, obj.root);
    return * this;
}

/** As said have no idea how it should be organized*/
BinaryTree & BinaryTree::operator = (BinaryTree && other)
{
 //???
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


