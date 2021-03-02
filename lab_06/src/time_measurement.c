#include <stdio.h>
#include <time.h>

#include "../inc/avl_tree.h"
#include "../inc/data_input.h"
#include "../inc/hash.h"
#include "../inc/usual_tree.h"
#include "../inc/errors.h"

#define NUM_ITER 1000

//Подсчет для обычного дерева
double usual_tree_count_time(tree_node *tree, int iter, int n)
{
    int compar = 0;
    clock_t start, stop;
    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        for (int j = 0; j < n + 1; j++)
        {
            usual_tree_find_node(tree, j, &compar);
            compar = 0;
        }
        stop = clock();

        all_time += stop - start;
    }

    return all_time / CLK_TCK / iter ;
}

//Подсчет для avl-дерева
double avl_tree_count_time(avl_tree_node *tree, int iter, int n)
{

    clock_t start, stop;
    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        for (int j = 0; j < n + 1; j++)
            avl_tree_find_node(tree, j);
        stop = clock();

        all_time += stop - start;
    }

    return all_time / CLK_TCK / iter;
}


//Подсчет для хэш-таблицы
double hash_count_time(hash **hash_table, int *key, int *collision, int *code, int iter, int n)
{clock_t start, stop;
    double all_time = 0;

    for (int i = 0; i < iter; i++)
    {
        start = clock();
        for (int j = 0; j < n + 1; j++)
            hash_find_in_table(hash_table, j, *key, *collision, code);
        stop = clock();

        all_time += stop - start;
    }

    return all_time / CLK_TCK / iter ;

    return (stop - start) / CLK_TCK / iter;
}

//Подсчет для файла
double file_count_time(FILE *f, int iter, int n)
{
    clock_t start, stop;
    double all_time = 0;

    int number = 0;
    for (int i = 0; i < 100; i++)
    {
        start = clock();
        for (int j = 0; j < n + 1; j++)
            fscanf(f, "%d", &number);
        stop = clock();
        all_time += stop - start;
        fseek(f, 0, SEEK_SET);
    }

    return all_time / CLK_TCK / iter ;

    return (stop - start) / CLK_TCK / iter ;
}


void count_for_file(FILE *f, int n, tree_node **tree, avl_tree_node **avl_tree, hash **hash, int hash_key, int collision)
{
    read_file(f, tree, avl_tree, hash, &hash_key, &collision);


    int code = ok;
    printf("%20.10f|", usual_tree_count_time(*tree, NUM_ITER, n));
    printf("%20.10f|", avl_tree_count_time(*avl_tree, NUM_ITER, n));
    printf("%20.10f|", hash_count_time(hash, &collision, &hash_key, &code, NUM_ITER, n));
    printf("%20.10f|\n", file_count_time(f, NUM_ITER, n));

    fclose(f);

    fseek(f, 0, SEEK_SET);
}


//Проверка эффективнсти
void check_efficience(int hash_key, int collision)
{

    tree_node *tree = NULL;
    avl_tree_node *avl_tree = NULL;

    hash *hash[MAX_SIZE];
    hash_init(hash);

    printf("\nПроверка эффектичности для поиска элементва\n\n");

    printf("Количество элментов    |      Обычное дерево|        AVL - дерево|      hash - таблица|          файл      |\n");

    int n = 50;
    printf("         %d            |", n);
    FILE *f;
    f = fopen("efficiency_1.txt", "r");
    count_for_file(f, n, &tree, &avl_tree, hash, hash_key, collision);

    n = 100;
    avl_tree = NULL;
    tree = NULL;
    hash_init(hash);
    printf("         %d           |", n);
    f = fopen("efficiency_2.txt", "r");
    count_for_file(f, n, &tree, &avl_tree, hash, hash_key, collision);

    n = 500;
    printf("         %d           |", n);
    f = fopen("efficiency_3.txt", "r");
    avl_tree = NULL;
    tree = NULL;
    hash_init(hash);
    count_for_file(f, n, &tree, &avl_tree, hash, hash_key, collision);

    n = 1000;
    printf("         %d          |", n);
    f = fopen("efficiency_4.txt", "r");
    avl_tree = NULL;
    tree = NULL;
    hash_init(hash);
    count_for_file(f, n, &tree, &avl_tree, hash, hash_key, collision);

    n = 5000;
    printf("         %d          |", n);
    f = fopen("efficiency_4.txt", "r");
    avl_tree = NULL;
    tree = NULL;
    hash_init(hash);
    count_for_file(f, n, &tree, &avl_tree, hash, hash_key, collision);

}

