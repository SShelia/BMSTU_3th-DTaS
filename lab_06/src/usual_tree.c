#include <stdio.h>
#include <stdlib.h>
#include "../inc/usual_tree.h"
#include "../inc/errors.h"

//Функции для png файла
void usual_tree_node_to_dot(struct tree_node *tree, void *param)
{
    FILE *f = param;
    if (tree->left)
        fprintf(f, "%d -> %d;\n", tree->data, tree->left->data);
    if (tree->right)
        fprintf(f, "%d -> %d;\n", tree->data, tree->right->data);
    if (!tree->right && !tree->left)
        fprintf(f, "%d;\n", tree->data);
}

void usual_tree_btree_apply_pre(struct tree_node *tree, ptr_action_usual f, void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    usual_tree_btree_apply_pre(tree->left, f, arg);
    usual_tree_btree_apply_pre(tree->right, f, arg);
}

void usual_tree_btree_export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
    usual_tree_btree_apply_pre(tree, usual_tree_node_to_dot, f);

    fprintf(f, "}\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------


//Обход дерева
void usual_tree_apply_in(struct tree_node *tree)
{
     if (tree == NULL)
            return;

    //in-order
    usual_tree_apply_in(tree->left);

    usual_tree_apply_in(tree->right);
    printf("%d ", tree->data);
}

//Создание одного элемента
tree_node *usual_tree_create_node(int data)
{
    tree_node *new_elem = malloc(sizeof(tree_node));

    if (new_elem != NULL)
    {
        new_elem->data = data;
        new_elem->left = NULL;
        new_elem->right = NULL;
        new_elem->parent = NULL;
    }
    return new_elem;
}

//Рекурсивное добавление элемента в дерево
int usual_tree_insert(tree_node **tree, int data, int *comparisons)
{
    int code = all_ok;

    if (*tree == NULL)
    {
        tree_node *tmp = usual_tree_create_node(data);
        if (tmp != NULL)
            *tree = tmp;
        else
            code = memory_allocation_error;
    }
    else
    {
        tree_node *tmp = *tree;
        if (data < (*tree)->data)
        {
            *comparisons += 1;
            usual_tree_insert(&(*tree)->left, data, comparisons);
            (*tree)->left->parent = tmp;
        }
        else if (data > (*tree)->data)
        {
            *comparisons += 1;
            usual_tree_insert(&(*tree)->right, data, comparisons);
            (*tree)->right->parent = tmp;
        }

        //Если такой элемент уже существует
        else
            code = same_elem;
    }
    return code;
}


//Поиск левого минимума в дереве
tree_node *usual_tree_find_left_min(tree_node *tree)
{
    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

//Поиск правого максимума в дереве
tree_node *usual_tree_find_right_max(tree_node *tree)
{
    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

//Поиск элемента
tree_node *usual_tree_find_node(tree_node *root, int find_elem, int *comparisons)
{
    //Поиск элемента
    while (root)
    {
        if (root->data > find_elem)
            root = root->left;
        else if (root->data < find_elem)
            root =root->right;
        else
            break;
        *comparisons += 1;
    }
    return root;
}

//Удаление узла (предполагается, что он сущетсвует)
void usual_tree_delete_node(tree_node *del_node)
{

    //Если у узла нет наследников
    if (del_node->left == NULL && del_node->right == NULL)
    {
        if (del_node->parent->left == del_node)
            del_node->parent->left = NULL;
        else
            del_node->parent->right = NULL;
        free(del_node);
    }

    //Если у узла один правый наследник
    else if (del_node->left == NULL && del_node->right != NULL)
    {
        del_node->data = del_node->right->data;
        free(del_node->right);
        del_node->right = NULL;
    }

    //Если у узла один левый наследник
    else if (del_node->left != NULL && del_node->right == NULL)
    {
        del_node->data = del_node->left->data;
        free(del_node->left);
        del_node->left = NULL;
    }

    //Если у узла два наследника
    else
    {
        tree_node *max_left_elem = usual_tree_find_right_max(del_node->left);
        del_node->data = max_left_elem->data;
        usual_tree_delete_node(max_left_elem);
    }

}

//Разрушение
void usual_tree_destroy(tree_node *tree)
{
    if (tree == NULL)
        return;

   usual_tree_destroy(tree->left);
   usual_tree_destroy(tree->right);
   free(tree);

}
