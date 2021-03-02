#include <stdio.h>
#include <Windows.h>

#include <sys/time.h>
#include <time.h>
#include <Windows.h>
#include "../inc/structures.h"

#include "../inc/errors.h"
#include "../inc/memory_allocation_for_matrix.h"
#include "../inc/input_size_and_command.h"
#include "../inc/filling_matrix.h"
#include "../inc/addition_of_matrices.h"
#define NS_IN_S  1E9

#define NUM_ITER 1

void output_sparce_matrices(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix);
void output_usual_matrices(struct usual_matrix *matrix_1, struct usual_matrix *matrix_2, struct usual_matrix *result_matrix);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setbuf(stdout, NULL);

    int code = ok;

    //����� ���������� �������
    printf("�������� ������� ���������� ������: \n1 - ������ ���������� \n2 - �������������� ���������� \n�����: ");
    int command = 0;
    code = other_number_input(&command);
    if (code == ok && (command > 2 || command < 1))
        code = input_error;
    while (code != ok)
    {
        printf("\n������������ ����.\n�����: ");
        code = other_number_input(&command);
        if (code == ok && (command > 2 || command < 1))
            code = input_error;
    }

    struct usual_matrix matrix_1;
    struct usual_matrix matrix_2;
    struct sparse_matrix sp_matrix_1;
    struct sparse_matrix sp_matrix_2;

    if (command == 1)
    {

        input_size(&matrix_1.lines, &matrix_1.columns);
        matrix_2.lines = matrix_1.lines;
        matrix_2.columns = matrix_1.columns;

        //��������� ������ ��� ������
        matrix_1.matrix = allocate_matrix(matrix_1.lines, matrix_1.columns);
        matrix_2.matrix = allocate_matrix(matrix_2.lines, matrix_2.columns);

        //���������� ������
        printf("\n���� ��������� ������ �������:\n");
        sp_matrix_1.num_non_zero_elem = filling_matrix(&matrix_1);
        printf("\n���� ��������� ������ ������:\n");
        sp_matrix_2.num_non_zero_elem = filling_matrix(&matrix_2);


    }
    else if (command == 2)
    {

        input_size(&matrix_1.lines, &matrix_1.columns);
        matrix_2.lines = sp_matrix_2.lines  = sp_matrix_1.lines = matrix_1.lines;
        matrix_2.columns = sp_matrix_2.columns  = sp_matrix_1.columns = matrix_1.columns;

        int per_of_occupancy = 0;

        printf("������� ��������������� ������� ���������� (����� ��������������� ����� <=100): ");
        code = other_number_input(&per_of_occupancy);
        if (code ==ok && per_of_occupancy > 100 )
            code = input_error;
        while (code != ok)
        {
            printf("\n������������ ����.������� ��������������� ������� ���������� (����� ��������������� ����� <=100): ");
            code = other_number_input(&per_of_occupancy);
            if (code == ok && per_of_occupancy > 100)
                code = input_error;
        }

        //��������� ������ ���  ������� ������
        matrix_1.matrix = allocate_matrix(matrix_1.lines, matrix_1.columns);
        matrix_2.matrix = allocate_matrix(matrix_2.lines, matrix_2.columns);

        //��������� ���������� � ������� ���������� ��������� ���������
        int flag = 0;
        sp_matrix_1.num_non_zero_elem = filling_matrix_random(&matrix_1, per_of_occupancy, flag);
        flag = 1;
        sp_matrix_2.num_non_zero_elem = filling_matrix_random(&matrix_2, per_of_occupancy, flag);


    }

    //��������� ������ ��� ��������� ��������� ����������� ������� (+1 ��� �������� �������� �� ��������� (��� ����� ��� ���� ������)
    sp_matrix_1.elements_value = calloc(sp_matrix_1.num_non_zero_elem + 1, sizeof(int));
    sp_matrix_1.column_index = calloc(sp_matrix_1.num_non_zero_elem + 1, sizeof(int));
    sp_matrix_1.line_index = calloc(sp_matrix_1.lines + 1, 8);

    sp_matrix_2.elements_value = calloc(sp_matrix_2.num_non_zero_elem + 1, sizeof(int));
    sp_matrix_2.column_index = calloc(sp_matrix_2.num_non_zero_elem + 1, sizeof(int));
    sp_matrix_2.line_index = calloc(sp_matrix_2.lines + 1, 8);


    //���������� ����������� ������
    filling_sparse_matrix(&matrix_1, &sp_matrix_1);
    filling_sparse_matrix(&matrix_2, &sp_matrix_2);

    //�������� ������� ������ �����������
    struct usual_matrix result_matrix;
    result_matrix.lines = matrix_1.lines;
    result_matrix.columns = matrix_1.columns;
    result_matrix.matrix = allocate_matrix(result_matrix.lines, result_matrix.columns);

    //�������� ����������� ������
    struct sparse_matrix sp_result_matrix;
    sp_result_matrix.lines = sp_matrix_1.lines;
    sp_result_matrix.columns = matrix_1.columns;

    //�������� ������ ��� c���������� ������ �����������
    sp_result_matrix.elements_value = calloc(sp_matrix_1.num_non_zero_elem + sp_matrix_2.num_non_zero_elem, sizeof(int));
    sp_result_matrix.column_index = calloc(sp_matrix_1.num_non_zero_elem + sp_matrix_2.num_non_zero_elem, sizeof(int));
    sp_result_matrix.line_index = calloc(sp_result_matrix.lines, 8);



    clock_t start, stop;


    printf("\n���������� ��������: %d", NUM_ITER);
    printf("\n����� ������ �������� ���������                ����� ������ ������������ ���������\n");
    //������� ��������
    double duration1=-1.0;
    start = clock();
    for (int i = 0; i < NUM_ITER; i++)
        addition_of_ordinary_matrices(&matrix_1, &matrix_2, &result_matrix);
    stop = clock();

    duration1=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("%20.10lf ������", (float)(duration1/NUM_ITER));


    //����������� ��������
    double duration2=-1.0;
    start = clock();
    for (int i = 0; i < NUM_ITER; i++)
        sp_result_matrix.num_non_zero_elem = addition_of_sparse_matrices(&sp_matrix_1, &sp_matrix_2, &sp_result_matrix, result_matrix.lines);
    stop = clock();

    duration2=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("%40.10lf ������", (float)(duration2/NUM_ITER));


    printf("\n\n������ �� �� ������� ��������� � \n1 - ������� ����\n2 - � ���� �������� �������� � �������� ��������\n3 - � ����� �����\n4 - �� �������� ���������\n�����: ");
    command = 0;
    code = other_number_input(&command);
    if (code == ok && (command > 4 || command < 1))
        code = input_error;
    while (code != ok)
    {
        printf("\n������������ ����.\n�����: ");
        code = other_number_input(&command);
        if (code == ok && (command > 4 || command < 1))
            code = input_error;
    }

    switch(command){
    case 1:
    {
        output_usual_matrices(&matrix_1, &matrix_2, &result_matrix);
        break;
    }
    case 2:
    {
        output_sparce_matrices(&sp_matrix_1, &sp_matrix_2, &sp_result_matrix);
        break;
    }
    case 3:
    {
        output_usual_matrices(&matrix_1, &matrix_2, &result_matrix);
        output_sparce_matrices(&sp_matrix_1, &sp_matrix_2, &sp_result_matrix);
        break;
    }
    case 4:
    {
        break;
    }
    }


    return code;

}
