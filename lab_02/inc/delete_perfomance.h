#ifndef DELETE_PERFOMANCE_H
#define DELETE_PERFOMANCE_H

#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <Windows.h>

void delete_perfomance(struct repertoire_of_theatres *theatres, int *number_of_perfomance);
void str_normallization(char *str);
int number_read(int *number);
int str_read(char *str, int len_of_str);
int str_input(char *new_str, int len);
int number_input(int *number);


#endif // DELETE_PERFOMANCE_H
