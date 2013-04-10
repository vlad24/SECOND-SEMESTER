#include <stdio.h>
#include "TreeNodeOperand.h"

TreeNodeOperand::TreeNodeOperand(char newOperand)
{
    left = NULL;
    right = NULL;
    operand = newOperand;
}

void TreeNodeOperand::printNode()
{
    printf("%c", operand);
}

int TreeNodeOperand::calculateNode()
{
    return (int(operand) - int('0'));
}

char TreeNodeOperand::getValue()
{
    return operand;
}
