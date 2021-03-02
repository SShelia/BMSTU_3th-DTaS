#include <stdio.h>
#include <time.h>

#include "../inc/queue_as_linked_list.h"
#include "../inc/queue_as_array.h"
#include "../inc/errors.h"
#include "../inc/data_input.h"

#define ITER 1000000

//Замер времени для добавления элемента в очередь
void time_push()
{
    int size_of_queue[6] = {10, 20, 50, 100, 500, 1000};

    printf("\n--------------------------------Добавление элемента в очередь-------------------------------\n");
    printf("\n  Количество элементов     Очередь на основе связного списка       Очередь на основе массива\n");
    for (int q = 0; q < 6; q++)
    {
        queue_sa array;
        init_queue_sa(&array);

        List list;
        init_queue_ll(&list);

        for (int i = 0; i < size_of_queue[q]; i++)
        {
            push_back_ll(&list, 1);
            push_back_sa(&array, 1);
        }

        clock_t start, stop;
        double time = 0;


        printf("%12.d",  size_of_queue[q]);
        for (int i = 0; i < ITER; i++)
        {
            start = clock();
            push_back_ll(&list, 1);
            stop = clock();
            time+=((double)stop-(double)start)/CLOCKS_PER_SEC;
            pop_front_ll(&list);
        }

        printf("%35.10f сек.", time/ITER);

        time = 0;
        for (int i = 0; i < ITER; i++)
        {
            start = clock();
            push_back_sa(&array, 1);
            stop = clock();
            time+=((double)stop-(double)start)/CLOCKS_PER_SEC;
            pop_front_sa(&array);
        }

        printf("%30.10f сек.\n", time/ITER);
    }

    printf("\n");

}



//Замер времени для удаления элемента из очереди
void time_pop()
{
    int size_of_queue[6] = {10, 20, 50, 100, 500, 1000};

    printf("\n------------------------------Удаление элемента из очереди----------------------------------\n");
    printf("\n  Количество элементов     Очередь на основе связного списка       Очередь на основе массива\n");
    for (int q = 0; q < 6; q++)
    {
        queue_sa array;
        init_queue_sa(&array);

        List list;
        init_queue_ll(&list);

        for (int i = 0; i < size_of_queue[q]; i++)
        {
            push_back_ll(&list, 1);
            push_back_sa(&array, 1);
        }

        clock_t start, stop;
        double time = 0;


        printf("%12.d",  size_of_queue[q]);
        for (int i = 0; i < ITER; i++)
        {
            start = clock();
            pop_front_ll(&list);
            stop = clock();
            time+=((double)stop-(double)start)/CLOCKS_PER_SEC;
            push_back_ll(&list, 1);
        }

        printf("%35.10f сек.", time/ITER);

        time = 0;
        for (int i = 0; i < ITER; i++)
        {
            start = clock();
            pop_front_sa(&array);
            stop = clock();
            time+=((double)stop-(double)start)/CLOCKS_PER_SEC;
            push_back_sa(&array, 1);
        }

        printf("%30.10f сек.\n", time/ITER);
    }

    printf("\n");

}

