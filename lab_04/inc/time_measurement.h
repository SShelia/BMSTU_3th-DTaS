#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H


#include "stack_as_linked_list.h"
#include "stack_as_static_array.h"
void time_measurement();

void prosec_stack_ll_for_time(Stack_ll *stack_ll);
void prosec_stack_sa_for_time(Stack_sa *stack_sa);
#endif // TIME_MEASUREMENT_H
