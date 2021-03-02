#ifndef HASH_H
#define HASH_H

typedef struct hash
{
    int value;
    struct hash *next;
}hash;

#define MAX_SIZE 5000

enum mistake
{
    ok,
    value_not_found,
    change_hash_key
};

void hash_init(hash **hash_table);
hash *hash_create_node(int data);
int hash_get_key_for_value(int value, int hash_key);
int hash_compare_int(int val_1, int val_2);
void hash_insert(hash **head, hash *elem, hash *before);
int hash_sorted_insert(hash **field, hash *element, int (*comparator)(int, int));
hash *hash_find_in_table(hash **hash_table, int value, int hash_key, int collision, int *code);

int hash_check_simple(int x);
void hash_key_change(int *hash_key);
void hash_restruct(hash **hash_table, hash **new_hash_table, int *hash_key, int *collision);
void hash_destroy(hash **hash_table, int *hash_key);
void hash_print(hash **hash_table, int *hash_key);

hash *hash_find_in_table_for_del(hash **hash_table, int value, int hash_key, int collision, int *code, int *comparisons);
int hash_insert_in_table(hash **hash_table, int value, int hash_key, int collision,int *comparisons);
int hash_remove_in_table(hash **hash_table, int value, int hash_key, int collision, int *comparisons);

#endif // HASH_H
