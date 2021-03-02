#include <stdio.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/graph_matrix.h"


//Освобождпни памяти
void free_matrix(int **data, int lines)
{
    for (int i = 0; i < lines; i++)
        free(data[i]);
    free(data);
}

//Выделение памяти
int **allocate_matrix(int lines, int columns)
{
    int **data = calloc(lines, sizeof(int*));
    if (data != NULL)
    {
        int i = 0;
        while (i < lines)
        {
            data[i] = malloc(columns * sizeof(int));
            if (data[i] == NULL)
            {
                free_matrix(data, lines);
                break;
            }
            i++;
        }
    }
    return data;
}


//Подсчет кол-ва ребер
int find_matrix_edge(int **matrix, int size)
{
    int edge = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i > j && matrix[i][j] != 0)
                edge++;

        }
    }
    return edge;
}

