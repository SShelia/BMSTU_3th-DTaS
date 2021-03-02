#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/stack_as_static_array.h"

//Инициализация стека
void init_sa(Stack_sa *st)
{
    st->n = 0;
}

//Проверка на пустоту стека
int is_empty_sa(Stack_sa *st)
{
    //Если стек пустой возвращатся 1
    return st->n == 0;
}

//Добавление элемента в начало стека
void push_sa(Stack_sa *st, Data number)
{
    st->data[st->n] = number;
    st->n++;
}

//Удаление элемента из начала
Data pop_sa(Stack_sa *st)
{
    Data res = st->data[st->n - 1];
    st->n --;
    return res;
}

//Проверка на переполнение стека
int is_full_sa(Stack_sa *st)
{
    //Если n равно количеству элементов возвращается 1
    return st->n == sizeof(st->data)/sizeof(st->data[0]);
}

