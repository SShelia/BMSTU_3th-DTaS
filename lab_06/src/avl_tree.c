#include <stdio.h>
#include <stdlib.h>
#include "../inc/avl_tree.h"
#include "../inc/errors.h"

//Функции для png файла
void avl_tree_node_to_dot(struct avl_tree_node *tree, void *param)
{
    FILE *f = param;
    if (tree->left)
        fprintf(f, "%d -> %d;\n", tree->data, tree->left->data);
    if (tree->right)
        fprintf(f, "%d -> %d;\n", tree->data, tree->right->data);
    if (!tree->right && !tree->left)
        fprintf(f, "%d;\n", tree->data);
}

void avl_tree_btree_apply_pre(struct avl_tree_node *tree, ptr_action_avl f, void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    avl_tree_btree_apply_pre(tree->left, f, arg);
    avl_tree_btree_apply_pre(tree->right, f, arg);
}

void avl_tree_btree_export_to_dot(FILE *f, const char *tree_name, struct avl_tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
    avl_tree_btree_apply_pre(tree, avl_tree_node_to_dot, f);

    fprintf(f, "}\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------

//Создание одного узла
avl_tree_node *avl_tree_create_new_node(int value)
{
    avl_tree_node* tmp = (avl_tree_node*) malloc(sizeof(avl_tree_node));

    if (tmp != NULL)
    {
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->data = value;
        tmp->height = 0;
    }
    return tmp;
}

//Подсчёт высоты
int avl_tree_count_height(avl_tree_node *node)
{
    int height;
    if (node != NULL)
        height = node->height;
    else
        height = -1;
    return height + 1;
}

//Подсчет баланса
int avl_tree_count_balance(avl_tree_node *avl_node)
{
    int balance = avl_tree_count_height(avl_node->right) - avl_tree_count_height(avl_node->left);
    return balance;
}

//Изменение переменной высоты
void avl_tree_change_height(avl_tree_node *node)
{
    int left_height = avl_tree_count_height(node->left);
    int right_height = avl_tree_count_height(node->right);

    if (left_height - right_height > 0)
        node->height = left_height;
    else
        node->height = right_height;
}


//Поворот дерева направо
avl_tree_node* avl_tree_right_rotate(avl_tree_node *node)
{
    //Запоминаем левый узел
    avl_tree_node *tmp = node->left;
    //Левый узел исходного корня меняет значение на значение правого узла левого подузла
    node->left = tmp->right;
    //левый подузел становится новым корнем, правым подузлом которого является исходный корень
    tmp->right = node;

    avl_tree_change_height(node);
    avl_tree_change_height(tmp);
    return tmp;
}

//Поворот дерева налево
avl_tree_node* avl_tree_left_rotate(avl_tree_node *node)
{
    avl_tree_node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    avl_tree_change_height(node);
    avl_tree_change_height(tmp);
    return tmp;
}

//Балансировка
avl_tree_node *avl_tree_balance(avl_tree_node *node)
{
    avl_tree_change_height(node);

    //Если правое поддерево на два выше
    if (avl_tree_count_balance(node) == 2)
    {
        //Если у правого поддерева правая сторона короче - делаем поворот направо
        if (avl_tree_count_balance(node->right) < 0)
            node->right = avl_tree_right_rotate(node->right);
        node = avl_tree_left_rotate(node);
    }
    //Если правое дерево на два ниже
    if (avl_tree_count_balance(node) == -2)
    {
        if (avl_tree_count_balance(node->left) > 0 )
            node->left = avl_tree_left_rotate(node->left);
        node = avl_tree_right_rotate(node);
    }
    return node;
}

//Вставка элемента
int avl_tree_insert(avl_tree_node **tree, int data, int *comparisons)
{
    int code = all_ok;
    if (*tree == NULL)
    {

        *tree = avl_tree_create_new_node(data);
        if (*tree == NULL)
            code = memory_allocation_error;
    }
    else
    {
        if (data < (*tree)->data)
        {
            *comparisons += 1;
            avl_tree_insert(&(*tree)->left, data, comparisons);
            *tree = avl_tree_balance(*tree);
        }
        else if (data > (*tree)->data)
        {
            *comparisons += 1;
            avl_tree_insert(&(*tree)->right, data, comparisons);
            *tree = avl_tree_balance(*tree);
        }
        else
            code = same_elem;
    }
    *tree = avl_tree_balance(*tree);

    return code;
}

//Поиск элемента
avl_tree_node *avl_tree_find_node(avl_tree_node *root, int find_elem)
{
    //Поиск элемента
    while (root)
    {
        if (root->data > find_elem)
            root = root->left;
        else if (root->data < find_elem)
            root = root->right;
        else
            break;
    }
    return root;
}

//Поиск элемента для удаления
avl_tree_node *avl_tree_find_del_node(avl_tree_node *tree, avl_tree_node **parent, int find_elem, int *comparisons)
{
    while (tree)
    {
        if (tree->data > find_elem)
        {
            *parent = tree;
            tree = tree->left;
        }
        else if (tree->data < find_elem)
        {
            *parent = tree;
            tree = tree->right;
        }
        else
            break;
        *comparisons +=  1;
    }
    return tree;
}

//Удаление элемента из дерева
void avl_tree_delete(avl_tree_node *del_node, avl_tree_node **parent)
{

    //Если у узла нет наследников
    if (del_node->left == NULL && del_node->right == NULL)
    {
        if ((*parent)->left == del_node)
            (*parent)->left = NULL;
        else
            (*parent)->right = NULL;
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
        avl_tree_node *min_left_elem =  del_node->left;
        del_node->data = min_left_elem->data;
        avl_tree_delete(min_left_elem, &del_node);
    }
}

