#include <stdio.h>
#include <stdlib.h>
#include "../inc/stack_as_static_array.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/print_stack.h"

void prosec_stack_sa(Stack_sa *stack_sa)
{
    printf("\nРезультат для массива: -> ");
    Stack_sa result_stack_sa;
    init_sa(&result_stack_sa);

    push_sa(&result_stack_sa, stack_sa->data[stack_sa->n - 1]);
    int result_index = 0;

    for (int i = stack_sa->n - 2; i >= 0; i--)
    {
        if (result_stack_sa.data[result_index] > stack_sa->data[i])
        {
            result_index++;
            push_sa(&result_stack_sa, stack_sa->data[i]);
        }
        else if (result_stack_sa.n != 1)
        {
            for (int j = result_stack_sa.n - 1; j >= 0; j--)
                printf("%d ", result_stack_sa.data[j]);
            for (int k = 0; k < result_index + 1; k++)
                pop_sa(&result_stack_sa);

            result_index = 0;
            push_sa(&result_stack_sa, stack_sa->data[i]);
        }
        else
        {
            pop_sa(&result_stack_sa);
            push_sa(&result_stack_sa, stack_sa->data[i]);
        }
    }


    if (result_stack_sa.n != 1)
    {
        for (int j = result_stack_sa.n - 1; j >= 0; j--)
            printf("%d ", result_stack_sa.data[j]);
    }
    for (int k = 0; k < result_index + 1; k++)
        pop_sa(&result_stack_sa);
}



void prosec_stack_ll(Stack_ll *stack_ll)
{

    printf("\nРезультат для связного списка: -> ");

    Stack_ll *result_stack_ll = (Stack_ll*)malloc(sizeof(Stack_ll));
    result_stack_ll->data = 0;
    result_stack_ll->next = NULL;
    pop_ll(&result_stack_ll);

    Stack_ll *p = stack_ll;
    push_ll(&result_stack_ll, p->data);
    p = p->next;

    for (; p != NULL; p = p->next)
    {
        if (result_stack_ll->data > p->data)
            push_ll(&result_stack_ll, p->data);

        else if (result_stack_ll->next != NULL)
        {
            for (Stack_ll *k = result_stack_ll; k != NULL; k = k->next)
                printf("%d ", k->data);
            while (is_empty_ll(result_stack_ll) == 0)
                pop_ll(&result_stack_ll);
            push_ll(&result_stack_ll, p->data);

        }
        else
        {
            pop_ll(&result_stack_ll);
            push_ll(&result_stack_ll, p->data);

        }


    }

    if (result_stack_ll->next != NULL)
    {
        for (Stack_ll *k = result_stack_ll; k != NULL; k = k->next)
            printf("%d ", k->data);
    }
    while (is_empty_ll(result_stack_ll) == 0)
        pop_ll(&result_stack_ll);
    printf("\n");
}


void prosec_stack_sa_for_time(Stack_sa *stack_sa)
{

    Stack_sa result_stack_sa;
    init_sa(&result_stack_sa);

    push_sa(&result_stack_sa, stack_sa->data[stack_sa->n - 1]);
    int result_index = 0;

    for (int i = stack_sa->n - 2; i >= 0; i--)
    {
        if (result_stack_sa.data[result_index] > stack_sa->data[i])
        {
            result_index++;
            push_sa(&result_stack_sa, stack_sa->data[i]);
        }
        else if (result_stack_sa.n != 1)
        {
            for (int j = result_stack_sa.n - 1; j >= 0; j--)
                ;
            for (int k = 0; k < result_index + 1; k++)
                pop_sa(&result_stack_sa);

            result_index = 0;
            push_sa(&result_stack_sa, stack_sa->data[i]);

        }
        else
        {
            pop_sa(&result_stack_sa);
            push_sa(&result_stack_sa, stack_sa->data[i]);

        }
    }
    for (int j = result_stack_sa.n - 1; j >= 0; j--)
        ;
    for (int k = 0; k < result_index + 1; k++)
        pop_sa(&result_stack_sa);
}



void prosec_stack_ll_for_time(Stack_ll *stack_ll)
{


    Stack_ll *result_stack_ll = (Stack_ll*)malloc(sizeof(Stack_ll));
    result_stack_ll->data = 0;
    result_stack_ll->next = NULL;
    pop_ll(&result_stack_ll);

    Stack_ll *p = stack_ll;
    push_ll(&result_stack_ll, p->data);
    p = p->next;

    for (; p != NULL; p = p->next)
    {
        if (result_stack_ll->data > p->data)
            push_ll(&result_stack_ll, p->data);

        else if (result_stack_ll->next != NULL)
        {
            for (Stack_ll *k = result_stack_ll; k != NULL; k = k->next)
                ;
            while (is_empty_ll(result_stack_ll) == 0)
                pop_ll(&result_stack_ll);
            push_ll(&result_stack_ll, p->data);

        }
        else
        {
            pop_ll(&result_stack_ll);
            push_ll(&result_stack_ll, p->data);

        }


    }

    for (Stack_ll *k = result_stack_ll; k != NULL; k = k->next)
        ;
    while (is_empty_ll(result_stack_ll) == 0)
        pop_ll(&result_stack_ll);

}

