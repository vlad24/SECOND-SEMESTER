#pragma once
#include <iostream>
using namespace std;

template <typename O>
//! A class on which a set with adding searching and removing will be based
class Tree
{
    friend class TreeTester;
public:
    struct TreeNode
    {
        O value;
        TreeNode* left;
        TreeNode* right;
    };

    Tree() : root(NULL){}

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

    void treeInorder()
    {
        if (!(isEmpty()))
            inorder(root);
    }

    ~Tree()
    {
        deleteSubTree(root);
    }

private:

    TreeNode* root;

    bool isEmpty()
    {
        return (root == NULL);
    }

    bool exsistsInSubtree(TreeNode *node, O value)
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

    void createNode(TreeNode* &node,O value)
    {
        node = new TreeNode;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }

    void addToSubtree(TreeNode* &node,O value)
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

    O popMostLeftValue(TreeNode* &node)
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


    void removeFromSubTree(TreeNode* &node,O value)
    {
        if (node == NULL)
            cout << "no such an element.\n";
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

    void inorder(TreeNode* &node)
    {
        if (node->left != NULL)
        {
            inorder(node->left);
            cout << node->value << endl;
            if (node->right != NULL)
                inorder(node->right);
        }
        else
        {
            cout << node->value << endl ;
            if (node->right != NULL)
                inorder(node->right);
        }
        return;
    }

    void deleteSubTree(TreeNode* &node)
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
};
