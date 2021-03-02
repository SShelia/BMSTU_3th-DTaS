#ifndef STACK_AS_LINKED_LIST_H
#define STACK_AS_LINKED_LIST_H

typedef int Data;
typedef struct s_stack{
    Data data;
    struct s_stack *next;
}Stack_ll;

Stack_ll *create_node_ll(int data);
void push_ll(Stack_ll **stack, int data);
void pop_ll(Stack_ll **stack);

#endif // STACK_AS_LINKED_LIST_H

