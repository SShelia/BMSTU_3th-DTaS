#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "number_normallization.h"


void number_normalization(struct number *number_structure, int *len_order)
{

    number_structure->order = 0;
    for (int i = *len_order - 1; i >=0; i--)
        number_structure->order = number_structure->order+number_structure->order_field[i] * pow(10, *len_order - i - 1);

    if (number_structure->order_sign == -1)
        number_structure->order *= -1;

    number_structure->order += number_structure->position_of_point;

    /*
    if (number_structure->position_of_point * number_structure->order_sign >= 0)
       {
        if (number_structure->position_of_point < 0)
            number_structure->position_of_point*=-1;
        number_structure->order += number_structure->position_of_point;
       }
    else
        if (abs(number_structure->position_of_point) > abs(number_structure->order))
        {
            number_structure->order_sign*=-1;
            number_structure->order = abs(number_structure->position_of_point) - abs(number_structure->order);
        }
        else
            number_structure->order = abs(number_structure->order) - abs(number_structure->position_of_point);
    */
}

void shift_point(struct number *number_structure, int *len_mantisa)
{
    if (number_structure->position_of_point == -1)
        number_structure->position_of_point = *len_mantisa;

    int number_of_zero = 0;
    while (number_structure->mantisa_field[number_of_zero] == 0)
        number_of_zero++;

    int number_of_other_numbers = *len_mantisa - number_of_zero;

    if (number_structure->mantisa_field[0] == 0)
    {
        for (int i = 0; i < number_of_other_numbers; i++)
            number_structure->mantisa_field[i] =  number_structure->mantisa_field[number_of_zero + i];

        *len_mantisa = number_of_other_numbers;

        if (number_structure->position_of_point == 1)
            number_structure->position_of_point = -number_of_zero + 1;
        else
            number_structure->position_of_point = number_structure->position_of_point - number_of_zero;
    }
}




//Данная функция не используется, так как нашёлся более быстрый и удобный вариант.
void number_normalization_2(struct number *number_structure, int *len_order)
{
    //Складываем числа
    if (number_structure->position_of_point * number_structure->order_sign >= 0)
    {
        if (number_structure->position_of_point < 0) number_structure->position_of_point *= -1;

        int excess = (number_structure->order_field[*len_order - 1] + number_structure->position_of_point) / 10;
        number_structure->order_field[*len_order - 1] = (number_structure->order_field[*len_order - 1] + number_structure->position_of_point) % 10;

        if (excess != 0 && *len_order == 1)
        {
            number_structure->order_field[1] = number_structure->order_field[0];
            number_structure->order_field[0] = excess;
            *len_order += 1;
        }
        else
        {
            int i = *len_order - 2;
            while (excess != 0 && i >= 0)
            {
                int l = number_structure->order_field[i];
                number_structure->order_field[i] = (number_structure->order_field[i] + excess) % 10;
                excess = (l + excess) / 10;
                i--;
            }

            if (i == -1 && excess > 0)
            {
                for (int i = *len_order;  i > 0; i--)
                    number_structure->order_field[i] = number_structure->order_field[i - 1];
                number_structure->order_field[0] = excess;
                *len_order += 1;
            }
        }
    }

    //Вычитаем
    else
    {

        if (number_structure->position_of_point < 0) number_structure->position_of_point *= -1;

        //Для двузначного поля
        if (*len_order == 2)
        {
            //Поле больше чем позиция точки
            if (number_structure->order_field[*len_order - 2] > number_structure->position_of_point / 10 ||
                    (number_structure->order_field[*len_order - 2] == number_structure->position_of_point / 10 &&
                    number_structure->order_field[*len_order - 1] >= number_structure->position_of_point % 10))
            {
                number_structure->order_field[*len_order - 1] = number_structure->order_field[*len_order - 1] - number_structure->position_of_point % 10;
                if (number_structure->order_field[*len_order - 1] < 0)
                {
                    number_structure->order_field[*len_order - 1] += 10;
                    number_structure->order_field[*len_order - 2] -= 1;
                }
                number_structure->order_field[*len_order - 2] = number_structure->order_field[*len_order - 2] - number_structure->position_of_point / 10;

            }
            //Поле меньше чем позиция точки
            else
            {
                number_structure->order_sign *= -1;
                if (number_structure->position_of_point % 10 - number_structure->order_field[*len_order - 1] < 0)
                {
                    number_structure->order_field[*len_order - 2] = number_structure->position_of_point % 10 - number_structure->order_field[*len_order - 2] + 10;
                    number_structure->position_of_point -= 10;

                    number_structure->order_field[*len_order - 1] = number_structure->position_of_point / 10 - number_structure->order_field[*len_order - 1];

                }
                else
                {
                    number_structure->order_field[*len_order - 1] = number_structure->position_of_point % 10 - number_structure->order_field[*len_order - 1];
                    number_structure->order_field[*len_order - 2] = number_structure->position_of_point / 10 - number_structure->order_field[*len_order - 2];
                }
            }
        }

        //Для однозначного поля
        else if (*len_order == 1)
        {
            if (number_structure->order_field[*len_order - 1] >= number_structure->position_of_point)
                number_structure->order_field[*len_order - 1] = number_structure->order_field[*len_order - 1] - number_structure->position_of_point;

            else
            {
                number_structure->order_field[*len_order - 1] = number_structure->position_of_point - number_structure->order_field[*len_order - 1];
                number_structure->order_sign *= -1;
            }
        }

       //Размер поля больше 2 (точно больше позиции точки)
       else
        {

           number_structure->order_field[*len_order - 1] =  number_structure->order_field[*len_order - 1] -  number_structure->position_of_point % 10;
           if (number_structure->order_field[*len_order - 1] < 0)
           {
               number_structure->order_field[*len_order - 1] += 10;
               number_structure->order_field[*len_order - 2] -= 1;
           }

           number_structure->order_field[*len_order - 2] =  number_structure->order_field[*len_order - 2] -  number_structure->position_of_point / 10;

           if (number_structure->order_field[*len_order - 2] < 0)
           {
               number_structure->order_field[*len_order - 2] += 10;
               number_structure->order_field[*len_order - 3] = number_structure->order_field[*len_order - 3 ] - 1;
           }
        }
    }
}
