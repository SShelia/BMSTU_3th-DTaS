#ifndef NUMBER_NORMALLIZATION_H
#define NUMBER_NORMALLIZATION_H

#include "typedefs_and_struct.h"

void number_normalization(struct number *number_structure, int *len_order);
void number_normalization_2(struct number *number_structure, int *len_order);
void shift_point(struct number *number_structure, int *len_mantisa);

#endif // NUMBER_NORMALLIZATION_H
