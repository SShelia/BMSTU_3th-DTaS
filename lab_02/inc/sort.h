#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <Windows.h>
#include <time.h>

void sort_array_keys(struct repertoire_of_theatres *theatres, int number_of_perfomance, int *keys);
void sort_full_table(struct repertoire_of_theatres *theatres, int number_of_perfomance);
void sort_full_table_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance);
void sort_array_keys_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance, int *keys);

typedef struct repertoire_of_theatres rep_of_theatres;
typedef struct struct_for_sort sort;

typedef int (*comp)(const void *, const void *);
typedef int (*key_comp)(const void *, const void *);


#endif // SORT_H
