#include "comp.h"

int check_string(char *str)
{
    while (*str)
    {
        if (*str != '0' && *str != '1')
            return (0);
        str++;
    }
    return (1);
}