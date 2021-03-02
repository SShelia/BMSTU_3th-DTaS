#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include <stdio.h>
#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"

void count_for_file_dextra(FILE *f, int iter, int capital);
void count_for_file_bellman(FILE *f, int iter, int capital);
void check_efficience();

#endif // TIME_MEASUREMENT_H
