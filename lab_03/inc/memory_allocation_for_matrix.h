#ifndef MEMORY_ALLOCATION_FOR_MATRIX_H
#define MEMORY_ALLOCATION_FOR_MATRIX_H

int **allocate_matrix(int lines, int columns);
void free_matrix(int **data, int lines);

#endif // MEMORY_ALLOCATION_FOR_MATRIX_H
