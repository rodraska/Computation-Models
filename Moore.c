#include "comp.h"

char    *Moore(char *str)
{
    int     i;
    int     len;
    char    state;
    char    *output;

    if(check_string_ab(str) == 0)
    {
        printf("Invalid String\n");
        return (NULL);
    }
    state = 'A';
    i = 0;
    len = strlen(str) + 1;
    output = (char *)malloc(sizeof(char) * (len + 1));
    if(!output)
        return (NULL);
    output[len] = '\0';
    while (i < len)
    {
        if (state == 'A')
        {
            output[i] = '0';
            if (*str == 'a')
                state = 'B';
            else if (*str == 'b')
                state = 'A';
        }
        else if (state == 'B')
        {
            output[i] = '0';
            if (*str == 'a')
                state = 'B';
            else if (*str == 'b')
                state = 'C';
        }
        else if (state == 'C')
        {
            output[i] = '0';
            if (*str == 'a')
                state = 'B';
            else if (*str == 'b')
                state = 'D';
        }
        else if (state == 'D')
        {
            output[i] = '1';
            if (*str == 'a')
                state = 'B';
            else if (*str == 'b')
                state = 'A';
        }
        i++;
        str++;
    }
    return (output);
}

int main(void)
{
    printf("%s\n", Moore("abbbabb"));
    return (0);
}