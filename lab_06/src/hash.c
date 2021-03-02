
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/hash.h"

//Инициализация хэш-таблицы
void hash_init(hash **hash_table)
{
    for (int i = 0; i < MAX_SIZE; i++)
        hash_table[i] = NULL;
}

//Создание одного элемента
hash *hash_create_node(int data)
{
    hash *new_elem = malloc(sizeof(hash));

    if (new_elem != NULL)
    {
        new_elem->value = data;
        new_elem->next = NULL;
    }
    return new_elem;
}

//Получаем ключ значения
int hash_get_key_for_value(int value, int hash_key)
{
    int key_value = abs(value) % hash_key;
    return key_value;
}

//Сравнение
int hash_compare_int(int val_1, int val_2)
{
    return (val_1 - val_2);
}

//Добавление элемента перед указанным
void hash_insert(hash **head, hash *elem, hash *before)
{
    if (head != NULL && before->value != elem->value)
    {
        hash *i = *head;
        //Если вставка перед первым элементом
        if (*head == before)
        {
            *head = elem;
            (*head)->next = i;
        }
        else
        {
            //Пока не дойдем до последнего
            while (i->next != NULL)
            {
                if (i->next == before)
                {
                    hash *tmp = i->next;
                    i->next = elem;
                    elem->next = tmp;
                    break;
                }

                i = i->next;
            }
        }
    }
}


//Добавление элемента в отсортированнный список
int hash_sorted_insert(hash **field, hash *element, int (*comparator)(int, int))
{
    int size = 0;
    if (*field != NULL && element != NULL)
    {
        hash *tmp = *field;
        while (tmp->next != NULL)
        {
            if (comparator(tmp->value, element->value) >= 0)
            {
                hash_insert(field, element, tmp);
                break;
            }
            tmp = tmp->next;
            size++;
        }

        //Для первого и последнего элемента
        if (tmp->next == NULL && comparator(tmp->value, element->value) >= 0)
        {
            hash_insert(field, element, tmp);
            size++;
        }
        else if (tmp->next == NULL)
        {
            tmp->next = element;
            element->next = NULL;
            size++;
        }
    }
    else if (element != NULL)
    {
        element->next = *field;
        *field = element;
        size = 1;
    }
    return size;
}

//Вставка в хэш-табицу
int hash_insert_in_table(hash **hash_table, int value, int hash_key, int collision, int *comparisons)
{
    int code = ok;

    //Узнаем ключ элемента
    int key = hash_get_key_for_value(value, hash_key);

    hash *new_elem = hash_create_node(value);
    int count_collision = 0;
    if (new_elem != NULL)
    {
        count_collision = hash_sorted_insert(&hash_table[key], new_elem, hash_compare_int);
        if (count_collision > collision)
            code = change_hash_key;
    }

    *comparisons = count_collision;
    return code;
}

//Поиск по хэш-таблице
hash *hash_find_in_table(hash **hash_table, int value, int hash_key, int collision, int *code)
{
    int count_collision = 0;

    //Узнаем ключ элемента
    int key = hash_get_key_for_value(value, hash_key);

    hash *tmp = hash_table[key];

    while (tmp != NULL)
    {
        count_collision++;
        if (tmp->value == value)
            break;
        tmp = tmp->next;
    }

    if (count_collision > collision)
        *code = change_hash_key;
    else if (tmp == NULL)
        *code = value_not_found;

    return tmp;
}


//Поиск по хэш-таблице
hash *hash_find_in_table_for_del(hash **hash_table, int value, int hash_key, int collision, int *code, int *comparisons)
{
    int count_collision = 0;

    //Узнаем ключ элемента
    int key = hash_get_key_for_value(value, hash_key);

    hash *tmp = hash_table[key];
    hash *parent = tmp;

    while (tmp != NULL && tmp->value <= value)
    {
        count_collision++;
        if (tmp->value == value)
            break;

        parent = tmp;
        tmp = tmp->next;
    }

    if (count_collision > collision)
        *code = change_hash_key;
    else if (tmp == NULL)
        *code = value_not_found;

    *comparisons = count_collision;
    return parent;
}

