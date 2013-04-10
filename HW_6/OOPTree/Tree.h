#pragma once
#include "TreeNode.h"
#include "SymbolMaster.h"
#include "StringValidator.h"

class Tree
{
    friend class TreeTester;
public:
    Tree();
    int calculateStringByTree(char *string);
    void printTree() const;
    ~Tree();
protected:
    TreeNode* root;
    //! An object for working with symbol types(defining whether a character is a number or not)
    SymbolMaster symbolMaster;
    //! An object which checks whether the given string is correct and remove all unneeded signs
    StringValidator* validator;
    bool isEmpty() const;
    int caclulateTree();
    int formTreeFromPrefixString(TreeNode *&node, int pos, char *string, int last);
};
