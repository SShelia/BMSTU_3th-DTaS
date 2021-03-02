#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>



/*
typedef struct linked_list
{
    //Блок данных
    int index_line_begin;

    //Указатель на следующую такую структуру
    struct linked_list *next;
}t_list;
*/

struct sparse_matrix{
    int lines;
    int columns;
    int num_non_zero_elem;

    int *elements_value;
    int *column_index;
    int *line_index;
};


struct usual_matrix{
    int **matrix;
    int lines;
    int columns;

};


#endif // STRUCTURES_H
