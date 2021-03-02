#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../inc/stack_as_linked_list.h"

//Создание одного элемента
Stack_ll *create_node_ll(int data)
{
    //Выделение памяти
    Stack_ll *node = (Stack_ll*)malloc(sizeof(Stack_ll));
    if (node != NULL)
    {
        //Добавление значения
        node->data = data;
        //Указатель на следующий элемент связного списка
        node->next = NULL;
    }
    return node;
}

//Проверка на пустоту
int is_empty_ll(Stack_ll *stack)
{
    return stack == NULL;
}

//Добавление в начало стека
void push_ll(Stack_ll **stack, int data)
{
    //Создание нового элемента
    Stack_ll *new_node = create_node_ll(data);
    //Ставим укзатель нового элемента на бывший первый элемент(теперь второй)
    new_node->next = *stack;
    //Переопределяем стек, с новым первым элементом
    *stack = new_node;
}

//Удаление первого элемента
void pop_ll(Stack_ll **stack)
{
    //Создаем указатель на первый элемент стека
    Stack_ll *tmp = *stack;

    //Указателю на первый элемент стека присваиваем значение указателя на второй элемент
    *stack = tmp->next;

    //Освобождаем память для первого элемента
    free(tmp);
}
