#include "DFA.h"

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

void    print_results(char state)
{
    if (state == 'E')
        printf("String Accepted\n");
    else if (state == 'F')
        printf("String Invalid\n");
    else
        printf("String Not Accepted\n");
}

void    DFA(char *str)
{
    int     len;
    int     i;
    char    state;

    if (check_string(str) == 0)
    {
        print_results('F');
        return ;
    }
    len = strlen(str);
    state = 'A';
    i = -1;
    while (++i < len)
    {
        if (state == 'A')
        {
            if (str[i] == '0')
                state = 'B';
            else if (str[i] == '1')
                state = 'A';
        }
        else if (state == 'B')
        {
            if (str[i] == '0')
                state = 'C';
            else if (str[i] == '1')
                state = 'A';
        }
        else if (state == 'C')
        {
            if (str[i] == '0')
                state = 'C';
            else if (str[i] == '1')
                state = 'D';
        }
        else if (state == 'D')
        {
            if (str[i] == '0')
                state = 'B';
            else if (str[i] == '1')
                state = 'E';
        }
        else if (state == 'E')
        {
            if (str[i] == '0' || str[i] == '1')
                state = 'E';
        }
    }
    print_results(state);
}

int main(void)
{
    DFA("0011");
    DFA("10011101");
    DFA("0101");
    DFA("aabb");
    return (0);
}