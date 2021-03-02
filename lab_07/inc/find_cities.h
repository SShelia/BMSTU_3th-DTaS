#ifndef FIND_CITIES_H
#define FIND_CITIES_H

#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"

int *dextra_function_with_matrix(int **matrix, int capital, int size);
int *bellman_function_with_matrix(int **matrix, int capital, int size);
int *dextra_function_with_list(list_graph **graph, int capital, int size);
int *bellman_function_with_list(list_graph **graph, int capital, int size);
void search_suitable_cities(int *array, int capital, int size, int max_distance);
int find_number_edges(int **matrix, int size);



#endif // FIND_CITIES_H
