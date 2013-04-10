#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "PointerStack.h"
#include "StringCalculator.h"
enum PolishPriorities
{
    plusMinusPriority = 5,
    multDivPriotity = 7,
    openBracketPrirority = 2,
    closingBracketPriotity = 4,
    otherPriority = 0
};
bool StringCalculator::isNumber(char v) const
{
    return ((v <= '9') && (v >= '0'));
}

bool StringCalculator::isSign(char v) const
{
    return ((v == '+')||(v == '-')||(v == '*')||(v == '/'));
}

int StringCalculator::makeOperation(char sign, int argument1, int argument2)
{
    switch (sign)
    {
    case ('-') :
    {
        return argument1 - argument2;
    }
    case ('+') :
    {
        return argument1 + argument2;
    }
    case ('*') :
    {
        return argument1 * argument2 ;
    }
    case ('/') :
    {
        if (argument2 != 0)
            return argument1 / argument2 ;
        else
            return INT_MAX ;
    }
    }
}

int StringCalculator::polishPriority(char v) const
{
        if ((v == '+') || (v == '-'))
            return plusMinusPriority;
        else if ((v == '*') || (v == '/'))
            return multDivPriotity;
        else if (v == '(')
            return openBracketPrirority;
        else if (v == ')')
            return closingBracketPriotity;
        else
            return otherPriority;
}
void StringCalculator::makePolish(char normal[], StackInterface* &stack)
{
    int newLength = strlen(normal) + 1;
    char tmp[newLength];
    for (int y = 0 ; y < newLength; y++)
    {
        tmp[y] = '\0';
    }
    int u = 0;
    int v = 0;
    for (u = 0; u < newLength; u++)
    {
        if (isNumber(normal[u]))
        {
            tmp[v] = normal[u];
            v++;
        }
        else
        {

            if (isSign(normal[u]))
            {
                if (polishPriority(normal[u]) > polishPriority(char(stack->top())))
                {
                    stack->push(normal[u]);
                }
                else
                {
                    while (polishPriority(normal[u]) <= polishPriority(char(stack->top())))
                    {
                        tmp[v] = stack->pop();
                        v++;
                    }
                    stack->push(normal[u]);
                }
            }
            else
            {
                if (polishPriority(normal[u]) == openBracketPrirority)
                   stack->push(normal[u]);
                else
                {
                    while ((polishPriority(char(stack->top())) != openBracketPrirority) &&
                          ((polishPriority(char(stack->top())) != otherPriority)))
                    {
                        tmp[v] = char(stack->pop());
                        v++;
                    }
                    //Deleting the opening bracket, because we do not need it
                    stack->pop();
                }
            }
        }
    }
    // Finish the line
    tmp[v] = '\0';
    // Replacing the infix version of the string by the polish one
    for (int j = 0; j <= v; j++)
    {
      normal[j] = tmp[j];
    }
}
int StringCalculator::convertToInt(char v) const
{
    return (v - '0');
}
int StringCalculator::calculateExpression(char string[])
{
        StackInterface* stackObject = new PointerStack();
        makePolish(string, stackObject);
        //printf("%s\n", string);
        int i = 0;
        int length = strlen(string) + 1;
        int argument1 = 1;
        int argument2 = 1;
        int tmpResult = 0;
        for (i = 0; i < length; i++)
        {
            if (isNumber(string[i]))
                stackObject->push(convertToInt(string[i]));
            if (isSign(string[i]))
            {
                argument2 = stackObject->pop();
                argument1 = stackObject->pop();
                tmpResult = makeOperation(string[i], argument1, argument2);
                stackObject->push(tmpResult);
            }
        }
        int result = stackObject->pop();
        delete stackObject;
        return result;
}
