#ifndef ADDITION_OF_MATRICES_H
#define ADDITION_OF_MATRICES_H

#include "structures.h"
void passage_of_line(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix, int *count_matrix_1, int *count_matrix_2, int *result_count, int *i);
void addition_of_ordinary_matrices(struct usual_matrix *matrix_1, struct usual_matrix *matrix_2, struct usual_matrix *result_matrix);
int addition_of_sparse_matrices(struct sparse_matrix *matrix_1, struct sparse_matrix *matrix_2, struct sparse_matrix *result_matrix, int size);
#endif // ADDITION_OF_MATRICES_H
