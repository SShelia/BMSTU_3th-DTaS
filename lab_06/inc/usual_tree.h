#ifndef USUAL_TREE_H
#define USUAL_TREE_H

#include <stdio.h>

//Структура дерева
typedef struct tree_node
{
      int data;
      struct tree_node *left;
      struct tree_node *right;
      struct tree_node *parent;
}tree_node;

void usual_tree_node_to_dot(struct tree_node *tree, void *param);
typedef void (*ptr_action_usual)(struct tree_node*, void*);
void usual_tree_btree_apply_pre(struct tree_node *tree, ptr_action_usual f, void *arg);
void usual_tree_btree_export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree);
tree_node *usual_tree_create_node(int data);

int usual_tree_insert(tree_node **tree, int data, int *comparisons);
tree_node *usual_tree_find_node(tree_node *root, int find_elem, int *comparisons);

tree_node *usual_tree_find_left_min(tree_node *tree);
void usual_tree_delete_node(tree_node *del_node);
void usual_tree_apply_in(struct tree_node *tree);
void usual_tree_destroy(tree_node *tree);

#endif // USUAL_TREE_H
