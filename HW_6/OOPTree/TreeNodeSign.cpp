#include <stdio.h>
#include <limits.h>
#include "TreeNodeSign.h"

TreeNodeSign::TreeNodeSign(char newSign)
{
    left = NULL;
    right = NULL;
    sign = newSign;
}

void TreeNodeSign::printNode()
{
    printf("%c", sign);
    if (left!= NULL)
        left->printNode();
    if (right != NULL)
        right->printNode();
}

int TreeNodeSign::calculateNode()
{
    switch(sign)
    {
    case ('+') :
    {
        return left->calculateNode() + right->calculateNode();
    }
    case ('-') :
    {
        return left->calculateNode() - right->calculateNode();
    }
    case ('*') :
    {
        return left->calculateNode() * right->calculateNode();
    }
    case ('/') :
    {
        if (right->calculateNode() != 0)
            return left->calculateNode() / right->calculateNode();
        else
        {
            printf("Division by zero!");
            return INT_MIN;
        }
    }
    }
}

char TreeNodeSign::getValue()
{
    return sign;
}
