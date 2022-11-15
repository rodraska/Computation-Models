#include "comp.h"

void    print_results_NFA(char *state)
{
    while (*state)
    {
        if (*state == 'B')
        {
            printf("String Accepted\n");
            return ;
        }     
        else if (*state == 'F')
        {
            printf("String Invalid\n");
            return ;
        }
        state++;
    }
    printf("String Not Accepted\n");
}

void    NFA(char *str)
{
    char    *state;

    if (check_string(str) == 0)
    {
        print_results_NFA("F");
        return ;
    }
    state = "A";
    while (*str)
    {
        while (*state)
        {
            if (*state == 'A')
            {
                if (*str == '1')
                    state = "A";
                else if (*str == '0')
                    state = "AB";
                break ;
            }
            state++;
        }
        str++;
    }
    print_results_NFA(state);
}

int main(void)
{
    NFA("100");
    NFA("1001");
    NFA("");
    NFA("abc");
    return (0);
}