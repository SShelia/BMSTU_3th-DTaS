#ifndef FILLING_MATRIX_H
#define FILLING_MATRIX_H

#include "structures.h"

int filling_matrix_random(struct usual_matrix *usual_matrix, int per_of_occupancy, int flag);
int filling_matrix(struct usual_matrix *usual_matrix);
void filling_sparse_matrix(struct usual_matrix *usual_matrix, struct sparse_matrix *sparce_matrix);
#endif // FILLING_MATRIX_H
