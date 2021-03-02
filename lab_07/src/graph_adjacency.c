#include <stdio.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/graph_adjacency.h"

//Инициализация
void graph_adj_init(list_graph **list, int size)
{
    for (int i = 0; i < size; i++)
        list[i] = NULL;
}

//Создание узла
list_graph *create_node(int set_path_length, int set_value)
{
    list_graph *node = (list_graph *)malloc(sizeof(list_graph));

    if (node != NULL)
    {
        node->path_length = set_path_length;
        node->value = set_value;
        node->next = NULL;
    }
    return node;
}

//Проверка на пустоту
int is_empty(list_graph *head)
{
    return (head == NULL);
}

//Добавление в конец списка
void push_back(list_graph **list, int set_path_length, int value)
{
    list_graph *new_elem = create_node(set_path_length, value);

    if (!is_empty((*list)))
    {
        list_graph *tmp = *list;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new_elem;
    }
    else
        *list = new_elem;
}

//Удаление первого элемента
list_graph *pop_front(list_graph **head)
{
    list_graph *data = NULL;

    if (head != NULL && *head != NULL)
    {
        data = create_node((*head)->path_length, (*head)->value);
        list_graph *del_elem = *head;
        *head = (*head)->next;
        free(del_elem);
    }
    return data;
}


//Очистка списка и освобождение памяти
void destruct(list_graph **head)
{
    list_graph *del_elem = NULL;
    while (is_empty(*head) == 0)
    {
        del_elem = pop_front(head);
        if (del_elem != NULL)
            free(del_elem);
    }
}





