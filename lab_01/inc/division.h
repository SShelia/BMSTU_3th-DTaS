#ifndef DIVISION_H
#define DIVISION_H

#include "typedefs_and_struct.h"

int division(struct number *dividend, struct number *divider,struct number *result, int *size_of_dividend_mantisa, int *size_of_divider_mantisa,int *size_of_result_mantisa);
int multiplication_by_number(struct number *divider, int multiplier, int *result, int size_of_divider_mantisa);
int comparison_with_the_result_of_multiplication(struct number *dividend, int *result, int begin, int end);
int subtraction(struct number *divider, int *result, int action_length);
int compare_the_numbers(struct number *dividend, struct number *divider, int begin, int end);

#endif // DIVISION_H
