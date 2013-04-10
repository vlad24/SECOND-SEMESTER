#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "Tree.h"
#include "TreeNodeOperand.h"
#include "TreeNodeSign.h"
#include "SymbolMaster.h"

Tree::Tree()
{
    root = NULL;
}

int Tree::calculateStringByTree(char* string)
{
    string = validator->avoidBracketsAndGaps(string);
    int last = strlen(string) - 1;
    if (validator->basicValidation(string))
    {
        formTreeFromPrefixString(root, 0, string, last);
        return caclulateTree();
    }
    else
    {
        printf("Incorrect string\n");
        throw 0;
    }
}

void Tree::printTree() const
{
    root->printNode();
}

Tree::~Tree()
{
    delete root;
}

bool Tree::isEmpty() const
{
    return (root == NULL);
}

int Tree::formTreeFromPrefixString(TreeNode *&node, int pos, char* string, int last)
{
    if (pos <= last)
    {
        if (symbolMaster.isSign(string[pos]))
        {
            node = new TreeNodeSign(string[pos]);
            pos++;

            pos = formTreeFromPrefixString(node->getLeft(), pos, string, last);
            pos++;
            pos = formTreeFromPrefixString(node->getRight(), pos, string, last);
        }
        else
        {
            node = new TreeNodeOperand(string[pos]);
            return pos;
        }
    }
}

int Tree::caclulateTree()
{
    if (!isEmpty())
        return root->calculateNode();
    else
    {
        printf("Empty tree.\n");
        throw 0;
    }
}
