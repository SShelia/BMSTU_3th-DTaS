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
    printf("\n1 - �������� ������\n"
           "2 - �������� ���������\n"
           "3 - �������\n"
           "4 - ����������� ���� ������\n"
           "5 - ������������ ���� ������\n"
           "6 - ��� ���������\n"
           "7 - ������ ���������\n\n");
    printf("�� ������ ���� �� ������ ������� ��������?: ");


    code = number_read(&choice);
    if (code != ok || choice > 7 || choice < 1)
    {
        printf("\n������������ ���� �������� ������.\n");
        code = answer_error;
    }

    while (code != ok)
    {
        choice = 0;
        printf("\n1 - �������� ������\n"
               "2 - �������� ���������\n"
               "3 - �������\n"
               "4 - ����������� ���� ������\n"
               "5 - ������������ ���� ������\n"
               "6 - ��� ���������\n"
               "7 - ������ ���������\n\n");
        printf("�� ������ ���� �� ������ ������� ��������?: ");

        code = number_read(&choice);
        if (code != ok || choice > 7 || choice < 1)
        {
            printf("\n������������ ���� �������� ������.\n");
            code = answer_error;
        }
    }
    fflush(stdin);

    switch(choice){
       case 1:
    {

        char delete_theatre_name[LEN_THEATRE_NAME];
        printf("\n������� �������� ������ (�� 50 ������): ");
        code = str_input(delete_theatre_name, LEN_THEATRE_NAME);
        while (code != ok)
        {
            printf("\n������� �������� ������ (�� 50 ������): ");
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
        printf("\n������� �������� ��������� (�� 40 ������): ");
        code = str_input(delete_perfomance_name, LEN_PERFOMANCE_NAME);
        while (code != ok)
        {
            printf("\n������� �������� ��������� (�� 40 ������): ");
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
        printf("\n������� ��� �������� (�� 25 ������): ");

        code = str_input(delete_producer_name, LEN_PRODUCER_NAME);
        while (code != ok)
        {
            printf("\n������� ��� �������� (�� 25 ������): ");
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

        printf("������� ����������� ���� �� ����� (����� ��������������� �����): ");
        code = number_input(&del_min_price);
        while (code != ok)
        {
            del_min_price = 0;
            printf("\n������� ����������� ���� �� ����� (����� ��������������� �����): ");
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


        printf("������� ������������ ���� �� ����� (����� ��������������� �����): ");
        code = number_input(&del_max_price);
        while (code != ok)
        {
            del_max_price = 0;
            printf("\n������� ������������ ���� �� ����� (����� ��������������� �����): ");
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
        printf("\n0 - �������\n1 - ��������\n2 - �����������\n\n����� ��� ���������?: ");
        int type = 0;
        code = number_read(&type);
        if (code != ok || type < 0 || type > 2)
        {
            printf("\n������������ ����.\n");
            code = answer_error;
        }


        while (code != ok)
        {
            printf("\n0 - �������\n1 - ��������\n2 - �����������\n\n����� ��� ���������?: ");
            type = 0;
            code = number_read(&type);
            if (code != ok || type < 0 || type > 2)
            {
                printf("\n������������ ���� �������� ������.\n");
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

        printf("������� ������ ���������: ");
        int index = 0;
        code = number_read(&index);
        if (code != ok || index >= *number_of_perfomance)
        {
            printf("\n������������ ����.\n\n");
            code = answer_error;
        }

        while (code != ok)
        {
            printf("������� ������ ���������: ");
            int index = 0;
            code = number_read(&index);
            if (code != ok || index >= *number_of_perfomance)
            {
                printf("\n������������ ����.\n\n");
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
