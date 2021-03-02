#include <stdio.h>
#include <stdlib.h>

#include "../inc/structures.h"

void output_sparce_matrices(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix);

//Обычное сложение матриц
void addition_of_ordinary_matrices(struct usual_matrix *matrix_1, struct usual_matrix *matrix_2, struct usual_matrix *result_matrix)
{
    for (int i = 0; i < result_matrix->lines; i++)
    {
        for (int j = 0; j < result_matrix->columns; j++)
            result_matrix->matrix[i][j] = matrix_1->matrix[i][j] + matrix_2->matrix[i][j];

    }
}


//Добавление числа
void add_items(struct sparse_matrix *result_matrix, struct sparse_matrix *matrix, int *result_count, int *count, int *line_index_result_count)
{
    //Добавление
    result_matrix->elements_value[*result_count] = matrix->elements_value[*count];
    result_matrix->column_index[*result_count] = matrix->column_index[*count];

    //Добавление указателя
    if (result_matrix->line_index[*line_index_result_count] == -1)
        result_matrix->line_index[*line_index_result_count] = *result_count;
    *result_count += 1;

}


//matrix_1 > matrix_2 Поиск пары
void find_the_pairs(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix, int *result_count, int *count_matrix_1, int *count_matrix_2, int *second_matrix_line_end, int *line_index_result_count)
{
    //Если столбец с данным индексом отсутствует, то добавляем значение || result_matrix->column_index[*result_count - 1] < matrix_2->column_index[*count_matrix_2]
    if (result_matrix->line_index[*line_index_result_count] == -1)
    {

        add_items(result_matrix, matrix_2, result_count, count_matrix_2, line_index_result_count);
        *count_matrix_2 += 1;
    }

    //Поиск пары

    while (matrix_2->column_index[*count_matrix_2] < matrix_1->column_index[*count_matrix_1] && *count_matrix_2 < *second_matrix_line_end)
    {
        if (result_matrix->column_index[*result_count - 1] < matrix_2->column_index[*count_matrix_2])
            add_items(result_matrix, matrix_2, result_count, count_matrix_2, line_index_result_count);
        *count_matrix_2+=1;
    }

    //Если не нашлось пары и столбец с данным индексом отсутствует просто добавляем элемент
    if ( *count_matrix_2 >= *second_matrix_line_end || matrix_2->column_index[*count_matrix_2] > matrix_1->column_index[*count_matrix_1])
    {
        add_items(result_matrix, matrix_1, result_count, count_matrix_1, line_index_result_count);
        *count_matrix_1+=1;
    }

    //Если пара нашлась добавляем сумму
    else
    {
        result_matrix->elements_value[*result_count] = matrix_1->elements_value[*count_matrix_1] + matrix_2->elements_value[*count_matrix_2];
        result_matrix->column_index[*result_count] = matrix_1->column_index[*count_matrix_1];
        if (result_matrix->line_index[*line_index_result_count] == -1)
            result_matrix->line_index[*line_index_result_count] = *result_count;
        *count_matrix_2+=1;
        *count_matrix_1+=1;
        *result_count += 1;
    }


}

//Проход по строке
void passage_of_line(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix, int *count_matrix_1, int *count_matrix_2,
                     int *first_matrix_line_end, int *second_matrix_line_end, int *result_count, int *line_index_result_count)
{
    //Пока не дойдем до начала следующей строки
    while (*count_matrix_1 < *first_matrix_line_end && *count_matrix_2 < *second_matrix_line_end)
    {
        //Если элементы в одной строчке и столбце
        if (matrix_1->column_index[*count_matrix_1] == matrix_2->column_index[*count_matrix_2])
        {
            result_matrix->elements_value[*result_count] = matrix_1->elements_value[*count_matrix_1] + matrix_2->elements_value[*count_matrix_2];
            result_matrix->column_index[*result_count] = matrix_1->column_index[*count_matrix_1];
            if (result_matrix->line_index[*line_index_result_count] == -1)
                result_matrix->line_index[*line_index_result_count] = *result_count;
            *result_count+=1;
            *count_matrix_1 += 1;
            *count_matrix_2 += 1;
        }

        else if (matrix_1->column_index[*count_matrix_1] < matrix_2->column_index[*count_matrix_2])
        {
           find_the_pairs(matrix_2, matrix_1, result_matrix, result_count, count_matrix_2, count_matrix_1,  first_matrix_line_end, line_index_result_count);
        }

        else if (matrix_1->column_index[*count_matrix_1] > matrix_2->column_index[*count_matrix_2])
        {
           find_the_pairs(matrix_1, matrix_2, result_matrix, result_count, count_matrix_1, count_matrix_2,  second_matrix_line_end, line_index_result_count);

        }

    }

    //Разбираемся с остатками
    while (*count_matrix_2 < *second_matrix_line_end)
    {
        add_items(result_matrix, matrix_2, result_count, count_matrix_2, line_index_result_count);
        *count_matrix_2 += 1;
    }

    //Разбираемся с остатками
    while (*count_matrix_1 < *first_matrix_line_end)
    {
        add_items(result_matrix, matrix_1, result_count, count_matrix_1, line_index_result_count);
        *count_matrix_1 += 1;
    }

}


