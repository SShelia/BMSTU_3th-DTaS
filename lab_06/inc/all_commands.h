#ifndef ALL_COMMANDS_H
#define ALL_COMMANDS_H

#include "../inc/avl_tree.h"
#include "../inc/data_input.h"
#include "../inc/hash.h"
#include "../inc/usual_tree.h"
#include "../inc/errors.h"

void add_elem(tree_node **usual_tree, avl_tree_node **avl_tree, hash **hash, int *hash_key, int *collision);
void delete_elem(tree_node **usual_tree, avl_tree_node **avl_tree, hash **hash, int *hash_key, int *collision);

#endif
