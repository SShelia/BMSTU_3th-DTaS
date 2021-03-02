#include "../inc/output.h"
#include <Windows.h>


//Обычный вывод
void output_of_structure_fields(struct repertoire_of_theatres *theatres, int num_of_elements)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    for (int i = 0; i < num_of_elements; i++)
    {

        printf("%3d %50s %35s %25s %5d %5d", theatres[i].index, theatres[i].theatre_name, theatres[i].perfomance,
               theatres[i].producer, theatres[i].min_ticket_price, theatres[i].max_ticket_price);

        if (theatres[i].type == childlike)
            printf("   Детский    ");
        else if (theatres[i].type == adult)
            printf("   Взрослый   ");
        else
            printf("   Музыкальный");



        if (theatres[i].type == childlike)
        {

            printf("%3d ",theatres[i].choice.childlike.age);

            if (theatres[i].choice.childlike.type == 0)
                printf("    Сказка");
            else
                printf("    Пьеса ");
        }
        else if (theatres[i].type == adult)
        {


            if (theatres[i].choice.adult.type == drama)
                printf("  Драма");
            else if (theatres[i].choice.adult.type == comedy)
                printf("  Комедия");
            else
                printf("  Пьеса");
        }
        else{

            printf("%25s ", theatres[i].choice.musical.composer);
            printf("%10s ", theatres[i].choice.musical.country);
            printf("%5d ",theatres[i].choice.musical.min_age);
            printf("%5d ",theatres[i].choice.musical.duration);

        }

        printf("\n");
     }
    printf("\n");

}


//Вывод после сортировки с ключом
void output_by_keys(struct repertoire_of_theatres *theatres, int num_of_elements, int *keys)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int j = 0; j < num_of_elements; j++)
    {
        int i = keys[j];
        printf("%3d %50s %35s %25s %5d %5d", theatres[i].index, theatres[i].theatre_name, theatres[i].perfomance,
               theatres[i].producer, theatres[i].min_ticket_price, theatres[i].max_ticket_price);

        if (theatres[i].type == childlike)
            printf("   Детский    ");
        else if (theatres[i].type == adult)
            printf("   Взрослый   ");
        else
            printf("   Музыкальный");



        if (theatres[i].type == childlike)
        {

            printf("%3d ",theatres[i].choice.childlike.age);

            if (theatres[i].choice.childlike.type == 0)
                printf("    Сказка");
            else
                printf("    Пьеса ");
        }
        else if (theatres[i].type == adult)
        {


            if (theatres[i].choice.adult.type == drama)
                printf("  Драма");
            else if (theatres[i].choice.adult.type == comedy)
                printf("  Комедия");
            else
                printf("  Пьеса");
        }
        else{

            printf("%25s ", theatres[i].choice.musical.composer);
            printf("%10s ", theatres[i].choice.musical.country);
            printf("%5d ",theatres[i].choice.musical.min_age);
            printf("%5d ",theatres[i].choice.musical.duration);

        }

        printf("\n");

     }
    printf("\n");


}


//Вывод по задпнию
void output_of_structire_by_variant(struct repertoire_of_theatres *theatres, int variant_age, int variant_duration)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int flag = 1;

    int num_of_theatres = 40;
    printf("\n");
    for (int i = 0; i < num_of_theatres; i++)
    {
        if (theatres[i].type == musical && theatres[i].choice.musical.min_age >= variant_age && theatres[i].choice.musical.duration < variant_duration)
        {
            printf("%2d", theatres[i].index);
            printf("%50s", theatres[i].theatre_name);
            printf("%35s",theatres[i].perfomance);
            printf("%25s ",theatres[i].producer);
            printf("%5d ",theatres[i].min_ticket_price);
            printf("%5d ",theatres[i].max_ticket_price);
            printf("     Музыкальный   ");
            printf("%25s ", theatres[i].choice.musical.composer);
            printf("%10s ", theatres[i].choice.musical.country);
            printf("%5d ",theatres[i].choice.musical.min_age);
            printf("%5d ",theatres[i].choice.musical.duration);
            printf("\n");
            flag = 0;

        }
    }
    printf("\n");
    if (flag) printf("Записи с такими данными отсутствуют!\n\n");
}

//Вывод ключей для обычной сортировки
void output_sort_array_keys(struct repertoire_of_theatres *theatres, int number_of_perfomance)
{
    struct struct_for_sort producer_for_sort[number_of_perfomance];

    for (int i = 0; i < number_of_perfomance; i++)
    {
        producer_for_sort[i].keys = i;
        strcpy(producer_for_sort[i].producer,theatres[i].producer);

    }

    for (int i = 1; i < number_of_perfomance; i++)
    {
        struct struct_for_sort memory;
        strcpy(memory.producer, producer_for_sort[i].producer);
        memory.keys = producer_for_sort[i].keys;
        int j = i - 1;
        while (j >= 0 && strcmp(memory.producer, producer_for_sort[j].producer) < 0)
        {
                producer_for_sort[ j + 1] = producer_for_sort[ j];
                producer_for_sort[j] = memory;
                j--;

        }
    }
    for (int i = 0; i < number_of_perfomance; i++)
        puts(producer_for_sort[i].producer);

}



//Вывод ключей для быстрой сортировки
void output_sort_array_keys_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance)
{

    struct struct_for_sort producer_for_sort[number_of_perfomance];

    for (int i = 0; i < number_of_perfomance; i++)
    {
        producer_for_sort[i].keys = i;
        strcpy(producer_for_sort[i].producer,theatres[i].producer);

    }

    qsort(producer_for_sort, number_of_perfomance, sizeof(struct struct_for_sort), key_compare);

    for (int i = 0; i < number_of_perfomance; i++)
        puts(producer_for_sort[i].producer);
    printf("\n");


}
