#include <stdio.h>
#include <Windows.h>

#include "../inc/output.h"
#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"

void matrix_graph_file_print(FILE *f, int **matrix, int size, char *name)
{
    fprintf(f, "digraph %s {\nrankdir=LR\n", name);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i < j && matrix[i][j] != 0)
                fprintf(f, "%d -> %d[label = %d, arrowhead = none]\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    fprintf(f, "}\n");
}

void result_graph_file_print(FILE *f, int **matrix, int *result, int capital, int size, char *name)
{
    fprintf(f, "digraph %s {\nrankdir=LR\n", name);

    fprintf(f, "digraph %s {\nrankdir=LR\n", name);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i < j && matrix[i][j] != 0)
                fprintf(f, "%d -> %d[label = %d, arrowhead = none]\n", i + 1, j + 1, matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        int temp = i;
        for (int j = 0; j < size; j++)
        {
          ;
        }
    }

    fprintf(f, "}\n");
}


//Вывод матрицы
void matrix_output(int **matrix, int size)
{
    printf("\nГраф в виде матрицы:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((matrix[i][j] != 0))
                printf("Вершина %d <-> %d = %d\n", i + 1, j + 1, matrix[i][j]);
        }
    }
}

//Вывод связного списка
void list_output(list_graph **list, int size)
{
    printf("\nГраф в виде списка:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Вершина %d -> ", i + 1);
        for (list_graph *j = list[i]; j != NULL; j = j->next)
            printf("%d(%d) -> ", j->value + 1, j->path_length);
        printf("NULL\n");
    }
}

void output(int **matrix, int size)
{
    printf("\nМатрица смежности:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
