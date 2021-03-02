#ifndef STACK_AS_STATIC_ARRAY_H
#define STACK_AS_STATIC_ARRAY_H

#define N 1000 //Размер маасива

typedef int Data;
typedef struct{
    Data data[N];
    int n;
}Stack_sa;

void init_sa(Stack_sa *st);
int is_empty_sa(Stack_sa *st);
void push_sa(Stack_sa *st, Data data);
Data pop_sa(Stack_sa *st);
int is_full_sa(Stack_sa *st);
void print_sa(Stack_sa *st);
#endif // STACK_AS_STATIC_ARRAY_H
