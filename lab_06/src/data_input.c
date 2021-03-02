#include <stdio.h>
#include "../inc/errors.h"
#include "../inc/avl_tree.h"
#include "../inc/data_input.h"
#include "../inc/hash.h"
#include "../inc/usual_tree.h"

//Считвание числа
int number_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];

    while ((c = getchar()) <= 57 && c >= 48 )
    {
        array[i] = c - 48;
        i++;
    }

    if (c == '\n' && i == 0)
        code= input_error;

    else if (c != '\n')
    {
        while ((c = getchar()) != '\n');
        code= input_error;
    }
    else
    {
        i--;
        int pow = 1;
        for (; i >=0; i--)
        {
            *number+=array[i] * pow;
            pow*=10;
        }
    }
    return code;
}

//Ввод команды
int command_input(int min_size, int max_size)
{
    int code = ok;
    int command = 0;
    code = number_read(&command);

    if (command > max_size || command < min_size)
        code = input_error;

    while (code != ok)
    {
        printf("\n???????????? ????.\n?????: ");
        command = 0;
        code = number_read(&command);
        if (command > max_size || command < min_size)
            code = input_error;;
    }

    return command;
}


//Считвание числа для добавления
int number_for_add_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];

    int sign = 1;
    if ((c = getchar()) == 45)
        sign = -1;
    else if (c == 43)
        sign = 1;
    else if (c <= 57 && c>= 48)
    {
        sign = 1;
        array[i] = c - 48;
        i++;
    }
    else
        code= input_error;

    while (code == ok && (c = getchar()) <= 57 && c >= 48 )
    {
        array[i] = c - 48;
        i++;
    }

    if (c == '\n' && i == 0)
        code= input_error;
    else if (c != '\n')
    {
        while ((c = getchar()) != '\n');
        code= input_error;
    }
    else
    {
        i--;
        int pow = 1;
        for (; i >=0; i--)
        {
            *number+=array[i] * pow;
            pow*=10;
        }
        *number*=sign;

    }
    return code;

}


//Ввод числа для добавления
int number_for_add_input()
{
    int code = ok;
    int number = 0;
    code = number_for_add_read(&number);
    while (code != ok)
    {
        number = 0;
        printf("\nНекорректный ввод. Введите чсило повторно: ");
        code = number_read(&number);
    }

    return number;
}

//------------------------------------------------------------------------------------------

//Считвание числа из файла
int read_int_number(FILE *f, int *number)
{
    if (fscanf(f, "%d", number) != 1)
        return 1;
    return 0;
}


//Считывание данных из файла
void read_file(FILE *f, tree_node **tree, avl_tree_node **avl_tree, hash **hash_table, int *hash_key, int *collision)
{
    int comparisons = 0;
    int code = ok;

    //Новый хеш на случай реструктуризации
    struct hash *new_hash_table[MAX_SIZE];
    hash_init(new_hash_table);

    int number;
    int result = read_int_number(f, &number);
    while (result == 0)
    {
        code = usual_tree_insert(tree, number, &comparisons);
        comparisons = 0;
        avl_tree_insert(avl_tree, number, &comparisons);

        comparisons = 0;
        code = hash_insert_in_table(hash_table, number, *hash_key, *collision, &comparisons);
        if (code == change_hash_key)
            hash_restruct(hash_table, new_hash_table, hash_key, collision);

        result = read_int_number(f, &number);

    }
}
