#ifndef DATA_INPUT_H
#define DATA_INPUT_H

#include <stdio.h>
#include "graph_matrix.h"
#include "graph_adjacency.h"

int command_input(int min_size, int max_size);
int number_read(int *number);
int matrix_graph_read_size(FILE *f, int *number);
int graph_user_read(list_graph **array, int **matrix_graph, int *size);
int graph_file_read(FILE *f, list_graph **array, int **matrix_graph, int size);
int check_matrix_symmetry(int **matrix_graph, int size);

#endif // DATA_INPUT_H
