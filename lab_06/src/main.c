#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "../inc/time_measurement.h"
#include "../inc/all_commands.h"
#include "../inc/avl_tree.h"
#include "../inc/data_input.h"
#include "../inc/hash.h"
#include "../inc/usual_tree.h"
#include "../inc/errors.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int code = all_ok;

    //�������������� ��������
    tree_node *usual_tree = NULL;
    avl_tree_node *avl_tree = NULL;
    hash *hash[MAX_SIZE];
    hash_init(hash);

    //���� ���������
    printf("������� ���������� ���������, ����� �������� ������� ��������� \n����������������� ���-�������(����� ������������� ����� < 100): ");
    int collision = command_input(1, 100);
    int hash_key = 7;

    printf("\n1 - ���� ������ �� �����\n"
           "2 - ������ � ������� �����������\n"
           "Ҟ���: ");
    int command = command_input(1, 2);

    //����� � �����
    if (command == 1)
    {
        FILE *f;
        f = fopen("in_01.txt", "r");
        read_file(f, &usual_tree, &avl_tree, hash, &hash_key, &collision);
        fclose(f);
    }

    printf("\nҞ������ ��������:\n"
           "1 - �������� ���� ��� �������� ��������� ������\n"
           "2 - �������� ���� ��� �������� ��������� avl-������\n"
           "3 - Ҟ����� ������� ��������� ���-�������\n"
           "4 - ���������� ��������\n"
           "5 - �������� ��������\n"
           "6 - ������� ���������� ��������� ��� ��������������� ���-�������\n"
           "7 - ������� ������� ����� ��� ���-�������\n"
           "8 - ޳����� ������������� ������ � ������ ��������� ������\n"
           "0 - ��������� ��������\n"
           "Ҟ���: ");
    command = command_input(0, 8);

    while (command != 0)
    {
        switch(command){

        //�������� ���� ��� �������� ��������� ������
        case 1:
        {
            FILE *f = fopen("usual_tree.gv", "w");
            usual_tree_btree_export_to_dot(f, "usual_tree", usual_tree);
            fclose(f);

            break;
        }
        //�������� ���� ��� �������� �������� avl-������
        case 2:
        {
            FILE *f = fopen("avl_tree.gv", "w");
            avl_tree_btree_export_to_dot(f, "avl_tree", avl_tree);
            fclose(f);

            break;
        }
        //Ҟ����� ������� ��������� ���-�������
        case 3:
        {
            hash_print(hash, &hash_key);
            break;
        }
        //���������� ��������
        case 4:
        {
            add_elem(&usual_tree, &avl_tree, hash, &hash_key, &collision);
            break;
        }
        //�������� ��������
        case 5:
        {
            delete_elem(&usual_tree, &avl_tree, hash, &hash_key, &collision);
            break;
        }
        //������� ���������� ��������� ��� �������������� ���-�������
        case 6:
        {
            printf("������� ���������� ���������, ����� �������� ������� ��������� \n����������������� ���-�������(����� ������������� ����� < 100): ");
            collision = command_input(1, 100);


            struct hash *new_hash_table[MAX_SIZE];
            hash_init(new_hash_table);

            hash_restruct(hash, new_hash_table, &hash_key, &collision);


            break;
        }

        //����� �����
        case 7:
        {
            printf("������� ������� �����: %d\n", hash_key);
            printf("������� ���� ����(����� ������������� ������� ����� < 100): ");
            hash_key = command_input(2, 100);

            while (hash_check_simple(hash_key))
            {
                printf("������������ ����, ����� ������ 񞐝 �������!");
                hash_key = command_input(2, 100);
            }


            struct hash *new_hash_table[MAX_SIZE];
            hash_init(new_hash_table);

            hash_restruct(hash, new_hash_table, &hash_key, &collision);
            break;

            break;
        }

        //�������� �������������
        case 8:
        {
            check_efficience(hash_key, collision);
            break;
        }
    }
        printf("\nҞ������ ��������:\n"
               "1 - �������� ���� ��� �������� ��������� ������\n"
               "2 - �������� ���� ��� �������� ��������� avl-������\n"
               "3 - Ҟ����� ������� ��������� ���-�������\n"
               "4 - ���������� ��������\n"
               "5 - �������� ��������\n"
               "6 - ������� ���������� ��������� ��� ��������������� ���-�������\n"
               "7 - ������� ������� ����� ��� ���-�������\n"
               "8 - ޳����� ������������� ������ � ������ ��������� ������\n"
               "0 - ��������� ��������\n"
               "Ҟ���: ");
        command = command_input(0, 8);
     }

    return code;
}

