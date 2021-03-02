#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "../inc/errors.h"
#include "../inc/data_input.h"
#include "../inc/time_measurement.h"
#include "../inc/stack_as_static_array.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/print_stack.h"
#include "../inc/task_execution.h"

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setbuf(stdout, NULL);
   int code = ok;

   //�������� ��������� ������ � ������� ��� �����
   Stack_sa stack_sa;
   init_sa(&stack_sa);
   Stack_ll *stack_ll = (Stack_ll*)malloc(sizeof(Stack_ll));
   stack_ll->data = 0;
   stack_ll->next = NULL;
   pop_ll(&stack_ll);


   //�������� ������� ��������� ��������
   Data *ll_free_area[N];
   int count = 0;

   printf("�������� ��������:"
          "\n1 - ���������� �������� � ����"
          "\n2 - �������� �������� �� �����"
          "\n3 - ������ �������� ��������� �����"
          "\n4 - ���������� �������"
          "\n0 - ���������� ���������"
          "\n�����: ");
   int command = command_input(0, 4);

   while (command != 0)
   {
       switch(command){
       case 1:
       {
           //���������� �������� � ����
           if (is_full_sa(&stack_sa))
               printf("\n���� ����������, ���������� ���������� (������������ ���������� ��������� - %d)\n", N);
           else
           {
               printf("\n������� ����� ����� - �������� �������� ��� ����������: ");
               int number = number_for_stack_input();

               //���������� �������� � ����, ��������������� � ���� ������������ �������
               push_sa(&stack_sa, number);

               //��������� �������� � ����, ��������������� � ���� �������� ������
               push_ll(&stack_ll, number);

               //�������� ��������� �������
               for (int i = 0; i < (int)(sizeof(ll_free_area)/sizeof(ll_free_area[0])); i++)
                   if ( ll_free_area[i] == &stack_ll->data)
                       count--;
           }

           printf("\n");
           //������ �������� ��������� �����
           print_sa(&stack_sa);
           print_ll(stack_ll);

           //������
           print_adresses_ll(stack_ll);
           print_free_area(ll_free_area, count);

           break;
       }
       case 2:
       {
           //�������� �������� �� �����
           if (is_empty_sa(&stack_sa) || is_empty_ll(stack_ll))
               printf("\n���� ������, �������� ����������\n");
           else
           {
               printf("\n");
               //�������� �������� �� �����, ��������������� � ���� ������������ �������
               pop_sa(&stack_sa);

               //�������� �������� �� ����a, ��������������� � ���� �������� ������
               ll_free_area[count] = &stack_ll->data;
               count++;
               pop_ll(&stack_ll);

               //������ �������� ��������� �����
               print_sa(&stack_sa);
               print_ll(stack_ll);

               //������
               print_adresses_ll(stack_ll);
               print_free_area(ll_free_area, count);

           }
           break;
       }
       case 3:
       {
           printf("\n");
           if (is_empty_sa(&stack_sa) || is_empty_ll(stack_ll))
           {
               printf("���� ����(����������� ������)\n");
               printf("���� ����(������� ������)\n");
           }
           else
           {
               //������ �������� ��������� �����
               print_sa(&stack_sa);
               print_ll(stack_ll);
               //������
               print_adresses_ll(stack_ll);
           }

           print_free_area(ll_free_area, count);

           break;
       }
       case 4:
       {
           /*
            * ������������ ��������� �����
            * ������������������ ����� ����� � ��������
            * �������
           */

           printf("\n�� ������ ��������� ������� � ������ ������, ��� c ����� � ��������� ����������? "
                  "\n1 - ������ ����"
                  "\n2 - ����� ����"
                  "\n�����: ");
           int choice = command_input(1, 2);
           if (choice == 1)
           {
               if (is_empty_sa(&stack_sa) || is_empty_ll(stack_ll))
               {
                   printf("\n���� ����, ���������� ��������� �������\n");
                   fflush(stdin);
               }
               else
               {
                   time_measurement(&stack_sa, stack_ll);
                   printf("\n\n�� ������ ������� ���������? "
                          "\n1 - ��"
                          "\n2 - ���"
                          "\n�����: ");
                   int choice_1 = command_input(1, 2);
                   if (choice_1 == 1)
                   {
                       printf("\n");
                       //������ �������� ��������� �����
                       print_sa(&stack_sa);
                       print_ll(stack_ll);

                       prosec_stack_sa(&stack_sa);
                       prosec_stack_ll(stack_ll);
                   }
                }
           }
           else
           {
               printf("������� ��������� ��������� (�� ������ 1 � �� ������ %d): ", N);
               int choice_3 = command_input(1, N);

               //�������� ������ ��������� ������ � ������� ��� �����
               Stack_sa stack_sa_new;
               init_sa(&stack_sa_new);
               Stack_ll *stack_ll_new = (Stack_ll*)malloc(sizeof(Stack_ll));
               stack_ll_new->data = 0;
               stack_ll_new->next = NULL;
               pop_ll(&stack_ll_new);

               //��������� ���������
               srand(time(NULL));
               int number = 0;
               for (int i = 0; i <choice_3; i++)
               {
                   number = rand()%100;
                   push_sa(&stack_sa_new, number);
                   push_ll(&stack_ll_new, number);
               }


               time_measurement(&stack_sa_new, stack_ll_new);
               printf("\n\n�� ������ ������� ����������? "
                      "\n1 - ��"
                      "\n2 - ���"
                      "\n�����: ");
               int choice_1 = command_input(1, 2);
               if (choice_1 == 1)
               {
                   printf("\n");
                   //������ �������� ��������� �����
                   print_sa(&stack_sa_new);
                   print_ll(stack_ll_new);

                   prosec_stack_sa(&stack_sa_new);
                   prosec_stack_ll(stack_ll_new);
               }

           }


           break;
       }
       }

       printf("\n�������� ��������:"
              "\n1 - ���������� �������� � ����"
              "\n2 - �������� �������� �� �����"
              "\n3 - ������ �������� ��������� ������"
              "\n4 - ���������� �������"
              "\n0 - ���������� ���������"
              "\n�����: ");
       command = command_input(0, 4);
    }


   return code;
}

