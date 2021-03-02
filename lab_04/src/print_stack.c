#include <stdio.h>
#include "../inc/stack_as_static_array.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/print_stack.h"

//Печать стека (массив)
void print_sa(Stack_sa *st)
{
    if (is_empty_sa(st))
        printf("Стек пуст (статический массив)\n");
    else
    {
        printf("Элементы стека (статический массив): ");
        for (int i = 0; i < st->n; i++)
            printf("%d ", st->data[i]);
        printf("<-\n");
    }
}


//Печать стека (список)
void print_ll(Stack_ll *stack)
{
   if (is_empty_ll(stack))
       printf("Стек пуст (связный список)\n");
   else
   {
       printf("Элементы стека (связный список): -> ");
       //Сначала p указывает на начало списка, а потом оно двигается по нему, изменяя указатель
       for (Stack_ll *p = stack; p != NULL; p = p->next)
           printf("%d ", p->data);
       printf("\n");
   }
}


//Печать адресов связного списка
void print_adresses_ll(Stack_ll *stack_ll)
{
    printf("\nАдреса элементов связного списка: ");
    for (Stack_ll *p = stack_ll; p != NULL; p = p->next)
        printf("%p ", &p->data);

}

//Печать свободной области
void print_free_area(int *ll_free_area[], int count)
{

    printf("\nАдреса элементов свободной области: ");
    for (int i = 0; i < count; i++)
        printf("%p ", ll_free_area[i]);
    printf("\n");

}
