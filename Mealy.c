#include "comp.h"

char    *Mealy(char *str)
{
    int     i;
    char    state;
    char    *output;
    
    if(check_string(str, "01") == 0)
    {
        printf("Invalid String\n");
        return (NULL);
    }
    i = strlen(str) - 1;
    state = 'A';
    output = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if(!output)
        return (NULL);
    output[strlen(str)] = '\0';
    output += strlen(str) - 1;
    str += strlen(str) - 1;
    while (*str)
    {
        if (state == 'A')
        {
            if (*str == '0')
            {
                output[i] = '0';
                state = 'A';
            } 
            else if (*str == '1')
            {
                output[i] = '1';
                state = 'B';
            }
        }
        else if (state == 'B')
        {
            if (*str == '0')
            {
                output[i] = '1';
                state = 'B';
            }
            else if (*str == '1')
            {
                output[i] = '0';
                state = 'B';
            }
        }
        i--;
        str--;
    }
    return (output);
}

int main(void)
{
    printf("%s\n", Mealy("1101010"));
    return (0);
}