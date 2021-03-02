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

   //Создание связнного списка и массива для стека
   Stack_sa stack_sa;
   init_sa(&stack_sa);
   Stack_ll *stack_ll = (Stack_ll*)malloc(sizeof(Stack_ll));
   stack_ll->data = 0;
   stack_ll->next = NULL;
   pop_ll(&stack_ll);


   //Создание массива свободных областей
   Data *ll_free_area[N];
   int count = 0;

   printf("Выберите действие:"
          "\n1 - Добавление элемента в стек"
          "\n2 - Удаление элемента из стека"
          "\n3 - Печать текущего состояния стека"
          "\n4 - Выполнение задания"
          "\n0 - Завершение программы"
          "\nВыбор: ");
   int command = command_input(0, 4);

   while (command != 0)
   {
       switch(command){
       case 1:
       {
           //Добавление элемента в стек
           if (is_full_sa(&stack_sa))
               printf("\nСтек переполнен, добавление невозможно (максимальное количество элементов - %d)\n", N);
           else
           {
               printf("\nВведите целое число - значение элемента для добавления: ");
               int number = number_for_stack_input();

               //Добавление элемента в стек, представленного в виде статического массива
               push_sa(&stack_sa, number);

               //Добавлени элемента в стек, представленного в виде связного списка
               push_ll(&stack_ll, number);

               //Проверка свободной области
               for (int i = 0; i < (int)(sizeof(ll_free_area)/sizeof(ll_free_area[0])); i++)
                   if ( ll_free_area[i] == &stack_ll->data)
                       count--;
           }

           printf("\n");
           //Печать текущего состояния стека
           print_sa(&stack_sa);
           print_ll(stack_ll);

           //Адреса
           print_adresses_ll(stack_ll);
           print_free_area(ll_free_area, count);

           break;
       }
       case 2:
       {
           //Удаление элемента из стека
           if (is_empty_sa(&stack_sa) || is_empty_ll(stack_ll))
               printf("\nСтек пустой, удаление невозможно\n");
           else
           {
               printf("\n");
               //Удаление элемента из стека, представленного в виде статического массива
               pop_sa(&stack_sa);

               //Удаление элемента из стекa, представленного в виде связного списка
               ll_free_area[count] = &stack_ll->data;
               count++;
               pop_ll(&stack_ll);

               //Печать текущего состояния стека
               print_sa(&stack_sa);
               print_ll(stack_ll);

               //Адреса
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
               printf("Стек пуст(статический массив)\n");
               printf("Стек пуст(связный список)\n");
           }
           else
           {
               //Печать текущего состояния стека
               print_sa(&stack_sa);
               print_ll(stack_ll);
               //Адреса
               print_adresses_ll(stack_ll);
           }

           print_free_area(ll_free_area, count);

           break;
       }
       case 4:
       {
           /*
            * Распечатайте убывающие серии
            * последовательности целых чисел в обратном
            * порядке
           */

           printf("\nВы хотите выполнить задание с данным стеком, или c новым с рандомным заполненем? "
                  "\n1 - старый стек"
                  "\n2 - новый стек"
                  "\nВыбор: ");
           int choice = command_input(1, 2);
           if (choice == 1)
           {
               if (is_empty_sa(&stack_sa) || is_empty_ll(stack_ll))
               {
                   printf("\nСтек пуст, невозможно выполнить задание\n");
                   fflush(stdin);
               }
               else
               {
                   time_measurement(&stack_sa, stack_ll);
                   printf("\n\nВы хотите вывести результат? "
                          "\n1 - да"
                          "\n2 - нет"
                          "\nВыбор: ");
                   int choice_1 = command_input(1, 2);
                   if (choice_1 == 1)
                   {
                       printf("\n");
                       //Печать текущего состояния стека
                       print_sa(&stack_sa);
                       print_ll(stack_ll);

                       prosec_stack_sa(&stack_sa);
                       prosec_stack_ll(stack_ll);
                   }
                }
           }
           else
           {
               printf("Введите колчество элементов (не меньше 1 и не больше %d): ", N);
               int choice_3 = command_input(1, N);

               //Создание нового связнного списка и массива для стека
               Stack_sa stack_sa_new;
               init_sa(&stack_sa_new);
               Stack_ll *stack_ll_new = (Stack_ll*)malloc(sizeof(Stack_ll));
               stack_ll_new->data = 0;
               stack_ll_new->next = NULL;
               pop_ll(&stack_ll_new);

               //Рандомное заполнене
               srand(time(NULL));
               int number = 0;
               for (int i = 0; i <choice_3; i++)
               {
                   number = rand()%100;
                   push_sa(&stack_sa_new, number);
                   push_ll(&stack_ll_new, number);
               }


               time_measurement(&stack_sa_new, stack_ll_new);
               printf("\n\nВы хотите вывести результата? "
                      "\n1 - да"
                      "\n2 - нет"
                      "\nВыбор: ");
               int choice_1 = command_input(1, 2);
               if (choice_1 == 1)
               {
                   printf("\n");
                   //Печать текущего состояния стека
                   print_sa(&stack_sa_new);
                   print_ll(stack_ll_new);

                   prosec_stack_sa(&stack_sa_new);
                   prosec_stack_ll(stack_ll_new);
               }

           }


           break;
       }
       }

       printf("\nВыберите действие:"
              "\n1 - Добавление элемента в стек"
              "\n2 - Удаление элемента из стека"
              "\n3 - Печать текущего состояния стеков"
              "\n4 - Выполнение задания"
              "\n0 - Завершение программы"
              "\nВыбор: ");
       command = command_input(0, 4);
    }


   return code;
}

