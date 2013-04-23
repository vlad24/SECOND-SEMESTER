#pragma once
#include <iostream>
using namespace std;
#include "TreeSet.h"

template <typename O>

class MultiTreeSet : public TreeSet
{
    friend class MultiTreeSetTester;

    struct TreeNode
    {
        O value;
        int reps;
        TreeNode* left;
        TreeNode* right;
    };

public:
    void addToMultiTree(O value);
protected:
    void printNode(TreeNode *&node);
    void increaseReps(O value);
    void increaseRepsInSubTree(TreeNode* node, O value);
};

template <typename O>
void MultiTreeSet<O>::increaseRepsInSubTree(TreeNode* node, O value)
{
    if (node != NULL)
    {
        if (node->value == value)
        {
            node->reps++;
            return;
        }
        else if (node->value > value)
            increaseRepsInSubTree(node->left, value);
        else if (node->value < value)
            increaseRepsInSubTree(node->right, value);

    }
    else
        return;
}

template <typename O>
void MultiTreeSet<O>::increaseReps(O value)
{
    increaseRepsInSubTree(this->root, value);
}

template <typename O>
void MultiTreeSet<O>::addToMultiTree(O value)
{
    this->addToTree(value);
    increaseReps(value);
}

template <typename O>
void MultiTreeSet<O>::printNode(TreeNode* &node)
{
    cout << node->value << "(" << node->reps << ")" << endl;
}