//Удаление из хэш-таблицы
int hash_remove_in_table(hash **hash_table, int value, int hash_key, int collision, int *comparisons)
{
    int code = ok;

    //Узнаем ключ элемента
    int key = hash_get_key_for_value(value, hash_key);
    //Ищем элемент в таблице
    hash *parent = hash_find_in_table_for_del(hash_table, value, hash_key, collision, &code, comparisons);

    if (code == value_not_found)
        printf("Not delete");
    else
    {
        //Если элемент один
        if (parent->next == NULL)
        {
           free(parent);
           hash_table[key] = NULL;
        }
        else
        {
            //Если нужный элемент первый
            if(parent->value == value)
            {
                hash_table[key] = parent->next;
                free(parent);
            }
            else
            {
                hash *del_elem = parent->next;
                parent->next = parent->next->next;
                free(del_elem);
            }
        }
    }

    return code;
}

//Проверка числа на простоту
int hash_check_simple(int x)
{
    if (x > 1)
    {
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
                return 1;
        }
        return 0;
    }
    else
        return 1;
}

//Смена ключа
void hash_key_change(int *hash_key)
{
    //Пока число не просто прибавляем 2
    *(hash_key) += 2;
    while (hash_check_simple(*hash_key))
        *(hash_key) += 2;
}


//Реструктаризация хэш-таблицы
void hash_restruct(hash **hash_table, hash **new_hash_table, int *hash_key, int *collision)
{
    int comp = 0;
    int count = 0;
    int h_hash_key = *hash_key;
    int code = change_hash_key;

    //Пока коллизии не будут устранены
    while (code == change_hash_key)
    {

        hash_destroy(new_hash_table, hash_key);
        //hash_init(new_hash_table);

        //Определяем новый ключ хэш-таблицы
        hash_key_change(hash_key);

        for (int i = 0; i < *hash_key; i++)
        {
            if (hash_table[i] == NULL) count++;
            for (hash *tmp = hash_table[i]; tmp != NULL; tmp = tmp->next)
            {
                int value = tmp->value;
                code = hash_insert_in_table(new_hash_table, value, *hash_key, *collision, &comp);
                comp = 0;
                if (code == change_hash_key)
                    break;
            }
        }
        if (count == *hash_key)
            break;
        else
            count = 0;

    }

    //Уничтожение старой хэш-таблицы
    hash_destroy(hash_table, &h_hash_key);
    hash_init(hash_table);

    for (int i = 0; i < *hash_key; i++)
    {
        for (hash *tmp = new_hash_table[i]; tmp != NULL; tmp = tmp->next)
        {
            int value = tmp->value;
            code = hash_insert_in_table(hash_table, value, *hash_key, *collision, &comp);
            comp = 0;
        }
    }

    hash_destroy(new_hash_table, hash_key);
}
//Уничтожение таблицы
void hash_destroy(hash **hash_table, int *hash_key)
{
    for (int i = 0; i < *hash_key; i++)
    {
        while (hash_table[i] != NULL)
        {
            hash *tmp = hash_table[i];
            hash_table[i] = tmp->next;
            free(tmp);
        }
    }
}

//Печать хэш-таблицы
void hash_print(hash **hash_table, int *hash_key)
{
    printf("\nHash key = %d\n", *hash_key);
    for (int i = 0; i < *hash_key; i++)
    {
        hash *tmp = hash_table[i];
        if (tmp != NULL)
        {
            printf("%d: ",i);

            while (tmp != NULL)
            {
                printf("%d -> ", tmp->value);
                tmp = tmp->next;
            }
            printf("NULL\n");
        }
        else
            printf("%d: NULL\n",  i);
    }
}



