#include "comp.h"

void    print_results_DFA(char state)
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

    if (check_string(str, "01") == 0)
    {
        print_results_DFA('F');
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
    print_results_DFA(state);
}

int main(void)
{
    DFA("0011");
    DFA("10011101");
    DFA("0101");
    DFA("");
    DFA("aabb");
    return (0);
}