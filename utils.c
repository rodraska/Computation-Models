#include "comp.h"

int check_string(char *str, char *inputs)
{
    int i;

    while (*str)
    {
        i = 0;
        while (1)
        {
            if (*str == inputs[i])
                break ;
            else if (inputs[i] == '\0')
                return (0);
            i++;
        }
        str++;
    }
    return (1);
}