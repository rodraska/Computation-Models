#ifndef COMP_H
# define COMP_H

# include <stdio.h>
# include <string.h>

void    DFA(char *str);
void    print_results_DFA(char state);
int     check_string(char *str);
void    NFA(char *str);
void    print_results_NFA(char *state);

#endif