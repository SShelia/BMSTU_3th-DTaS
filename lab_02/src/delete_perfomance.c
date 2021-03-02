#include <Windows.h>
#include "../inc/delete_perfomance.h"


void del_perfomance_struct(struct repertoire_of_theatres *theatres, int i, int *number_of_perfomance)
{
    while (i < *number_of_perfomance)
    {
        theatres[i] = theatres[i + 1];
        i++;
    }
    *number_of_perfomance-=1;
}

void delete_perfomance(struct repertoire_of_theatres *theatres, int *number_of_perfomance)
{
    int code = ok;
    setbuf(stdin, NULL);

    int choice = 0;
    printf("\n1 - Название театра\n"
           "2 - Название спектакля\n"
           "3 - Режисер\n"
           "4 - Минимальная цена билета\n"
           "5 - Максимальная цена билета\n"
           "6 - Тип спектакля\n"
           "7 - Индекс спектакля\n\n");
    printf("По какому полю вы хотите сделать удаление?: ");


    code = number_read(&choice);
    if (code != ok || choice > 7 || choice < 1)
    {
        printf("\nНеправильный ввод варианта ответа.\n");
        code = answer_error;
    }

    while (code != ok)
    {
        choice = 0;
        printf("\n1 - Название театра\n"
               "2 - Название спектакля\n"
               "3 - Режисер\n"
               "4 - Минимальная цена билета\n"
               "5 - Максимальная цена билета\n"
               "6 - Тип спектакля\n"
               "7 - Индекс спектакля\n\n");
        printf("По какому полю вы хотите сделать удаление?: ");

        code = number_read(&choice);
        if (code != ok || choice > 7 || choice < 1)
        {
            printf("\nНеправильный ввод варианта ответа.\n");
            code = answer_error;
        }
    }
    fflush(stdin);

    switch(choice){
       case 1:
    {

        char delete_theatre_name[LEN_THEATRE_NAME];
        printf("\nВведите название театра (до 50 знаков): ");
        code = str_input(delete_theatre_name, LEN_THEATRE_NAME);
        while (code != ok)
        {
            printf("\nВведите название театра (до 50 знаков): ");
            code = str_input(delete_theatre_name, LEN_THEATRE_NAME);

        }

        for (int i = 0; i < *number_of_perfomance; i++)
        {

            if (strcmp(theatres[i].theatre_name, delete_theatre_name) == 0)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }
        }

        break;
    }

       case 2:
    {


        char delete_perfomance_name[LEN_PERFOMANCE_NAME];
        printf("\nВведите название спектакля (до 40 знаков): ");
        code = str_input(delete_perfomance_name, LEN_PERFOMANCE_NAME);
        while (code != ok)
        {
            printf("\nВведите название спектакля (до 40 знаков): ");
            code = str_input(delete_perfomance_name, LEN_PERFOMANCE_NAME);

        }


        for (int i = 0; i < *number_of_perfomance; i++)
        {
            if (strcmp(theatres[i].perfomance, delete_perfomance_name) == 0)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }
        }
        break;
    }

    case 3:
    {
        char delete_producer_name[LEN_PRODUCER_NAME];
        printf("\nВведите имя режисера (до 25 знаков): ");

        code = str_input(delete_producer_name, LEN_PRODUCER_NAME);
        while (code != ok)
        {
            printf("\nВведите имя режисера (до 25 знаков): ");
            code = str_input(delete_producer_name, LEN_PRODUCER_NAME);

        }


        for (int i = 0; i < *number_of_perfomance; i++)
        {
            if (strcmp(theatres[i].producer, delete_producer_name) == 0)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }

        }
        break;
    }
    case 4:
    {


        int del_min_price = 0;

        printf("Введите минимальную цену за билет (целое неотрицательное число): ");
        code = number_input(&del_min_price);
        while (code != ok)
        {
            del_min_price = 0;
            printf("\nВведите минимальную цену за билет (целое неотрицательное число): ");
            code = number_input(&del_min_price);
        }


        for (int i = 0; i < *number_of_perfomance; i++)
        {
            if (theatres[i].min_ticket_price == del_min_price)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }

        }
        break;

    }
    case 5:
    {
        int del_max_price = 0;


        printf("Введите максимальную цену за билет (целое неотрицательное число): ");
        code = number_input(&del_max_price);
        while (code != ok)
        {
            del_max_price = 0;
            printf("\nВведите максимальную цену за билет (целое неотрицательное число): ");
            code = number_input(&del_max_price);
        }


        for (int i = 0; i < *number_of_perfomance; i++)
        {
            if (theatres[i].max_ticket_price == del_max_price)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }

        }
        break;


    }
    case 6:
    {
        printf("\n0 - Детский\n1 - Взрослый\n2 - Музыкальный\n\nКакой тип спектакля?: ");
        int type = 0;
        code = number_read(&type);
        if (code != ok || type < 0 || type > 2)
        {
            printf("\nНекорректный ввод.\n");
            code = answer_error;
        }


        while (code != ok)
        {
            printf("\n0 - Детский\n1 - Взрослый\n2 - Музыкальный\n\nКакой тип спектакля?: ");
            type = 0;
            code = number_read(&type);
            if (code != ok || type < 0 || type > 2)
            {
                printf("\nНеправильный ввод варианта ответа.\n");
                code = answer_error;
            }
            fflush(stdin);
        }


        for (int i = 0; i < *number_of_perfomance; i++)
        {
            if ((int)theatres[i].type == type)
            {
                del_perfomance_struct(&theatres[0], i, number_of_perfomance);
                i--;
            }
        }
        break;

    }
    case 7:
    {

        printf("Введите индекс спектакля: ");
        int index = 0;
        code = number_read(&index);
        if (code != ok || index >= *number_of_perfomance)
        {
            printf("\nНекорректный ввод.\n\n");
            code = answer_error;
        }

        while (code != ok)
        {
            printf("Введите индекс спектакля: ");
            int index = 0;
            code = number_read(&index);
            if (code != ok || index >= *number_of_perfomance)
            {
                printf("\nНекорректный ввод.\n\n");
                code = answer_error;
            }
        }
        del_perfomance_struct(&theatres[0], index, number_of_perfomance);

        break;
    }

    default:
        break;

}

    for (int i = 0; i < *number_of_perfomance; i++)
        theatres[i].index = i;

    printf("\n");
}
