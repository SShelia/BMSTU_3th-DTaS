#include <stdio.h>

#include <Windows.h>
#include "../inc/structures.h"

void output_usual_matrices(struct usual_matrix *matrix_1, struct usual_matrix *matrix_2, struct usual_matrix *result_matrix)
{
    printf("\nМатрица 1:\n");
    for (int i = 0; i < matrix_1->lines; i++)
    {
        for (int j = 0; j < matrix_1->columns; j++)
            printf("%d ", matrix_1->matrix[i][j]);
        printf("\n");
    }

    printf("\nМатрица 2:\n");
    for (int i = 0; i < matrix_2->lines; i++)
    {
        for (int j = 0; j < matrix_2->columns; j++)
            printf("%d ", matrix_2->matrix[i][j]);
        printf("\n");
    }

    printf("\nМатрица результат:\n");
    for (int i = 0; i < result_matrix->lines; i++)
    {
        for (int j = 0; j < result_matrix->columns; j++)
            printf("%d ", result_matrix->matrix[i][j]);
        printf("\n");
    }
}

void output_sparce_matrices(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix)
{
    //printf("\nЗначение -1 в 3 массиве-результате означает, что в данной строке нет элементов. (или строка начинается с элемента -1)\n");
    printf("                        ");
    printf("Значение ненулевых элементов первой матрицы: ");
    for (int i = 0; i < matrix_1->num_non_zero_elem - 1; i++)
        printf("%d ", matrix_1->elements_value[i]);


    printf("\nСоответствующие индексы столбцов ненулевых элементов первой матрицы: ");
    for (int i = 0; i < matrix_1->num_non_zero_elem - 1; i++)
        printf("%d ", matrix_1->column_index[i]);



    printf("\n                     Индексы элементов, с которых начинаются строки: ");
    for (int i = 0; i < matrix_1->lines - 1 ; i++)
        printf("%d ", matrix_1->line_index[i]);


    printf("\n\n                        ");
    printf("Значение ненулевых элементов второй матрицы: ");
    for (int i = 0; i < matrix_2->num_non_zero_elem - 1; i++)
        printf("%d ", matrix_2->elements_value[i]);


    printf("\nСоответствующие индексы столбцов ненулевых элементов второй матрицы: ");
    for (int i = 0; i < matrix_2->num_non_zero_elem - 1;  i++)
        printf("%d ", matrix_2->column_index[i]);


    printf("\n                     Индексы элементов, с которых начинаются строки: ");
    for (int i = 0; i < matrix_2->lines - 1; i++)
        printf("%d ", matrix_2->line_index[i]);


    printf("\n\n                        ");
    printf("  Значение ненулевых элементов в результате: ");
    for (int i = 0; i < result_matrix->num_non_zero_elem - 1; i++)
        printf("%d ", result_matrix->elements_value[i]);


    printf("\n  Соответствующие индексы столбцов ненулевых элементов в результате: ");
    for (int i = 0; i < result_matrix->num_non_zero_elem - 1; i++)
        printf("%d ", result_matrix->column_index[i]);


    printf("\n                     Индексы элементов, с которых начинаются строки: ");
    for (int i = 0; i < result_matrix->lines - 1; i++)
        printf("%d ", result_matrix->line_index[i]);
    printf("\n");


}
