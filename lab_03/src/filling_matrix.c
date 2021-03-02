#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../inc/structures.h"
#include "../inc/errors.h"
#include "../inc/input_size_and_command.h"
#include <Windows.h>

//Обычное заполнение матрицы
int filling_matrix(struct usual_matrix *usual_matrix)
{
    setbuf(stdout, NULL);

    int num_non_zero_elem = 1;
    int code = ok;
    for (int i = 0; i < usual_matrix->lines; i++)
    {

        for (int j = 0; j < usual_matrix->columns; j++)
        {
            printf("Введите элемент строки %d, столбца %d (целое число): ", i + 1, j + 1);

            usual_matrix->matrix[i][j] = 0;
            code = number_input(&usual_matrix->matrix[i][j]);
            while (code != ok)
            {
                printf("\nНекорреткный ввод.Введите значение повторно: ");
                code = number_input(&usual_matrix->matrix[i][j]);

            }

            if (usual_matrix->matrix[i][j] != 0)
                num_non_zero_elem++;
        }
    }
    return num_non_zero_elem;
}

//Рандомное заполнение матрицы
int filling_matrix_random(struct usual_matrix *usual_matrix, int per_of_occupancy, int flag)
{

    srand(time(NULL) + flag);
    int num_non_zero_elem = 1;
    int check = 0;
    for (int i = 0; i < usual_matrix->lines; i++)
    {

        for (int j = 0; j < usual_matrix->columns; j++)
        {
            if ((check = rand()%(100)) >= per_of_occupancy)
                usual_matrix->matrix[i][j] = 0;
            else
            {
                num_non_zero_elem++;
                usual_matrix->matrix[i][j] = check + rand()%100;
            }
        }
    }
    return num_non_zero_elem;
}



//Перевод значений в разреженную матрицу
void filling_sparse_matrix(struct usual_matrix *usual_matrix, struct sparse_matrix *sparce_matrix)
{
    int k = 0;
    int p = 0;
    sparce_matrix->line_index[p] = -1;
    for (int i = 0; i < usual_matrix->lines; i++)
    {

        for (int j = 0; j < usual_matrix->columns; j++)
        {
            if (usual_matrix->matrix[i][j] != 0)
            {
                sparce_matrix->elements_value[k] = usual_matrix->matrix[i][j];
                sparce_matrix->column_index[k] = j;

                if (sparce_matrix->line_index[p] == -1)
                    sparce_matrix->line_index[p] = k;

                k++;
            }
        }

        p++;
        sparce_matrix->line_index[p] = -1;

    }
    sparce_matrix->elements_value[k] = -1;
    sparce_matrix->column_index[k] = -1;


    //Для доп элемента + 1
    sparce_matrix->lines = usual_matrix->lines + 1;

}
