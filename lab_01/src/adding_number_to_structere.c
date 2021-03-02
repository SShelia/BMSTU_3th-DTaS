#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "adding_number_to_structure.h"


int adding_dividend_to_structere(struct number *number_structure, int *i)
{

    int code = ok;
    number_structure->position_of_point = -1;

    //Считываем первый символ
    int ch = getchar();
    if (ch == minus)
        number_structure->mantisa_sign = -1;
    else if (ch == plus)
        number_structure->mantisa_sign = 1;

    else if (zero <= ch && ch <= nine)
    {
        number_structure->mantisa_sign = 1;
        number_structure->mantisa_field[0] = ch - 48;
        *i = *i + 1;
    }
    else
        code = incorrect_number_input;


    //Считывание остальных символов
    while (code == ok && (ch = getchar()) != '\n' && ch!=EOF  && *i <= 30)
    {
        if (zero <= ch && ch <= nine)
        {
            number_structure->mantisa_field[*i] = ch - 48;
            *i = *i + 1;
        }
        else
            code = incorrect_number_input;
    }

    if (*i >30 || *i<=0)
        code = incorrect_number_input;

    number_structure->order_sign = 1;
    number_structure->order = *i;


    /*Добавление поля порядка в виде массива
    if (*i / 10 != 0)
    {
        number_structure->order_field[1] = *i % 10;
        number_structure->order_field[0] = *i / 10;
        *j = 2;
    }
    else
    {
        number_structure->order_field[0] = *i % 10;
        *j = 1;
    }
    */

    return code;
}


int adding_divider_to_structere(struct number *number_structure, int *i, int *j)
{

    int code = ok;
    number_structure->position_of_point = -1;

    //Считываем первый символ
    int ch = getchar();
    if (ch == minus)
        number_structure->mantisa_sign = -1;
    else if (ch == plus)
        number_structure->mantisa_sign = 1;
    else if (ch == point)
    {
        number_structure->mantisa_sign = 1;
        number_structure->position_of_point = 1;
        number_structure->mantisa_field[0] = 0;
        *i = *i + 1;
    }
    else if (zero <= ch && ch <= nine)
    {
        number_structure->mantisa_sign = 1;
        number_structure->mantisa_field[0] = ch - 48;
        *i = *i + 1;
    }
    /*
    else if (ch == ex || ch == Ex)
    {
        *i = 1;
        number_structure->mantisa_field[0] = 1;
        code = missing_mantissa;
        number_structure->mantisa_sign = 1;
    }
    */
    else
        code = incorrect_number_input;


    //Считывание до экспоненты
    while ( (ch = getchar()) != '\n' && ch!=EOF  && code == ok && ch!= ex && ch!= Ex && *i <= 30)
    {
        if (ch == point)
        {
            //Проверка на отсутствие лишних точек
            if (number_structure->position_of_point == -1)
                number_structure->position_of_point = *i;
            else
                code = incorrect_number_input;

        }
        else if (zero <= ch && ch <= nine)
        {
            number_structure->mantisa_field[*i] = ch - 48;
            *i = *i + 1;
        }
        else
            code = incorrect_number_input;
    }


    //Считывание после экспоненты, если она есть
    if ((ch == ex || ch == Ex) && (code == ok))
    {
        /*
        if (code == missing_mantissa)
            code = ok;
        */

        ch = getchar();
        if (ch == minus)
            number_structure->order_sign = -1;

        else if (ch == plus)
            number_structure->order_sign = 1;

        else if (zero <= ch  && ch <= nine)
        {
            number_structure->order_sign = 1;
            number_structure->order_field[0] = ch - 48;
             *j = *j + 1;
        }
        else
            code = incorrect_number_input;


        while ((ch = getchar()) != '\n' && ch!=EOF && code == ok && *j <= 5)
        {
            if (zero <= ch  && ch <= nine)
            {
                number_structure->order_field[*j] = ch - 48;
                *j = *j + 1;
            }
            else
                code = incorrect_number_input;
        }
    }

    //Экспонента отсутсвует
    else if (code == ok)
    {
        number_structure->order_sign = 1;
        number_structure->order_field[0] = 0;
        *j = 1;
    }

    if (*i >30 || *j > 5 || *i<=0)
        code = incorrect_number_input;

    return code;
}


