#include "Exceptions.h"

int main()
{
    try
    {
        Error* error = new Error();
        printf("test mark 1\n");
    }
    catch(char value)
    {
        printf("%c\n", value);
    }

    return 0;
}

