#include <stdio.h>
#include <time.h>

#include "../inc/time_measurement.h"
#include "../inc/task_execution.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/stack_as_static_array.h"

#define ITER 10000

void time_measurement(Stack_sa *stack_sa, Stack_ll *stack_ll){

    printf("\nКолчество итераций - %d", ITER);
    printf("\nКоличество элементов в стеке - %d", stack_sa->n);
    //printf("\nОбъём занимаемой памяти стека (статическй массв)                 Объём занимаемой памяти стека (связный список)");
    //printf("\n%30.d б. %50.d б.", 4 * (stack_sa -> n + 1), 12 * (stack_sa ->n));
    printf("\nВремя обработки стека, представленного статическиим массивом     Время обработки стека, представленного связным списком\n");
    clock_t start, stop;

    //Замер для массива
    {
        double duration1 = -1.0;

        start = clock();
        for (int i = 0; i < ITER; i++)
            prosec_stack_sa_for_time(stack_sa);
        stop = clock();

        duration1=(double)(stop-start)/CLOCKS_PER_SEC;
        printf("%35.10lf сек.", (float)(duration1/ITER));
    }

    //Замер для списка
    {
        double duration2 = -1.0;

        start = clock();
        for (int i = 0; i < ITER; i++)
            prosec_stack_ll_for_time(stack_ll);
        stop = clock();

        duration2=(double)(stop-start)/CLOCKS_PER_SEC;
        printf("%55.10lf сек.", (float)(duration2/ITER));
    }
}
