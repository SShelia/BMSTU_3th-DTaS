#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include "../inc/graph_matrix.h"
#include "../inc/graph_adjacency.h"

void matrix_graph_file_print(FILE *f, int **matrix, int size, char *name);
void list_output(list_graph **list, int size);
void matrix_output(int **matrix, int size);
void output(int **matrix, int size);
void result_graph_file_print(FILE *f, int **matrix, int *result, int capital, int size, char *name);

#endif // OUTPUT_H


