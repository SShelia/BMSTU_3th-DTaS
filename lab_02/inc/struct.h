#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <string.h>

#define LEN_THEATRE_NAME 51
#define LEN_PERFOMANCE_NAME 41
#define LEN_PRODUCER_NAME 26
#define LEN_COMPOSER_NAME 26
#define LEN_COUNTRY_NAME 16


enum type_of_perfomance {
    childlike,
    adult,
    musical};

enum type_of_child_performance {
    fairy_tale,
    child_play};

enum type_of_adult_performance{
    adult_play,
    drama,
    comedy};

struct children_performance
{
    int age;
    enum type_of_child_performance type;

};

struct adult_performance
{
    enum type_of_adult_performance type;
};

struct musical_performance
{
    char composer[LEN_COMPOSER_NAME];
    char country[LEN_COUNTRY_NAME];
    int min_age;
    int duration;
};


struct repertoire_of_theatres
{
    int index;
    char theatre_name[LEN_THEATRE_NAME];
    char perfomance[LEN_PERFOMANCE_NAME];
    char producer[LEN_PRODUCER_NAME];
    int min_ticket_price;
    int max_ticket_price;

    enum type_of_perfomance type;

    union
    {
        struct children_performance childlike;
        struct adult_performance adult;
        struct musical_performance musical;
    }choice;

};

struct struct_for_sort{
    char producer[LEN_PRODUCER_NAME];
    int keys;
};


typedef enum
{
    ok = 0,
    input_error,
    price_error,
    answer_error,
    age_error,
    empty_input,

}statuscodes;






#endif // STRUCT_H
