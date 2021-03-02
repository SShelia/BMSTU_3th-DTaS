#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "../inc/queue_as_linked_list.h"
#include "../inc/queue_as_array.h"
#include "../inc/errors.h"
#include "../inc/data_input.h"
#include "../inc/time_measurement.h"
#include "../inc/task_execution.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setbuf(stdout, NULL);

    int code  = ok;

    queue_sa array;
    init_queue_sa(&array);

    List list;
    init_queue_ll(&list);

    int *free_area[MAX_ELEMENTS_NUMBER];
    int count_free_area = 0;

    printf("Выберите действие:\n"
           "1 - Добавить элемент в очередь (максимальное количество элементов %d)\n"
           "2 - Удалить элемент из очереди\n"
           "3 - Распечатать текущее состояние очереди\n"
           "4 - Выполнить задание для связного списка\n"
           "5 - Выполнить задание для кольцевого массива\n"
           "6 - Сравнить время обработки очереди, реализованной в виде массива и связного списка\n"
           "0 - Завершить программу\n"
           "Выбор: ", MAX_ELEMENTS_NUMBER);
    int command = command_input(0, 6);

    while (command != 0)
    {
        switch(command){

        //Добавление элемента в очередь
        case 1:
        {

            if (is_full_sa(&array))
                printf("\nОчередь переполнена, добавление невозможно (максимальное количество элементов - %d)\n", MAX_ELEMENTS_NUMBER);
            else
            {
                printf("\nВведите целое число - значение элемента для добавления: ");
                int number = number_for_queue_input();

                //Добавление элемента в очередь - массив
                push_back_sa(&array, number);

                //Добавлени элемента в очередь - связный список
                push_back_ll(&list, number);

                //Проверка свободной области
                for (int i = 0; i < (int)(sizeof(free_area)/sizeof(free_area[0])); i++)
                {
                    if ((void*)free_area[i] == (void*)list.head)
                        count_free_area--;
                }
            }

            printf("\n");

            //Печать текущего состояния очереди
            print_array(&array);
            print_list(&list);

            //Адреса
            print_adresses_ll(&list);
            print_free_area(free_area, count_free_area);

            break;
        }
        case 2:
        {

            //Удаление элемента из стека
            if (is_empty_sa(&array) || is_empty(&list))
                printf("\nОчередь пуста, удаление невозможно!\n\n");
            else
            {
                printf("\n");

                //Удаление элемента из очереди - массива
                pop_front_sa(&array);

                //Удаление элемента из очереди - связного списка
                free_area[count_free_area] = (void*)list.head->next;
                count_free_area++;
                pop_front_ll(&list);

                //Печать текущего состояния очереди
                print_array(&array);
                print_list(&list);

                //Адреса
                print_adresses_ll(&list);
                print_free_area(free_area, count_free_area);

            }
            break;
        }
        case 3:
        {
            printf("\n");
            //Печать текущего состояния очереди
            print_array(&array);
            print_list(&list);

            //Адреса
            print_adresses_ll(&list);
            print_free_area(free_area, count_free_area);

            break;
        }
        case 4:
        {

            task_execution();
            break;
        }
        case 5:
        {
            task_execution_sa();
            break;
        }
        case 6:
        {
            if (MAX_ELEMENTS_NUMBER < 1001)
                printf("\nНевозможно провести полноценное сравнения, так как число элементов в очереди < 1001\n\n");
            else
            {
                time_push();
                time_pop();
            }
            break;
        }
        }


        printf("Выберите действие:\n"
               "1 - Добавить элемент в очередь (максимальное количество элементов %d)\n"
               "2 - Удалить элемент из очереди\n"
               "3 - Распечатать текущее состояние очереди\n"
               "4 - Выполнить задание для связного списка\n"
               "5 - Выполнить задание для кольцевого массива\n"
               "6 - Сравнить время обработки очереди, реализованной в виде массива и связного списка\n"
               "0 - Завершить программу\n"
               "Выбор: ", MAX_ELEMENTS_NUMBER);
        command = command_input(0, 6);
     }

    destruct_ll(&list);
    return code;
}
