#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/queue_as_linked_list.h"

//Инициализация очереди
void init_queue_ll(List *list)
{
    list->head = (queue_ll*)malloc(sizeof(queue_ll));
    list->tail = (queue_ll*)malloc(sizeof(queue_ll));

    list->head->next = list->tail;
    list->head->data = 0;

    list->tail->next = NULL;
    list->tail->data = 0;

    list->size = 0;
}

//Вставка в конец очереди
void push_back_ll(List *list, int data)
{
    queue_ll *new_elem = list->tail;
    new_elem->data = data;

    list->tail = (queue_ll*)malloc(sizeof(queue_ll));
    list->tail->next = NULL;
    list->tail->data = 0;

    new_elem->next = list->tail;

    list->size += 1;

    /*
    if (list->size == 0)
    {
       list->head->data = data;
       list->size+=1;
    }
    else if (list->size == 1)
    {
      list->tail->data = data;
      list->size += 1;
    }
    else
    {
      queue_ll *new_elem = (queue_ll*)malloc(sizeof(queue_ll));
      new_elem->data = data;

      list->tail->next = new_elem;
      new_elem->next = NULL;

      list->tail = new_elem;
      list->size += 1;
    }
    */

}

//Проверка на пустоту
int is_empty(List *list)
{
    if (list->size ==0) return 1;
    else return 0;
}

//Извлечение из начала очереди
void pop_front_ll(List *list)
{
    if (is_empty(list) == 0)
    {
        queue_ll *del_elem = list->head->next;

        list->head->next = del_elem->next;
        list->size-=1;

        free(del_elem);
    }
    /*
    if (is_empty(list) == 0)
    {
        queue_ll *del_elem = list->head;
        list->size-=1;
        list->head = del_elem->next;

        free(del_elem);

        if (list->size == 1)
        {
          list->tail = (queue_ll*)malloc(sizeof(queue_ll));
          list->tail->next = NULL;
          list->tail->data = 0;

          list->head->next = list->tail;

        }
        else if (list->size == 0)
          init_queue_ll(list);
    }
    */

}



//Очистка очереди и освобождение памяти
void destruct_ll(List *list)
{
    while (is_empty(list))
        pop_front_ll(list);

    free(list->head);
    list->head = NULL;

    free(list->tail);
    list->tail = NULL;
}


void print_list(List *list)
{
    if (is_empty(list))
        printf("Очередь пуста (связной список): HEAD -> TAIL\n");
    else
    {
        printf("Элементы очереди (связной список): ");
        for (queue_ll *i = list->head->next; i != list->tail; i = i->next )
            printf("%d -> ", i->data);

        printf("NULL\n");
     }
}

//Печать адресов связного списка
void print_adresses_ll(List *list)
{
    printf("\nАдреса элементов связного списка: ");
    for (queue_ll *i = list->head->next; i != list->tail; i = i->next )
        printf("%p ", &i->data);
}

//Печать свободной области
void print_free_area(int *free_area[], int count)
{
    printf("\nАдреса элементов свободной области: ");
    for (int i = 0; i < count; i++)
        printf("%p ", free_area[i]);
    printf("\n\n");

}



