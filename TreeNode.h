#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
private:
    TreeNode * left;
    TreeNode * right;
    int data;
public:
    TreeNode();
    TreeNode(const TreeNode & obj);
    TreeNode(TreeNode && other);
    ~TreeNode();

    TreeNode & operator = (const TreeNode & obj);
    TreeNode & operator = (TreeNode && other);
};

#endif // TREENODE_H
