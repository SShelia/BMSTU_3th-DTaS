#ifndef FUNCTIONS_H
#define FUNCTIONS_H


struct number
{
    int mantisa_sign;
    int mantisa_field[31];
    int order_sign;
    int order_field[6];
    int position_of_point;
    int order;
};

typedef enum
{
    point = 46,
    minus = 45,
    plus = 43,
    zero = 48,
    nine = 57,
    ex = 101,
    Ex = 69,

}alt_code;

typedef enum
{
    ok = 0,
    incorrect_number_input,
    division_by_zero,
    stop_the_division,
    missing_mantissa,
    overflow,
}statuscodes;

#endif
