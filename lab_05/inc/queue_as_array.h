#ifndef QUEUE_AS_ARRAY_H
#define QUEUE_AS_ARRAY_H

//Структура очереди для статического массива
#define MAX_ELEMENTS_NUMBER 1001
typedef struct queue_sa{
    int queue[MAX_ELEMENTS_NUMBER];
    int begin;
    int end;
    int size;
}queue_sa;


void pop_front_sa(queue_sa *array);
void print_array(queue_sa *array);
void push_back_sa(queue_sa *array, int data);
void init_queue_sa(queue_sa *array);
int is_full_sa(queue_sa *array);
int is_empty_sa(queue_sa *array);

#endif // QUEUE_AS_ARRAY_H
