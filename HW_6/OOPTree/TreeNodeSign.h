#pragma once
#include "TreeNode.h"

//! A class specified for nodes which contain signs to make calculating faster

class TreeNodeSign : public TreeNode
{
public:
    TreeNodeSign(char newSign);
    void printNode();
    int calculateNode();
    char getValue();
private:
    char sign;
};

