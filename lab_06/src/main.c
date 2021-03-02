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

    //Øıø³øğûø÷ğø³øŸ ¸¹ƒúƒ¹
    tree_node *usual_tree = NULL;
    avl_tree_node *avl_tree = NULL;
    hash *hash[MAX_SIZE];
    hash_init(hash);

    //Òòşô ¸¹ğòıõıøù
    printf("Òòõôøõ úşûø¿õ¸òş ¸¹ğòıõıøù, ÿş¸ûõ ÿ¹õò¼õıøŸ úşş¹¾ ıõşñ¾şôøüğ \n¹õ¹õ¸¹ƒúƒ¹ø÷ğ³øŸ ¾§¼-ğñûø³(³õûşõ ÿşûşöøõûışõ ¿ø¸ûş < 100): ");
    int collision = command_input(1, 100);
    int hash_key = 7;

    printf("\n1 - á¿øğ ôğııõ ø÷ ºğùûğ\n"
           "2 - àğñşğ ¸ ÿƒ¸üø ¸¹ƒúƒ¹ğüø\n"
           "Òñş¹: ");
    int command = command_input(1, 2);

    //çõıøõ ¸ ºğùûğ
    if (command == 1)
    {
        FILE *f;
        f = fopen("in_01.txt", "r");
        read_file(f, &usual_tree, &avl_tree, hash, &hash_key, &collision);
        fclose(f);
    }

    printf("\nÒñõ¹øõ ôõù¸òøõ:\n"
           "1 - Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıøŸ ôõ¹õòğ\n"
           "2 - Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıøŸ avl-ôõ¹õòğ\n"
           "3 - Òòõ¸ø õúƒšõõ ¸ş¸şŸıøõ ¾§¼-ğñûø³\n"
           "4 - Ôşñğòûõıøõ §ûõüõığ\n"
           "5 - ãôğûõıøõ §ûõüõığ\n"
           "6 - áüõıø úşûø¿õ¸òş ¸¹ğòıõıøù ôûŸ ¹õ¸¹ƒúƒ¹ø÷ğ³øø ¾§¼-ğñûø³\n"
           "7 - áüõıø ÷ığ¿õıøõ úû¢¿ğ ôûŸ ¾§¼-ğñûø³\n"
           "8 - Ş³õıø §ººõúøòış¸ ÿşø¸úğ ò ¹ğ÷ı¾ ¸¹ƒúƒ¹ğ¾ ôğıı¾\n"
           "0 - ×ğòõ¹¼ø ÿ¹şó¹ğüüƒ\n"
           "Òñş¹: ");
    command = command_input(0, 8);

    while (command != 0)
    {
        switch(command){

        //Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıøŸ ôõ¹õòğ
        case 1:
        {
            FILE *f = fopen("usual_tree.gv", "w");
            usual_tree_btree_export_to_dot(f, "usual_tree", usual_tree);
            fclose(f);

            break;
        }
        //Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıø avl-ôõ¹õòğ
        case 2:
        {
            FILE *f = fopen("avl_tree.gv", "w");
            avl_tree_btree_export_to_dot(f, "avl_tree", avl_tree);
            fclose(f);

            break;
        }
        //Òòõ¸ø õúƒšõõ ¸ş¸şŸıøõ ¾§¼-ğñûø³
        case 3:
        {
            hash_print(hash, &hash_key);
            break;
        }
        //Ôşñğòûõıøõ §ûõüõığ
        case 4:
        {
            add_elem(&usual_tree, &avl_tree, hash, &hash_key, &collision);
            break;
        }
        //ãôğûõıøõ §ûõüõığ
        case 5:
        {
            delete_elem(&usual_tree, &avl_tree, hash, &hash_key, &collision);
            break;
        }
        //áüõıø úşûø¿õ¸òş ¸¹ğòıõıøõ ôûŸ ¹õ¸¹ƒúğ¹ø÷ğ³øø ¾§¼-ğñûø³
        case 6:
        {
            printf("Òòõôøõ úşûø¿õ¸òş ¸¹ğòıõıøù, ÿş¸ûõ ÿ¹õò¼õıøŸ úşş¹¾ ıõşñ¾şôøüğ \n¹õ¹õ¸¹ƒúƒ¹ø÷ğ³øŸ ¾§¼-ğñûø³(³õûşõ ÿşûşöøõûışõ ¿ø¸ûş < 100): ");
            collision = command_input(1, 100);


            struct hash *new_hash_table[MAX_SIZE];
            hash_init(new_hash_table);

            hash_restruct(hash, new_hash_table, &hash_key, &collision);


            break;
        }

        //áüõıŸ úû¢¿ğ
        case 7:
        {
            printf("âõúƒšõõ ÷ığ¿õıøõ úû¢¿ğ: %d\n", hash_key);
            printf("Òòõôøõ ışòù úû¢¿(³õûşõ ÿşûşöøõûışõ ÿ¹ş¸şõ ¿ø¸ûş < 100): ");
            hash_key = command_input(2, 100);

            while (hash_check_simple(hash_key))
            {
                printf("İõúş¹¹õúıù òòşô, ¿ø¸ûş ôşûöış ñ ÿ¹ş¸ü!");
                hash_key = command_input(2, 100);
            }


            struct hash *new_hash_table[MAX_SIZE];
            hash_init(new_hash_table);

            hash_restruct(hash, new_hash_table, &hash_key, &collision);
            break;

            break;
        }

        //á¹ğòıõıøõ §ººõúøòış¸ø
        case 8:
        {
            check_efficience(hash_key, collision);
            break;
        }
    }
        printf("\nÒñõ¹øõ ôõù¸òøõ:\n"
               "1 - Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıøŸ ôõ¹õòğ\n"
               "2 - Şñışòø ºğùû ôûŸ õúƒšõóş ¸ş¸şŸıøŸ avl-ôõ¹õòğ\n"
               "3 - Òòõ¸ø õúƒšõõ ¸ş¸şŸıøõ ¾§¼-ğñûø³\n"
               "4 - Ôşñğòûõıøõ §ûõüõığ\n"
               "5 - ãôğûõıøõ §ûõüõığ\n"
               "6 - áüõıø úşûø¿õ¸òş ¸¹ğòıõıøù ôûŸ ¹õ¸¹ƒúƒ¹ø÷ğ³øø ¾§¼-ğñûø³\n"
               "7 - áüõıø ÷ığ¿õıøõ úû¢¿ğ ôûŸ ¾§¼-ğñûø³\n"
               "8 - Ş³õıø §ººõúøòış¸ ÿşø¸úğ ò ¹ğ÷ı¾ ¸¹ƒúƒ¹ğ¾ ôğıı¾\n"
               "0 - ×ğòõ¹¼ø ÿ¹şó¹ğüüƒ\n"
               "Òñş¹: ");
        command = command_input(0, 8);
     }

    return code;
}

