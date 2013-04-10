#pragma once

class TreeNode
{
public:
    virtual void printNode() = 0;
    //! Make operation set by sign with left and right subtrees
    virtual int calculateNode() = 0;
    //! @return The sign character or the int value of the node depending on the type of the node
    virtual char getValue() = 0;
    //! @return Pointer to the left subtree
    TreeNode *&getLeft();
    //! @return Pointer to the left subtree
    TreeNode *&getRight();
protected:
    TreeNode* left;
    TreeNode* right;
};