//Для случая когда все нули
void zero_case(struct sparse_matrix *matrix, struct sparse_matrix *result_matrix, int line_index_count, int *result_count, int *matrix_count, int i)
{
    result_matrix->line_index[line_index_count] = *result_count;

    //Поиск конца строки матрицы
    int v = i + 1;
    while (matrix->line_index[v] == -1 && v < matrix->lines - 1)
        v++;

    if (v == matrix->lines - 1)
        v =  matrix->num_non_zero_elem - 1;
    else
        v = matrix->line_index[v];


    //Проход по строке матрицы
    for (; *matrix_count < v; *matrix_count+=1)
    {
        result_matrix->elements_value[*result_count] = matrix->elements_value[*matrix_count];
        result_matrix->column_index[*result_count] = matrix->column_index[*matrix_count];
        *result_count += 1;
    }

}

int addition_of_sparse_matrices(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix, int size)
{
    //Инициализирцем указатели матрицы результата на строки нулями
    for (int i = 0; i < size + 1; i++)
        result_matrix->line_index[i] =  -1;

    //Счётчик элементов в матрице - результате
    int result_count = 0;
    int line_index_count = 0;

    //Счетчик элементов
    int count_matrix_1 = 0;
    int count_matrix_2 = 0;

    //Идем по строкам
    for (int i = 0; i < matrix_1->lines - 1; i++)
    {

        //В строке первой матрицы все 0
        if (matrix_1->line_index[i] == -1 && matrix_2->line_index[i] != -1)
            zero_case(matrix_2, result_matrix, line_index_count, &result_count, &count_matrix_2, i);

        //В строке второй матрицы все 0
        else if (matrix_2->line_index[i] == -1 && matrix_1->line_index[i] != -1)
            zero_case(matrix_1, result_matrix, line_index_count, &result_count, &count_matrix_1, i);

        //В обоих строках все нули
        else if (matrix_2->line_index[i] == -1 && matrix_1->line_index[i] == -1)
        {
            result_matrix->line_index[line_index_count] = -1;
        }

        //В обоих строках есть числа
        else
        {
            //Поиск конца строки первой матрицы
            int v1 = i + 1;
            while (matrix_1->line_index[v1] == -1 && v1 < matrix_1->lines - 1)
                v1++;

            if (v1 == matrix_1->lines - 1)
                v1 =  matrix_1->num_non_zero_elem - 1;
            else
                v1 = matrix_1->line_index[v1];

            //Поиск конца строки второй матрицы
            int v2 = i + 1;
            while (matrix_2->line_index[v2] == -1 && v2 < matrix_2->lines - 1)
                v2++;

            if (v2 == matrix_2->lines - 1)
                v2 =  matrix_2->num_non_zero_elem - 1;
            else
                v2 = matrix_2->line_index[v2];


            //Определяем в какой матрице в данной строке больше элементов
            if (v1 - count_matrix_1 > v2 - count_matrix_2)
                passage_of_line(matrix_1, matrix_2, result_matrix, &count_matrix_1, &count_matrix_2, &v1, &v2, &result_count, &line_index_count);

            else
                passage_of_line(matrix_2, matrix_1, result_matrix, &count_matrix_2, &count_matrix_1, &v2, &v1, &result_count, &line_index_count);
        }

        line_index_count++;

    }

    return result_count + 1;
}
