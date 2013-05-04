#pragma once
#include <iostream>
#include "SortedList.h"
#include "TreeSet.h"

using namespace std;

template <typename O>

class MultiTreeSet : public TreeSet<O>
{
    friend class MultiTreeSetTester;


public:

    struct TreeNode
    {
        O value;
        TreeNode* left;
        TreeNode* right;
    };
    void addToMultiTree(O value);

    void removeFromMultiTree(O value);

    void printTree();

    ~MultiTreeSet()
    {
        sList.~SortedList();
    }

private:

    SortedList<O> sList;
};


template <typename O>
void MultiTreeSet<O>::addToMultiTree(O value)
{
    addToTree(value);
    sList.add(value);
}

template <typename O>
void MultiTreeSet<O>::removeFromMultiTree(O value)
{
    if (sList.repsOfElement(value) == 1)
           removeFromTree(value);
    sList.remove(value);
}

template  <typename O>
void MultiTreeSet<O>::printTree()
{
    sList.printList();
}
