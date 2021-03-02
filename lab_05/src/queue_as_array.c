#include <stdio.h>

#include "../inc/queue_as_array.h"

//Инициализация очереди
void init_queue_sa(queue_sa *array)
{
    array->begin = -1;
    array->end = -1;
    array->size = 0;

}

//Проверка переполнения
int is_full_sa(queue_sa *array)
{
    return ((array->begin == array->end + 1) || (array->begin == 0 && array->end == MAX_ELEMENTS_NUMBER - 1));

}

//Проверка на пустоту
int is_empty_sa(queue_sa *array)
{
    return(array->begin == -1);
}

//Добавление элемента в конец очереди
void push_back_sa(queue_sa *array, int data)
{
    if ((is_full_sa(array)))
        printf("Очередь переполнена, добавление невозможно!");
    else
    {
        if (array->begin == -1)
            array->begin = 0;

        array->end = (array->end + 1) % MAX_ELEMENTS_NUMBER;
        array->queue[array->end] = data;
        array->size++;
    }

}

//Извлечение элемента из начала очереди
void pop_front_sa(queue_sa *array)
{
    if (is_empty_sa(array))
        printf("Удаление невозможно, очередь пуста!");
    else
    {
       if (array->begin == array->end)
       {
            array->begin = -1;
            array->end = -1;
       }
       else
       array->begin = (array->begin + 1) % MAX_ELEMENTS_NUMBER;
       array->size--;

    }

}

//Вывод элементов очереди
void print_array(queue_sa *array)
{
    if (is_empty_sa(array))
        printf("Очередь пуста (массив): HEAD -> TAIL\n");
    else
    {
        printf("Элементы очереди (массив): ");
        int h;
        for(h = array->begin; h < array->end; h++)
           printf("%d -> ",array->queue[h]);
        printf("%d -> NULL\n",array->queue[h]);
    }

}


