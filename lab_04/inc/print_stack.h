#ifndef PRINT_STACK_H
#define PRINT_STACK_H

#include "stack_as_static_array.h"
#include "stack_as_linked_list.h"

void print_ll(Stack_ll *stack);
void print_sa(Stack_sa *st);
int is_empty_ll(Stack_ll *stack);
int is_empty_sa(Stack_sa *st);
void print_adresses_ll(Stack_ll *stack_ll);
void print_free_area(int *ll_free_area[], int count);

#endif // PRINT_STACK_H
