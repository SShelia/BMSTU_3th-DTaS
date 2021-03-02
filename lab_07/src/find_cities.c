#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include "../inc/graph_matrix.h"
#include "../inc/graph_adjacency.h"

//������� ���������� �����
int find_number_edges(int **matrix_graph, int size)
{
    int edge = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if (i > j && matrix_graph[i][j] != INT_MAX)
                edge++;
    }
    return edge;
}

//����� ���������� �� ������� �������
void search_suitable_cities(int *array, int capital, int size, int max_distance)
{
    printf("\n�������� �������� �������: %d, ���������� ��� ���������: %d\n", capital, max_distance);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 1000)
            array[i] = 0;
        if (i != capital - 1 && array[i] > max_distance)
            printf("���������� �� ������ %d: %d\n", i + 1, array[i]);
        else if (i != capital - 1)
            printf("���������� �� ������ %d: %d (�� ��������)\n", i + 1, array[i]);
    }
}

//������� - �������
int *dextra_function_with_matrix(int **matrix, int capital, int size)
{
    //��������� ������ � ���������� ���� ����� � ���������� ������
    int *dextra_array = malloc(sizeof(int) * size);
    int *visited_peaks = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        if (i == capital - 1)
            dextra_array[i] = 0;
        else
            dextra_array[i] = 1000;
        visited_peaks[i] = 1;
    }

    int min_index = 1000 - 1;
    int min_value = 1000;
    int temp;

    //���� ���� ������������ �������
    while (min_index < 1000)
    {
        min_index = 1000;
        min_value = 1000;

        for (int i = 0; i < size; i++)
        {
            //���� ������� ����� ������������ ������ �����������
            if (visited_peaks[i] == 1 && dextra_array[i] < min_value)
            {
                min_value = dextra_array[i];
                min_index = i;
            }
        }

        if (min_index != 1000)
        {
            for (int j = 0; j < size; j++)
            {
                //���� �� �������������� ������� ���� ����
                if (visited_peaks[j] == 1 && matrix[min_index][j] > 0)
                {
                    //����� �������� ������������� ������� � ���� �� ��� � �����-���� ������ �������
                    temp = min_value + matrix[min_index][j];
                    if (temp < dextra_array[j])
                        dextra_array[j] = temp;
                }
            }
            visited_peaks[min_index] = 0;
        }
    }

    free(visited_peaks);

    return dextra_array;
}

//������� - ����
int *dextra_function_with_list(list_graph **list, int capital, int size)
{
    //��������� ������ � ���������� ���� ����� � ���������� ������
    int *dextra_array = malloc(sizeof(int) * size);
    int *visited_peaks = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        if (i == capital - 1)
            dextra_array[i] = 0;
        else
            dextra_array[i] = 1000;
        visited_peaks[i] = 1;
    }

    int min_index = 1000 - 1;
    int min_value = 1000;
    int temp;

    //���� ���� ������������ �������
    while (min_index < 1000)
    {
        min_index = 1000;
        min_value = 1000;

        for (int i = 0; i < size; i++)
        {
            //���� ������� ����� ������������ ������ �����������
            if (visited_peaks[i] == 1 && dextra_array[i] < min_value)
            {
                min_value = dextra_array[i];
                min_index = i;
            }
        }
        if (min_index != 1000)
        {

            for (list_graph *j = list[min_index]; j != NULL; j = j->next)
            {
                //���� �� �������������� ������� ���� ����
                if (visited_peaks[j->value] == 1)
                {
                  //����� �������� ������������� ������� � ���� �� ��� � �����-���� ������ �������
                  temp = min_value + j->path_length;
                  if (temp < dextra_array[j->value])
                    dextra_array[j->value] = temp;
                }
            }
            visited_peaks[min_index] = 0;
        }
    }

    free(visited_peaks);
    return dextra_array;
}

//������� �������
int *bellman_function_with_matrix(int **matrix, int capital, int size)
{
    int *bellman_array = malloc(sizeof(int) * size);

    //������ ��� ������
    for (int i = 0; i < size; i++)
        bellman_array[i] = 1000;
    bellman_array[capital - 1] = 0;

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (matrix[i][j] != 0)
                {
                    if (bellman_array[i] + matrix[i][j] < bellman_array[j])
                        bellman_array[j] = bellman_array[i] + matrix[i][j];
                }
             }
        }
    }
    return bellman_array;
}


//������� ������
int *bellman_function_with_list(list_graph **list, int capital, int size)
{
    int *bellman_array = malloc(sizeof(int) * size);

    //������ ��� ������
    for (int i = 0; i < size; i++)
        bellman_array[i] = 1000;
    bellman_array[capital - 1] = 0;

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; ++i)
        {
            for (list_graph *j  = list[i];  j != NULL; j = j->next)
            {

                if (bellman_array[i] + j->path_length < bellman_array[j->value])
                    bellman_array[j->value] = bellman_array[i] + j->path_length;
            }
        }
    }

    return bellman_array;
}
