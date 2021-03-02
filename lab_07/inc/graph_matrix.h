#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

int **allocate_matrix(int lines, int columns);
void free_matrix(int **data, int lines);
int find_matrix_edge(int **matrix, int size);

#endif // GRAPH_MATRIX_H
