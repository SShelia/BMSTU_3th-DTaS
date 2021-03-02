#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
//Структура дерева
typedef struct avl_tree_node
{
    int data;
    int height;
    struct avl_tree_node *left;
    struct avl_tree_node *right;

}avl_tree_node;

void avl_tree_node_to_dot(struct avl_tree_node *tree, void *param);
typedef void (*ptr_action_avl)(struct avl_tree_node*, void*);
void avl_tree_btree_apply_pre(struct avl_tree_node *tree, ptr_action_avl f, void *arg);
void avl_tree_btree_export_to_dot(FILE *f, const char *tree_name, struct avl_tree_node *tree);

avl_tree_node *avl_tree_find_node(avl_tree_node *root, int find_elem);
avl_tree_node *avl_tree_create_new_node(int value);
int avl_tree_count_height(avl_tree_node *node);
int avl_tree_count_balance(avl_tree_node *avl_node);
void avl_tree_change_height(avl_tree_node *node);
avl_tree_node* avl_tree_right_rotate(avl_tree_node *node);
avl_tree_node* avl_tree_left_rotate(avl_tree_node *node);
avl_tree_node *avl_tree_balance(avl_tree_node *node);

int avl_tree_insert(avl_tree_node **tree, int data, int *comparisons);
avl_tree_node *avl_tree_find_del_node(avl_tree_node *tree, avl_tree_node **parent, int find_elem, int *comparisons);

void avl_tree_delete(avl_tree_node *del_node, avl_tree_node **parent);

#endif // AVL_TREE_H
