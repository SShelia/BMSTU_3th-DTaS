#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "struct.h"
#include "sort.h"

void output_sort_array_keys_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance);
void output_sort_array_keys(struct repertoire_of_theatres *theatres, int number_of_perfomance);
void output_by_keys(struct repertoire_of_theatres *theatres, int num_of_elements, int *keys);
void output_of_structire_by_variant(struct repertoire_of_theatres *theatres, int variant_age, int variant_duration);
void output_of_structure_fields(struct repertoire_of_theatres *theatres, int num_of_elements);
int compare(const void *val_1, const void *val_2);
int key_compare(const void *val_1, const void *val_2);




#endif // OUTPUT_H
