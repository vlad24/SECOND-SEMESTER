#pragma once

#include <iostream>
using namespace std;

template <typename O>
//! A class on which a set with adding searching and removing will be based

class TreeSet
{
    friend class MultiTreeSetTester;

public:
    struct TreeNode
    {
        O value;
        TreeNode* left;
        TreeNode* right;
    };

    TreeSet() : root(NULL){}

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


    void intersectTrees(TreeSet* &anotherTreeSet)
    {
        intersectSubTrees(root, anotherTreeSet);
    }

    void sumTrees(TreeSet* &anotherTreeSet)
    {
        sumSubTrees(root, anotherTreeSet);
        anotherTreeSet->printTree();
    }

    virtual ~TreeSet()
    {
        deleteSubTree(root);
    }

protected:

    TreeNode* root;

    bool isEmpty()
    {
        return (root == NULL);
    }

    bool exsistsInSubtree(TreeNode *node, O value);

    void createNode(TreeNode* &node,O value);

    void addToSubtree(TreeNode* &node,O value);

    bool hasLeftChild(TreeNode* &node)
    {
        return (node->left != NULL);
    }

    bool hasRightChild(TreeNode* &node)
    {
        return (node->right != NULL);
    }

    bool hasOneChild(TreeNode* &node)
    {
        return ((hasLeftChild(node)) && !(hasRightChild(node))) || ( !(hasLeftChild(node)) && (hasRightChild(node)) );
    }

    bool isLeaf(TreeNode* &node)
    {
        return (!hasLeftChild(node) && !hasRightChild(node));
    }

    O popMostLeftValue(TreeNode* &node);

    void removeFromSubTree(TreeNode* &node, O value);

    virtual void printNode(TreeNode* &node);

    void inorder(TreeNode* &node);

    void deleteSubTree(TreeNode* &node);

    void intersectSubTrees(TreeNode* &node, TreeSet* anotherTreeSet);

    void sumSubTrees(TreeNode* &node, TreeSet* anotherTreeSet);

};

template <typename O>
bool TreeSet<O>::exsistsInSubtree(TreeNode *node, O value)
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
void TreeSet<O>::createNode(TreeNode* &node,O value)
{
    node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
}

template <typename O>
void TreeSet<O>::addToSubtree(TreeNode* &node,O value)
{
    if (node == NULL)
        return createNode(node,value);
    else if (node->value == value)
        return;
    else if (value > node->value)
        return addToSubtree(node->right,value);
    else
        return addToSubtree(node->left,value);
}

template <typename O>
O TreeSet<O>::popMostLeftValue(TreeNode* &node)
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
void TreeSet<O>::removeFromSubTree(TreeNode* &node,O value)
{
    if (node == NULL)
        cout << "No such an element.";
    else if (node -> value == value )
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
                    TreeNode* tmp = node->left;
                    delete node;
                    node = tmp;
                }
                else
                {
                    TreeNode* tmp = node->right;
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
    else if (value > node->value)
        return removeFromSubTree(node->right,value);
    else
        return removeFromSubTree(node->left,value);
}

template <typename O>
void TreeSet<O>::printNode(TreeNode* &node)
{
    cout << node->value << endl;
}

template <typename O>
void TreeSet<O>::inorder(TreeNode* &node)
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
void TreeSet<O>::deleteSubTree(TreeNode* &node)
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
void TreeSet<O>::intersectSubTrees(TreeNode* &node, TreeSet* anotherTreeSet)
{
    if (node != NULL)
    {
        if (anotherTreeSet->exsistsInTree(node->value))
        {
            cout << node->value << endl;
        }
        intersectSubTrees(node->left, anotherTreeSet);
        intersectSubTrees(node->right, anotherTreeSet);
    }
    else
        return;
}

template <typename O>
void TreeSet<O>::sumSubTrees(TreeNode* &node, TreeSet* anotherTreeSet)
{
    if (node != NULL)
    {
        if (!(anotherTreeSet->exsistsInTree(node->value)))
        {
            cout << node->value << endl;
        }
        sumSubTrees(node->left, anotherTreeSet);
        sumSubTrees(node->right, anotherTreeSet);
    }
    else
        return;
}
