#pragma once

#include <iostream>
#include "TreeNode.h"

using namespace std;

template <typename O>
//! A class on which a set with adding searching and removing will be based

class MultiTreeSet
{
    friend class MultiTreeSetTester;

public:

    MultiTreeSet() : root(NULL){}

    bool exsistsInTree(O value)
    {
        return exsistsInSubtree(root, value);
    }

    void addToTree(O value)
    {
        return addToSubtree(root, value);
    }

    void removeFromTree(O value)
    {
        removeFromSubTree(root, value);
    }

    virtual void printTree()
    {
        if (!(isEmpty()))
            inorder(root);
    }

    TreeNode<O>* getRoot() const
    {
       return root;
    }

    void intersectTrees (MultiTreeSet<O>* &anotherTreeSet)
    {
        intersectSubTrees(root, anotherTreeSet);
    }

    void sumTrees (MultiTreeSet<O>* &anotherTreeSet)
    {
        printUnique(root, anotherTreeSet);
        printCommonElements(anotherTreeSet);
    }

    ~MultiTreeSet()
    {
        deleteSubTree(root);
    }

protected:

    TreeNode<O>* root;

    bool isEmpty()
    {
        return (root == NULL);
    }

    bool exsistsInSubtree(TreeNode<O> *node, O value);

    void createNode(TreeNode<O>* &node,O value);

    void addToSubtree(TreeNode<O>* &node,O value);

    bool hasLeftChild(TreeNode<O>* &node)
    {
        return (node->left != NULL);
    }

    bool hasRightChild(TreeNode<O>* &node)
    {
        return (node->right != NULL);
    }

    bool hasOneChild(TreeNode<O>* &node)
    {
        return ((hasLeftChild(node)) && !(hasRightChild(node))) || ( !(hasLeftChild(node)) && (hasRightChild(node)) );
    }

    bool isLeaf(TreeNode<O>* &node)
    {
        return (!hasLeftChild(node) && !hasRightChild(node));
    }

    O popMostLeftValue(TreeNode<O>* &node);

    void removeFromSubTree(TreeNode<O>* &node, O value);

    virtual void printNode(TreeNode<O>* &node);

    void inorder(TreeNode<O>* &node);

    void deleteSubTree(TreeNode<O>* &node);

    void intersectSubTrees(TreeNode<O>* &node, MultiTreeSet* anotherTreeSet);

    void printUnique(TreeNode<O>* &node, MultiTreeSet* anotherTreeSet);

    int repsOfElementInSubTree(TreeNode<O>* &node, O value);

    int repsOfElement(O value)
    {
        return repsOfElementInSubTree(root, value);
    }

    void printCommonElements (MultiTreeSet* &anotherTree)
    {
        printWithOthers(root, anotherTree);
    }

    void printWithOthers(TreeNode<O>* &node, MultiTreeSet* &anotherTree);
};

template <typename O>
bool MultiTreeSet<O>::exsistsInSubtree(TreeNode<O> *node, O value)
{
    if (node == NULL)
        return false;
    if (node->value == value)
        return true;
    if (value > node->value)
        return exsistsInSubtree(node->right,value);
    else
        return exsistsInSubtree(node->left,value);
}

template <typename O>
void MultiTreeSet<O>::createNode(TreeNode<O>* &node,O value)
{
    node = new TreeNode<O>;
    node->reps = 1;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
}

template <typename O>
void MultiTreeSet<O>::addToSubtree(TreeNode<O>* &node, O value)
{
    if (node == NULL)
        return createNode(node,value);
    else if (node->value == value)
    {
        node->reps++;
        return;
    }
    else if (value > node->value)
        return addToSubtree(node->right,value);
    else
        return addToSubtree(node->left,value);
}

template <typename O>
O MultiTreeSet<O>::popMostLeftValue(TreeNode<O>* &node)
{
    O tmp = 0;
    if (node->left != NULL)
        return popMostLeftValue(node->left);
    else
    {
        tmp = node->value;
        delete node;
        node = NULL;
        return tmp ;
    }
}

template <typename O>
void MultiTreeSet<O>::removeFromSubTree(TreeNode<O>* &node,O value)
{
    if (node == NULL)
        cout << "No such an element.";
    else if (node->value == value)
    {
        if (node->reps == 1)
        {
            if ((isLeaf(node))||(hasOneChild(node)))
            {
                if (isLeaf(node))
                {
                    delete node;
                    node = NULL;
                    return;
                }
                if (hasOneChild(node))
                {
                    if(hasLeftChild(node))
                    {
                        TreeNode<O>* tmp = node->left;
                        delete node;
                        node = tmp;
                    }
                    else
                    {
                        TreeNode<O>* tmp = node->right;
                        delete node;
                        node = tmp;
                    }
                }
            }
            else
            {
                O tmp = popMostLeftValue(node->right);
                node->value = tmp;
            }
        }
        else
        {
            node->reps--;

        }
    }
    else if (value > node->value)
        return removeFromSubTree(node->right,value);
    else
        return removeFromSubTree(node->left,value);
}

template <typename O>
void MultiTreeSet<O>::printNode(TreeNode<O>* &node)
{
    cout << node->value << "(" << node->reps << ")" << endl;
}

template <typename O>
void MultiTreeSet<O>::inorder(TreeNode<O>* &node)
{
    if (node->left != NULL)
    {
        inorder(node->left);
        printNode(node);
        if (node->right != NULL)
            inorder(node->right);
    }
    else
    {
        printNode(node);
        if (node->right != NULL)
            inorder(node->right);
    }
    return;
}

template <typename O>
void MultiTreeSet<O>::deleteSubTree(TreeNode<O>* &node)
{
    if (node == NULL)
        return;
    else
    {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

template <typename O>
void MultiTreeSet<O>::intersectSubTrees(TreeNode<O>* &node, MultiTreeSet* anotherTreeSet)
{
    if (node == NULL)
        return;
    else
    {
        int anotherReps = anotherTreeSet->repsOfElement(node->value);
        if (anotherReps != 0)
        {
            int min = anotherReps;
            if (node->reps < min)
                min = node->reps;
            cout << node->value << "(" << min << ")" << endl;
        }
        intersectSubTrees(node->left, anotherTreeSet);
        intersectSubTrees(node->right, anotherTreeSet);
    }
}

template <typename O>
void MultiTreeSet<O>::printUnique(TreeNode<O>* &node, MultiTreeSet* anotherTreeSet)
{
    if (node != NULL)
    {
        if (!(anotherTreeSet->exsistsInTree(node->value)))
        {
            cout << node->value << "(" << node->reps << ")" << endl;
        }
        printUnique(node->left, anotherTreeSet);
        printUnique(node->right, anotherTreeSet);
    }
    else
        return;
}

template <typename O>
int MultiTreeSet<O>::repsOfElementInSubTree(TreeNode<O>* &node, O value)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        if (node->value == value)
        {
            return node->reps;
        }
        else if (node->value < value)
        {
            return repsOfElementInSubTree(node->right, value);
        }
        else
        {
            return repsOfElementInSubTree(node->left, value);
        }
    }
}

template <typename O>
void MultiTreeSet<O>::printWithOthers (TreeNode<O> *&node, MultiTreeSet<O> *&anotherTreeSet)
{
    if (node == NULL)
        return;
    else
    {
        int anotherReps = anotherTreeSet->repsOfElement(node->value);
        if (anotherReps != 0)
           cout << node->value << "(" << anotherReps + node->reps << ")" << endl;
        printWithOthers(node->left, anotherTreeSet);
        printWithOthers(node->right, anotherTreeSet);
    }
}
