#ifndef QUEUE_AS_LINKED_LIST_H
#define QUEUE_AS_LINKED_LIST_H

//Структура очереди
typedef struct queue_ll{
    int data;
    struct queue_ll *next;
}queue_ll;

//Указатели на начало и на конец очереди
typedef struct List
{
    int size;
    queue_ll *head;
    queue_ll *tail;
}List;


int is_empty(List *list);
void destruct_ll(List *list);

void pop_front_ll(List *list);
void init_queue_ll(List *list);
void push_back_ll(List *list, int data);
void print_list(List *lst);
void print_free_area(int *free_area[], int count);
void print_adresses_ll(List *list);


#endif // QUEUE_AS_LINKED_LIST_H
