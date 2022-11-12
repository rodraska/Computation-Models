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
    char    state;

    if (check_string(str) == 0)
    {
        print_results('F');
        return ;
    }
    state = 'A';
    while (*str)
    {
        if (state == 'A')
        {
            if (*str == '0')
                state = 'B';
            else if (*str == '1')
                state = 'A';
        }
        else if (state == 'B')
        {
            if (*str == '0')
                state = 'C';
            else if (*str == '1')
                state = 'A';
        }
        else if (state == 'C')
        {
            if (*str == '0')
                state = 'C';
            else if (*str == '1')
                state = 'D';
        }
        else if (state == 'D')
        {
            if (*str == '0')
                state = 'B';
            else if (*str == '1')
                state = 'E';
        }
        else if (state == 'E')
        {
            if (*str == '0' || *str == '1')
                state = 'E';
        }
        str++;
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