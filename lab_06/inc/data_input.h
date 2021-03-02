#ifndef DATA_INPUT_H
#define DATA_INPUT_H

#include <stdio.h>

#include "avl_tree.h"
#include "hash.h"
#include "usual_tree.h"

int number_read(int *number);
int command_input(int min_size, int max_size);
int number_for_add_read(int *number);
int number_for_add_input();
void read_file(FILE *f, tree_node **tree, avl_tree_node **avl_tree, hash **hash_table, int *hash_key, int *collision);
int read_int_number(FILE *f, int *number);
void usual_tree_apply_in(struct tree_node *tree);

#endif // DATA_INPUT_H
