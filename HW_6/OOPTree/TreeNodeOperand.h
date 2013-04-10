#pragma once
#include "TreeNode.h"
#include "Tree.h"

//! A class specified for nodes which contain operands to make calculating faster

class TreeNodeOperand : public TreeNode
{
public:
    TreeNodeOperand(char newOperand);
    void printNode();
    int calculateNode();
    char getValue();
private:
    char operand;
};

