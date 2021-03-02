#include <stdio.h>
#include <Windows.h>

#include "../inc/all_commands.h"
#include "../inc/avl_tree.h"
#include "../inc/data_input.h"
#include "../inc/hash.h"
#include "../inc/usual_tree.h"
#include "../inc/errors.h"


//Добавление во все структуры
void add_elem(tree_node **usual_tree, avl_tree_node **avl_tree, hash **hash, int *hash_key, int *collision)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int code = all_ok;

    //Инициализация новой хэш-таблицы на случай реструктуризации
    struct hash *new_hash_table[MAX_SIZE];
    hash_init(new_hash_table);

    //Ввод значения для добавления
    printf("\nВведите целое число - значение элемента для добавления: ");
    int number = number_for_add_input();

    int  usual_comparisons = 0;
    code = usual_tree_insert(usual_tree, number, &usual_comparisons);

    if (code == memory_allocation_error)
        printf("Ошибка выделения памяти при добавлении в обычное дерево\n");
    else if (code == same_elem)
        printf("Такое число уже присутствует в структурах!");

    else
    {
        int  avl_comparisons = 0;
        avl_tree_insert(avl_tree, number, &avl_comparisons);

        int hash_comparisons = 0;
        int result = hash_insert_in_table(hash, number, *hash_key, *collision, &hash_comparisons);
        if (result == change_hash_key)
            hash_restruct(hash, new_hash_table, hash_key,collision);

        printf("Добавление прошло успешно!\n");
        printf("Для обычного дерева понадобилось: %d сравн.\n", usual_comparisons + 1);
        printf("Для AVL-дерева понадобилось: %d сравн.\n", avl_comparisons + 1);
        printf("Для хеш-таблицы понадобилось: %d сравн.\n", hash_comparisons);


    }
}

//Удаление из всех структур
void delete_elem(tree_node **usual_tree, avl_tree_node **avl_tree, hash **hash, int *hash_key, int *collision)
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Инициализация новой хэш-таблицы на случай реструктуризации
    struct hash *new_hash_table[MAX_SIZE];
    hash_init(new_hash_table);

    //Ввод значения для удаления
    printf("\nВведите целое число - значение элемента для удаления: ");
    int number = number_for_add_input();

    if (*usual_tree != NULL)
    {
        int  usual_comparisons = 0;
        tree_node *del_elem = usual_tree_find_node(*usual_tree, number, &usual_comparisons);
        if (del_elem == NULL)
            printf("Элемент с таким значением отсутсвует.\n");
        else
        {
            int  avl_comparisons = 0;
            avl_tree_node *tmp = NULL;
            avl_tree_node *avl_del_elem = avl_tree_find_del_node(*avl_tree, &tmp, number, &avl_comparisons);

            //Если узел - корень без наследников
            if (del_elem->parent == NULL && del_elem->left == NULL && del_elem->right == NULL)
            {
                free(del_elem);
                *usual_tree = NULL;

                free(avl_del_elem);
                *avl_tree = NULL;
            }
            else
            {
                usual_tree_delete_node(del_elem);
                avl_tree_delete(avl_del_elem, &tmp);
            }

            int hash_comparisons = 0;
            int result = hash_remove_in_table(hash, number, *hash_key, *collision, &hash_comparisons);
            if (result == change_hash_key)
                hash_restruct(hash, new_hash_table, hash_key, collision);

            printf("Удаление прошло успешно!\n");
            printf("Для обычного дерева понадобилось: %d сравн.\n", usual_comparisons + 1);
            printf("Для AVL-дерева понадобилось: %d сравн.\n", avl_comparisons + 1);
            printf("Для хеш-таблицы понадобилось: %d сравн.\n", hash_comparisons);


        }
    }
    else
        printf("Попытка удаления из пустых структур!\n");
}


