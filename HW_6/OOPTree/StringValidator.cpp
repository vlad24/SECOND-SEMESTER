#include "StringValidator.h"
#include "string.h"
#include "stdio.h"

bool StringValidator::basicValidation(char *s) const
{
    bool ok = true;
    bool symbolsState = false;
    bool signsState = true;
    int i = 0;
    int signs = 0;
    int operands = 0;

    while ((i < strlen(s)) && ok)
    {
        if (signsState)
        {
            if (isSign(s[i]))
            {
                signs++;
                i++;
            }
            else
            {
                if (i == 0)
                {
                    ok = false;
                    i++;
                }
                else
                {
                    symbolsState = true;
                    operands++;
                    i++;
                }
            }
        }
        else
        {
            if (isSign(s[i]))
            {
                ok = false;
                break;
            }
            else
            {
                operands++;
                i++;
            }
        }
    }
    return (ok && (signs <= operands));
}

char* StringValidator::avoidBracketsAndGaps(char *str)
{
    char* bufString = strdup(str);
    int j = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!((isGap(str[i])) || isBracket(str[i])))
        {
            j++;
            bufString[j] = str[i];
        }
    }
    j++;
    bufString[j] = '\0';
    return bufString;
}
