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

    //Изначальный размер массива
    int number_of_perfomance = 1;

    //Заполнение массива структур
    struct repertoire_of_theatres theatres[MAX_NUMBER_OF_THATRES];
    filling_structure_fields(&theatres[0]);

    int code = ok;

    printf("Все сортировки производятся по продюсеру!\n\n");
    int command =  0;
    while (command != 11)
    {
        command = 0;
        setbuf(stdin, NULL);
        printf("1 - Добавить новый спектакль\n");
        printf("2 - Удалить спектакль\n");
        printf("3 - Просмотреть отсортированную таблицу ключей при несортированной исходной таблице (qsort и вставками)\n");
        printf("4 - Вывести упорядоченную исходную таблицу без использования таблицы ключей (сортировка вставками)\n");
        printf("5 - Вывести упорядоченную исходную таблицу без использования таблицы ключей (qsort)\n");
        printf("6 - Вывести упорядоченную исходную таблицу с использованием таблицы ключей (сортировка вставками)\n");
        printf("7 - Вывести упорядоченную исходную таблицу с использованием таблицы ключей (qsort)\n");
        printf("8 - Вывести результат сравнения эффективности работы программы при обработке данных в исходной таблице и в таблице ключей\n");
        printf("9 - Вывести список всех музыкальных спектаклей  для детей указанного возраста продолжительностью меньше указанной.\n");
        printf("10 - Вывод таблицы в текущем состоянии(без сортировок).\n");
        printf("11 - Завершить выполнение.\n");
        printf("Введите команду: ");
        number_read(&command);

        switch (command){

        case 1: //Добавление нового спектакля

            printf("\nМаксимальное количество спектаклей: %d, на данным момент: %d\n", MAX_NUMBER_OF_THATRES, number_of_perfomance);
            if (number_of_perfomance >= MAX_NUMBER_OF_THATRES)
                printf("Массив переполнен, добавление невозможно!");
            else
            {
                code = add_new_theatre(&theatres[0], &number_of_perfomance);
                theatres[number_of_perfomance - 1].index = number_of_perfomance - 1;
            }

            break;

        case 2: //Удаление спектакля
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли, удаление невозможно.\n");
            else
                delete_perfomance(&theatres[0], &number_of_perfomance);

            break;
        }
        case 3: //Просмотр сортированной таблицы ключей
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                printf("\nТаблица ключей для сортировки вставками:\n");
                output_sort_array_keys(&theatres[0], number_of_perfomance);

                printf("\nТаблица ключей для сортировки qsort:\n");
                output_sort_array_keys_qs(&theatres[0], number_of_perfomance);
            }


            break;
        }
        case 4: //Вывести упорядоченную исходную таблицу без использования таблицы ключей (сортировка вставками)
        {

            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                printf("\nСортировка произодится по имени режисера.");
                printf("\nОтсортированная таблица без использования массива ключей(сортировка вставками):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];

            for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];

            sort_full_table(&special_theatres[0], number_of_perfomance);
            output_of_structure_fields(&special_theatres[0], number_of_perfomance);
            break;
        }
        case 5: //Вывести упорядоченную исходную таблицу без использования таблицы ключей (быстрая сортировка);
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                printf("\nСортировка произодится по имени режисера.");
                printf("\nОтсортированная таблица без использования таблицы ключей(быстрая сортировка):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];

            for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];


            sort_full_table_qs(&special_theatres[0], number_of_perfomance);
            output_of_structure_fields(&special_theatres[0], number_of_perfomance);
            break;
        }
        case 6: //Вывести упорядоченную исходную таблицу с использованием таблицы ключей (обычная сортировка)
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                printf("\nСортировка произодится по имени режисера.");
                printf("\nОтсортированная таблица с использованием таблицы ключей(сортировка вставками):\n");
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
                printf("\nВ таблице отсутсвуют спектакли.\n");
            {
                printf("\nСортировка произодится по имени режисера.");
                printf("\nОтсортированная таблица с использованием таблицы ключей(qsort):\n");
            }
            struct repertoire_of_theatres special_theatres[number_of_perfomance];
            int keys[number_of_perfomance];


           for (int j = 0; j < number_of_perfomance; j++)
                special_theatres[j] = theatres[j];

            sort_array_keys_qs(&special_theatres[0], number_of_perfomance, keys);

            output_by_keys(&special_theatres[0], number_of_perfomance, keys);

            break;
        }
        case 8: //Вывести результат сранвения эффективности
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                printf("\nКоличество струткур в массиве: %d, количество итерацй: %d\n\n", number_of_perfomance, NUMBER_OF_ITERATION);
                printf("Сортировка с помощью массива ключей(вставками)");
                printf("    Сортировка с помощью массива ключей(qsort)");
                printf("          Полная сортировка массива(вставками)");
                printf("              Полная сортировка массива(qsort)\n");

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
                printf("%39.5lf секунд", duration1);



                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_array_keys_qs(&theatres_1[0], number_of_perfomance, keys);

                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf секунд", duration1);




                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_full_table(&theatres_1[0], number_of_perfomance);
                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf секунд", duration1);




                start = clock();
                for (int i = 0; i < NUMBER_OF_ITERATION; i ++)
                {
                    for (int j = 0; j < number_of_perfomance; j++)
                        theatres_1[j] = theatres[j];
                    sort_full_table_qs(&theatres_1[0], number_of_perfomance);
                }
                stop = clock();
                duration1=(double)(stop-start)/CLOCKS_PER_SEC;
                printf("%39.5lf секунд", duration1);

                printf("\n\n");

            }
            break;
        }
        case 9:
        {
            if (number_of_perfomance == 0)
                printf("\nВ таблице отсутсвуют спектакли.\n");
            else
            {
                fflush(stdin);
                int variant_age = 0, variant_duration = 0;

                printf("\nВведите возраст(целое неотрицательное число <18): ");
                code = number_input(&variant_age);
                if (code == ok && variant_age >= 18)
                {
                    printf("\nНекорректный ввод.\n");
                    code = input_error;
                }

                while (code != ok)
                {
                   variant_age = 0;
                   printf("\nВведите возраст(целое неотрицательное число <18): ");
                   code = number_input(&variant_age);
                   if (code == ok && variant_age >= 18)
                   {
                       printf("\nНекорректный ввод.\n");
                       code = input_error;
                   }
                }


                printf("Введите длительность(целое положительное число): ");
                code = number_input(&variant_duration);
                if (code == ok && variant_duration == 0)
                {
                    printf("\nНекорреткный ввод!\n");
                    code = input_error;
                }

                while (code != ok)
                {
                   variant_duration = 0;
                   printf("\nВведите длительность(целое положительное число): ");
                   code = number_input(&variant_duration);
                   if (code == ok && variant_duration == 0)
                   {
                       printf("\nНекорреткный ввод!\n");
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
                printf("\nВ таблице отсутсвуют спектакли.\n");
            output_of_structure_fields(&theatres[0], number_of_perfomance);
            break;
        }
        case 11:
        {
            return code;
            break;
        }
        default:

            printf("\nНекорректный ввод комманды!\n\n");
            break;
        }

    }

    return code;
}

