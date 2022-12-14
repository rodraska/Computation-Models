#ifndef COMP_H
# define COMP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void    DFA(char *str);
void    print_results_DFA(char state);
void    NFA(char *str);
void    print_results_NFA(char *state);
char    *Mealy(char *str);
char    *Moore(char *str);
int     check_string(char *str, char *inputs);

#endif