#include <stdio.h>
#include "../inc/struct.h"
#include <string.h>
#include "../inc/add_new_perfomance.h"
#include "../inc/delete_perfomance.h"
#include "../inc/filling_structure_fields.h"
#include "../inc/output.h"
#include "../inc/sort.h"
#include <Windows.h>

#define NUMBER_OF_ITERATION 15000
#define MAX_NUMBER_OF_THATRES 80

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //����������� ������ �������
    int number_of_perfomance = 1;

    //���������� ������� ��������
    struct repertoire_of_theatres theatres[MAX_NUMBER_OF_THATRES];
    filling_structure_fields(&theatres[0]);

    int code = ok;

    printf("��� ���������� ������������ �� ���������!\n\n");
    int command =  0;
    while (command != 11)
    {
        command = 0;
        setbuf(stdin, NULL);
        printf("1 - �������� ����� ���������\n");
        printf("2 - ������� ���������\n");
        printf("3 - ����������� ��������������� ������� ������ ��� ��������������� �������� ������� (qsort � ���������)\n");
        printf("4 - ������� ������������� �������� ������� ��� ������������� ������� ������ (���������� ���������)\n");
        printf("5 - ������� ������������� �������� ������� ��� ������������� ������� ������ (qsort)\n");
        printf("6 - ������� ������������� �������� ������� � �������������� ������� ������ (���������� ���������)\n");
        printf("7 - ������� ������������� �������� ������� � �������������� ������� ������ (qsort)\n");
        printf("8 - ������� ��������� ��������� ������������� ������ ��������� ��� ��������� ������ � �������� ������� � � ������� ������\n");
        printf("9 - ������� ������ ���� ����������� ����������  ��� ����� ���������� �������� ������������������ ������ ���������.\n");
        printf("10 - ����� ������� � ������� ���������(��� ����������).\n");
        printf("11 - ��������� ����������.\n");
        printf("������� �������: ");
        number_read(&command);

        switch (command){

        case 1: //���������� ������ ���������

            printf("\n������������ ���������� ����������: %d, �� ������ ������: %d\n", MAX_NUMBER_OF_THATRES, number_of_perfomance);
            if (number_of_perfomance >= MAX_NUMBER_OF_THATRES)
                printf("������ ����������, ���������� ����������!");
            else
            {
                code = add_new_theatre(&theatres[0], &number_of_perfomance);
                theatres[number_of_perfomance - 1].index = number_of_perfomance - 1;
            }

            break;

        case 2: //�������� ���������
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������, �������� ����������.\n");
            else
                delete_perfomance(&theatres[0], &number_of_perfomance);

            break;
        }
        case 3: //�������� ������������� ������� ������
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                printf("\n������� ������ ��� ���������� ���������:\n");
                output_sort_array_keys(&theatres[0], number_of_perfomance);

                printf("\n������� ������ ��� ���������� qsort:\n");
                output_sort_array_keys_qs(&theatres[0], number_of_perfomance);
            }


            break;
        }
        case 4: //������� ������������� �������� ������� ��� ������������� ������� ������ (���������� ���������)
        {

            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                printf("\n���������� ����������� �� ����� ��������.");
                printf("\n��������������� ������� ��� ������������� ������� ������(���������� ���������):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];

            for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];

            sort_full_table(&special_theatres[0], number_of_perfomance);
            output_of_structure_fields(&special_theatres[0], number_of_perfomance);
            break;
        }
        case 5: //������� ������������� �������� ������� ��� ������������� ������� ������ (������� ����������);
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                printf("\n���������� ����������� �� ����� ��������.");
                printf("\n��������������� ������� ��� ������������� ������� ������(������� ����������):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];

            for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];


            sort_full_table_qs(&special_theatres[0], number_of_perfomance);
            output_of_structure_fields(&special_theatres[0], number_of_perfomance);
            break;
        }
        case 6: //������� ������������� �������� ������� � �������������� ������� ������ (������� ����������)
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                printf("\n���������� ����������� �� ����� ��������.");
                printf("\n��������������� ������� � �������������� ������� ������(���������� ���������):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];



           for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];

           int keys[number_of_perfomance];
           sort_array_keys_qs(&special_theatres[0], number_of_perfomance, keys);
           output_by_keys(&special_theatres[0], number_of_perfomance, keys);

            break;
        }
        case 7:
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            {
                printf("\n���������� ����������� �� ����� ��������.");
                printf("\n��������������� ������� � �������������� ������� ������(qsort):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];
            int keys[number_of_perfomance];


           for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];

            sort_array_keys_qs(&special_theatres[0], number_of_perfomance, keys);

            output_by_keys(&special_theatres[0], number_of_perfomance, keys);

            break;
        }
        case 8: //������� ��������� ��������� �������������
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                printf("\n���������� �������� � �������: %d, ���������� �������: %d\n\n", number_of_perfomance, NUMBER_OF_ITERATION);
                printf("���������� � ������� ������� ������(���������)");
                printf("    ���������� � ������� ������� ������(qsort)");
                printf("          ������ ���������� �������(���������)");
                printf("              ������ ���������� �������(qsort)\n");

                clock_t start, stop;
                double duration1=-1.0;
                start = clock();

                struct repertoire_of_theatres theatres_1[number_of_perfomance];
                int keys[number_of_perfomance];


                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_array_keys(&theatres_1[0], number_of_perfomance, keys);

                }

                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf ������", duration1);



                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_array_keys_qs(&theatres_1[0], number_of_perfomance, keys);

                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf ������", duration1);




                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_full_table(&theatres_1[0], number_of_perfomance);
                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf ������", duration1);




                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_full_table_qs(&theatres_1[0], number_of_perfomance);
                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf ������", duration1);

                printf("\n\n");

            }
            break;
        }
        case 9:
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            else
            {
                fflush(stdin);
                int variant_age = 0, variant_duration = 0;

                printf("\n������� �������(����� ��������������� ����� <18): ");
                code = number_input(&variant_age);
                if (code == ok && variant_age >= 18)
                {
                    printf("\n������������ ����.\n");
                    code = input_error;
                }

                while (code != ok)
                {
                   variant_age = 0;
                   printf("\n������� �������(����� ��������������� ����� <18): ");
                   code = number_input(&variant_age);
                   if (code == ok && variant_age >= 18)
                   {
                       printf("\n������������ ����.\n");
                       code = input_error;
                   }
                }


                printf("������� ������������(����� ������������� �����): ");
                code = number_input(&variant_duration);
                if (code == ok && variant_duration == 0)
                {
                    printf("\n������������ ����!\n");
                    code = input_error;
                }

                while (code != ok)
                {
                   variant_duration = 0;
                   printf("\n������� ������������(����� ������������� �����): ");
                   code = number_input(&variant_duration);
                   if (code == ok && variant_duration == 0)
                   {
                       printf("\n������������ ����!\n");
                       code = input_error;
                   }
                }

                output_of_structire_by_variant(&theatres[0], variant_age, variant_duration);
            }
            break;
        }
        case 10:
        {
            if (number_of_perfomance == 0)
                printf("\n� ������� ���������� ���������.\n");
            output_of_structure_fields(&theatres[0], number_of_perfomance);
            break;
        }
        case 11:
        {
            return code;
            break;
        }
        default:

            printf("\n������������ ���� ��������!\n\n");
            break;
        }

    }

    return code;
}

