#include <stdio.h>
#include <time.h>

#include "../inc/time_measurement.h"
#include "../inc/task_execution.h"
#include "../inc/stack_as_linked_list.h"
#include "../inc/stack_as_static_array.h"

#define ITER 10000

void time_measurement(Stack_sa *stack_sa, Stack_ll *stack_ll){

    printf("\n��������� �������� - %d", ITER);
    printf("\n���������� ��������� � ����� - %d", stack_sa->n);
    //printf("\n����� ���������� ������ ����� (���������� �����)                 ����� ���������� ������ ����� (������� ������)");
    //printf("\n%30.d �. %50.d �.", 4 * (stack_sa -> n + 1), 12 * (stack_sa ->n));
    printf("\n����� ��������� �����, ��������������� ������������ ��������     ����� ��������� �����, ��������������� ������� �������\n");
    clock_t start, stop;

    //����� ��� �������
    {
        double duration1 = -1.0;

        start = clock();
        for (int i = 0; i < ITER; i++)
            prosec_stack_sa_for_time(stack_sa);
        stop = clock();

        duration1=(double)(stop-start)/CLOCKS_PER_SEC;
        printf("%35.10lf ���.", (float)(duration1/ITER));
    }

    //����� ��� ������
    {
        double duration2 = -1.0;

        start = clock();
        for (int i = 0; i < ITER; i++)
            prosec_stack_ll_for_time(stack_ll);
        stop = clock();

        duration2=(double)(stop-start)/CLOCKS_PER_SEC;
        printf("%55.10lf ���.", (float)(duration2/ITER));
    }
}
