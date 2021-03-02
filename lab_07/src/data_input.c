#include <stdio.h>
#include <limits.h>
#include <Windows.h>
#include "../inc/data_input.h"
#include "../inc/errors.h"
#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"

//Считвание числа
int number_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];

    while ((c = getchar()) <= 57 && c >= 48 )
    {
        array[i] = c - 48;
        i++;
    }
    if (c == '\n' && i == 0)
        code= input_error;

    else if (c != '\n')
    {
        while ((c = getchar()) != '\n');
        code= input_error;
    }
    else
    {
        i--;
        int pow = 1;
        for (; i >=0; i--)
        {
            *number+=array[i] * pow;
            pow*=10;
        }
    }
    return code;
}

//Ввод команды
int command_input(int min_size, int max_size)
{
    int code = ok;
    int command = 0;
    code = number_read(&command);

    if (command > max_size || command < min_size)
        code = input_error;

    while (code != ok)
    {
        printf("\nНекорректный ввод. Повторите ввод: ");
        command = 0;
        code = number_read(&command);
        if (command > max_size || command < min_size)
            code = input_error;;
    }
    return command;
}

//Считвание количества вершин графа
int matrix_graph_read_size(FILE *f, int *number)
{
    int code = ok;
    if (fscanf(f, "%d", number) != 1)
        code = input_error;
    return code;
}

//Проверка матрицы на симметричность
int check_matrix_symmetry(int **matrix, int size)
{
    int result = 1;
    for (int i = 0; i < size && result == 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != matrix[j][i] || (i == j && matrix[i][j] != 0))
            {
                result = 0;
                break;
            }
        }
    }
    return result;
}

//Чтение графа из файла
int graph_file_read(FILE *f, list_graph **list, int **matrix, int size)
{
    int result = ok;
    int number;

    for (int i = 0; i < size && result == ok; i++)
    {
        for (int j = 0; j < size && result == ok; j++)
        {
            if (fscanf(f, "%d", &number) != 1)
                result = input_error;

            else
            {
                if (number != 0)
                {
                    push_back(&list[i], number, j);
                    matrix[i][j] = number;
                }
                else
                   matrix[i][j] = 0;
            }
        }
    }
    return result;
}

//Заполнение списка ручной режим
int graph_user_read(list_graph **list, int **matrix, int *size)
{
    int code = ok;
    int number;

    for (int i = 0; i < *size && code == ok; i++)
    {
        for (int j = 0; j < *size && code == ok; j++)
        {
            if (scanf("%d", &number) != 1)
                code = input_error;

            else
            {
                if  (number != 0)
                {
                    push_back(&list[i], number, j);
                    matrix[i][j] = number;
                }
                else
                    matrix[i][j] = 0;

            }
        }
    }
    return code;
}



