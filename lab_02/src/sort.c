#include <Windows.h>
#include "../inc/sort.h"


int compare(const void *val_1, const void *val_2)
{
    return strcmp(((rep_of_theatres*)val_1)->producer, ((rep_of_theatres*)val_2)->producer);

}

int key_compare(const void *val_1, const void *val_2)
{
    return strcmp(((sort*)val_1)->producer, ((sort*)val_2)->producer);

}


void sort_full_table_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance)
{

    int compare(const void *val_1, const void *val_2);
    qsort(theatres, number_of_perfomance, sizeof(theatres[0]), compare);


}

void sort_array_keys_qs(struct repertoire_of_theatres *theatres, int number_of_perfomance, int *keys)
{
    struct struct_for_sort producer_for_sort[number_of_perfomance];

    for (int i = 0; i < number_of_perfomance; i++)
    {
        producer_for_sort[i].keys = i;
        strcpy(producer_for_sort[i].producer,theatres[i].producer);

    }
    qsort(producer_for_sort, number_of_perfomance, sizeof(struct struct_for_sort), key_compare);

    for (int i = 0; i < number_of_perfomance; i++)
        keys[i] = producer_for_sort[i].keys;

}


void sort_array_keys(struct repertoire_of_theatres *theatres, int number_of_perfomance, int *keys)
{

    struct struct_for_sort producer_for_sort[number_of_perfomance];
    //char producers[*number_of_perfomance][LEN_PRODUCER_NAME];
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
        keys[i] = producer_for_sort[i].keys;


}



void sort_full_table(struct repertoire_of_theatres *theatres, int number_of_perfomance)
{

    //Сортировка вставками
    for (int i = 1; i < number_of_perfomance; i++)
    {
        struct repertoire_of_theatres memory = theatres[i];
        int j = i - 1;
        while (j >=0 && strcmp(memory.producer, theatres[j].producer) < 0)
        {
            theatres[j + 1] = theatres[j];
            theatres[j] = memory;
            j--;
        }
    }

}
