#include <stdio.h>
#include "../inc/stack_as_static_array.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/print_stack.h"

//������ ����� (������)
void print_sa(Stack_sa *st)
{
    if (is_empty_sa(st))
        printf("���� ���� (����������� ������)\n");
    else
    {
        printf("�������� ����� (����������� ������): ");
        for (int i = 0; i < st->n; i++)
            printf("%d ", st->data[i]);
        printf("<-\n");
    }
}


//������ ����� (������)
void print_ll(Stack_ll *stack)
{
   if (is_empty_ll(stack))
       printf("���� ���� (������� ������)\n");
   else
   {
       printf("�������� ����� (������� ������): -> ");
       //������� p ��������� �� ������ ������, � ����� ��� ��������� �� ����, ������� ���������
       for (Stack_ll *p = stack; p != NULL; p = p->next)
           printf("%d ", p->data);
       printf("\n");
   }
}


//������ ������� �������� ������
void print_adresses_ll(Stack_ll *stack_ll)
{
    printf("\n������ ��������� �������� ������: ");
    for (Stack_ll *p = stack_ll; p != NULL; p = p->next)
        printf("%p ", &p->data);

}

//������ ��������� �������
void print_free_area(int *ll_free_area[], int count)
{

    printf("\n������ ��������� ��������� �������: ");
    for (int i = 0; i < count; i++)
        printf("%p ", ll_free_area[i]);
    printf("\n");

}
