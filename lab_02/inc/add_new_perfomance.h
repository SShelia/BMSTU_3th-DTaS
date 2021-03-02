#ifndef ADD_NEW_PERFOMANCE_H
#define ADD_NEW_PERFOMANCE_H

#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <Windows.h>
#include <conio.h>

int add_new_theatre(struct repertoire_of_theatres *theatres, int *number_of_perfomance);
void str_normallization(char *str);
int str_input(char *new_str, int len);
int number_input(int *number);

#endif // ADD_NEW_PERFOMANCE_H
