#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../inc/find_cities.h"
#include "../inc/data_input.h"
#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"
#include "../inc/errors.h"

#define NUM_ITER 1000

//Подсчет для матрицы Дейкстра
double time_matrix_dextra(int **matrix, int iter, int size, int capital)
{
    clock_t start, stop;

    double all_time = 0;
    for (int i = 0; i < iter; i++)
    {
        start = clock();
        int *dextra_array = dextra_function_with_matrix(matrix, capital, size);
        stop = clock();
        all_time += stop - start;
        free(dextra_array);
    }

    return all_time / CLK_TCK / iter ;
}

//Подсчет для матрицы Беллман
double time_matrix_bellman(int **matrix, int iter, int size, int capital)
{
    clock_t start, stop;

    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        int *dextra_array = bellman_function_with_matrix(matrix, capital, size);
        stop = clock();
        all_time += stop - start;
        free(dextra_array);
    }

    return all_time / CLK_TCK / iter ;
}

//Подсчет для списка Декстра
double time_list_dextra(list_graph **list, int iter, int size, int capital)
{
    clock_t start, stop;

    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        int *dextra_array = dextra_function_with_list(list, capital, size);
        stop = clock();
        all_time += stop - start;
        free(dextra_array);
    }

    return all_time / CLK_TCK / iter ;
}


//Подсчет для списка Беллман
double time_list_bellman(list_graph **list, int iter, int size, int capital)
{
    clock_t start, stop;

    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        int *dextra_array = bellman_function_with_list(list, capital, size);
        stop = clock();
        all_time += stop - start;
        free(dextra_array);
    }

    return all_time / CLK_TCK / iter ;
}


void count_for_file_dextra(FILE *f, int iter, int capital)
{
    int size;
    matrix_graph_read_size(f, &size);

    list_graph **adj_graph;
    int **matrix_graph;

    adj_graph = malloc(size * sizeof(list_graph));
    graph_adj_init(adj_graph, size);
    matrix_graph = allocate_matrix(size, size);

    graph_file_read(f, adj_graph, matrix_graph, size);
    int edge = find_matrix_edge(matrix_graph, size);

    printf("%20.d|", size);
    printf("%20.d|", edge);
    printf("%19.10fs|", time_matrix_dextra(matrix_graph, iter, size, capital));
    printf("%19.10fs|", time_list_dextra(adj_graph, iter, size, capital));
    printf("\n");

    for (int i = 0; i < size; i++)
        destruct(&adj_graph[i]);
    free_matrix(matrix_graph, size);

}

void count_for_file_bellman(FILE *f, int iter, int capital)
{
    int size;
    matrix_graph_read_size(f, &size);

    list_graph **adj_graph;
    int **matrix_graph;

    adj_graph = malloc(size * sizeof(list_graph));
    graph_adj_init(adj_graph, size);
    matrix_graph = allocate_matrix(size, size);

    graph_file_read(f, adj_graph, matrix_graph, size);
    int edge = find_matrix_edge(matrix_graph, size);

    printf("%20.d|", size);
    printf("%20.d|", edge);
    printf("%19.10fs|", time_matrix_bellman(matrix_graph, iter, size, capital));
    printf("%19.10fs|", time_list_bellman(adj_graph, iter, size, capital));
    printf("\n");

    for (int i = 0; i < size; i++)
        destruct(&adj_graph[i]);
    free_matrix(matrix_graph, size);

}

//Проверка эффективнсти
void check_efficience()
{
    int iter = 10000;
    int capital = 3;

    printf("\nПроверка эффективности для поиска городов\n\n");
    printf("Дейкстра\n");
    printf("Количество вершин   |    Количество ребер|             Матрица|              Список|\n");
    printf("------------------------------------------------------------------------------------\n");

    FILE *f_01, *f_02, *f_03, *f_04, *f_05, *f_06, *f_07, *f_08;

    f_01 = fopen("efficience_01.txt", "r");
    count_for_file_dextra(f_01, iter, capital);
    fseek(f_01, 0, SEEK_SET);

    f_02 = fopen("efficience_02.txt", "r");
    count_for_file_dextra(f_02, iter, capital);
    fseek(f_02, 0, SEEK_SET);

    f_03 = fopen("efficience_03.txt", "r");
    count_for_file_dextra(f_03, iter, capital);
    fseek(f_03, 0, SEEK_SET);

    f_04 = fopen("efficience_04.txt", "r");
    count_for_file_dextra(f_04, iter, capital);
    fseek(f_04, 0, SEEK_SET);

    f_05 = fopen("efficience_05.txt", "r");
    count_for_file_dextra(f_05, iter, capital);
    fseek(f_05, 0, SEEK_SET);

    f_06 = fopen("efficience_06.txt", "r");
    count_for_file_dextra(f_06, iter, capital);
    fseek(f_06, 0, SEEK_SET);

    f_07 = fopen("efficience_07.txt", "r");
    count_for_file_dextra(f_07, iter, capital);
    fseek(f_07, 0, SEEK_SET);


    f_08 = fopen("efficience_08.txt", "r");
    count_for_file_dextra(f_08, iter, capital);
    fseek(f_08, 0, SEEK_SET);


    printf("Беллман\n");
    printf("Количество вершин   |    Количество ребер|             Матрица|              Список|\n");
    printf("------------------------------------------------------------------------------------\n");


    iter = 1000;
    count_for_file_bellman(f_01, iter, capital);
    fclose(f_01);
    count_for_file_bellman(f_02, iter, capital);
    fclose(f_02);
    count_for_file_bellman(f_03, iter, capital);
    fclose(f_03);
    count_for_file_bellman(f_04, iter, capital);
    fclose(f_04);
    count_for_file_bellman(f_05, iter, capital);
    fclose(f_05);
    count_for_file_bellman(f_06, iter, capital);
    fclose(f_06);
    count_for_file_bellman(f_07, iter, capital);
    fclose(f_07);
    count_for_file_bellman(f_08, iter, capital);
    fclose(f_08);

}

