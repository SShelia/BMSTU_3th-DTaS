#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "division.h"


//Умножение на цифру
int multiplication_by_number(struct number *divider, int multiplier, int *result, int size_of_divider_mantisa)
{
    int overflow = 0;
    int excess = (divider->mantisa_field[size_of_divider_mantisa - 1] * multiplier) / 10;
    result[size_of_divider_mantisa - 1] = (divider->mantisa_field[size_of_divider_mantisa - 1] * multiplier) % 10;

    if (excess != 0 && size_of_divider_mantisa == 1)
    {
        result[1] = result[0];
        result[0] = excess;
        overflow = 1;
    }

    else
    {
        int i = size_of_divider_mantisa - 2;
        while (i >= 0)
        {
            result[i] = (divider->mantisa_field[i] * multiplier + excess) % 10;
            excess = (divider->mantisa_field[i] * multiplier + excess) / 10;
            i--;
        }

        if (excess > 0)
        {
            for (int i = size_of_divider_mantisa;  i > 0; i--)
                result[i] = result[i - 1];
            result[0] = excess;
            overflow = 1;
        }
    }
    return size_of_divider_mantisa + overflow;
}

//Вычитание
int subtraction(struct number *dividend, int *result, int action_length)
{
    for (int i = action_length - 1; i >=0; i--)
    {
        dividend->mantisa_field[i] = dividend->mantisa_field[i] - result[i];
        if (dividend->mantisa_field[i] < 0)
        {
            dividend->mantisa_field[i] = (dividend->mantisa_field[i] + 10) % 10;
            dividend->mantisa_field[i - 1] -=1;
        }
    }

    int number_of_zeroes = 0;
    while (dividend->mantisa_field[number_of_zeroes] == 0 && number_of_zeroes <= action_length - 1)
        number_of_zeroes++;

    return number_of_zeroes;
}

//Сравнение делимого и делителя
int compare_the_numbers(struct number *dividend, struct number *divider, int begin, int end)
{

    for (int i = begin; i < end; i++)
    {
        if (dividend->mantisa_field[i] < divider->mantisa_field[i])
            return 1;
        else if (dividend->mantisa_field[i] > divider->mantisa_field[i])
            return 0;
    }
    return 0;
}

//Сравнение результата умножения и делимого
int  comparison_with_the_result_of_multiplication(struct number *dividend, int *result, int begin, int end)
{

    for (int i = begin; i < end; i++)
    {
        if (dividend->mantisa_field[i] < result[i])
            return 1;
        else if (dividend->mantisa_field[i] > result[i])
            return 0;
    }
   return 0;
}


//Подсчёт поля результата
void find_order_of_result(struct number *dividend, struct number *divider, struct number *division_result,int *size_of_divider_mantisa, int *size_of_dividend_mantisa)
{
    division_result->order =  (dividend->order - *size_of_dividend_mantisa)  - (divider->order - *size_of_divider_mantisa);
}


//Деление
int division(struct number *dividend, struct number *divider, struct number *division_result, int *size_of_dividend_mantisa, int *size_of_divider_mantisa,int *size_of_result_mantisa)
{
    int code = ok;

    find_order_of_result(dividend, divider, division_result, size_of_divider_mantisa, size_of_dividend_mantisa);

    int len_result;
    int result[31];


    //Обнуляем поля делимого
    for (int i = *size_of_dividend_mantisa; i < 31; i++)
        dividend->mantisa_field[i] = 0;


    int zero_error = *size_of_dividend_mantisa;
    while (*size_of_dividend_mantisa > 0 && *size_of_result_mantisa <=31)
    {

        if (*size_of_dividend_mantisa > *size_of_divider_mantisa || (*size_of_dividend_mantisa == *size_of_divider_mantisa
                && !compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa)))
        {
            //Обработка "спускание" цифр
            int p = 0;
            while ((zero_error < *size_of_divider_mantisa))
            {
                p++;
                zero_error++;
            }

            if (p != 0 && (zero_error == *size_of_divider_mantisa) && !(compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa))) p--;

            if (p > 0)
            {
                for (int i = *size_of_result_mantisa; i < *size_of_result_mantisa + p; i ++)
                    division_result->mantisa_field[i] = 0;
                *size_of_result_mantisa = *size_of_result_mantisa + p;
            }

            //Проверка длины делителя
            int lack = 0;
            if (compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa)) lack = 1;


            //Поиск подходящей цифры
            int multiplier = 1;
            len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            while (*size_of_divider_mantisa + lack > len_result ||(*size_of_divider_mantisa + lack == len_result &&
                                                                   comparison_with_the_result_of_multiplication(dividend, result, 0, len_result) == 0 ))
            {
                multiplier++;
                len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            }

            if (multiplier > 1) multiplier--;
            len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            //Подготовка к вычитанию
            if (len_result < *size_of_divider_mantisa + lack)
            {
                for (int i = len_result; i > 0; i--)
                    result[i] = result[i-1];
                result[0] = 0;
            }

            //Вычитание
            int number_of_zero = subtraction(dividend, result, *size_of_divider_mantisa + lack);

            //Удаление лидирующих нулей в делимом
            for (int i = 0; i < *size_of_dividend_mantisa - number_of_zero; i++)
                dividend->mantisa_field[i] =  dividend->mantisa_field[number_of_zero + i];
            *size_of_dividend_mantisa -= number_of_zero;

            for (int i = *size_of_dividend_mantisa; i < 31; i++)
                dividend->mantisa_field[i] = 0;

            //Добавлеение результата
            division_result->mantisa_field[*size_of_result_mantisa] = multiplier;
            *size_of_result_mantisa+=1;


            //Подготовка к следующему шагу
            if (*size_of_dividend_mantisa < *size_of_divider_mantisa || (*size_of_dividend_mantisa == *size_of_divider_mantisa
                                                                         && compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa)))
            {

                int l = *size_of_dividend_mantisa - (*size_of_divider_mantisa + lack - number_of_zero);
                division_result->order = division_result->order + l + *size_of_result_mantisa;
                for (int i = *size_of_result_mantisa; i < *size_of_result_mantisa + l; i ++)
                     division_result->mantisa_field[i] = 0;
                *size_of_result_mantisa +=l;
            }

            else
                zero_error = *size_of_divider_mantisa + lack - number_of_zero;

        }

        else
        {

            //Обработка "спускание" цифр
            int p = 0;
            while ((*size_of_dividend_mantisa < *size_of_divider_mantisa) ||
                   ((*size_of_dividend_mantisa == *size_of_divider_mantisa) && (compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa))))
            {
                *size_of_dividend_mantisa+=1;
                p++;
            }

            if ( p +  *size_of_result_mantisa >30) break;
            //Добавление нулей в резульат
            for (int i = *size_of_result_mantisa; i < *size_of_result_mantisa + p - 1; i ++)
                 division_result->mantisa_field[i] = 0;
            *size_of_result_mantisa +=( p - 1);

            //Проверка делителя
            int lack = 0;
            if (compare_the_numbers(dividend, divider, 0, *size_of_divider_mantisa)) lack = 1;


            //Поиск множителя
            int multiplier = 1;
            len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            while (*size_of_divider_mantisa + lack > len_result ||(*size_of_divider_mantisa + lack == len_result &&
                                                                   comparison_with_the_result_of_multiplication(dividend, result, 0, len_result) == 0 ))
            {
                multiplier++;
                len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            }
            if (multiplier > 1) multiplier--;
            len_result = multiplication_by_number(divider, multiplier, result, *size_of_divider_mantisa);

            //Подготовка к вычитанию
            if (len_result < *size_of_divider_mantisa + lack)
            {
                for (int i = len_result; i > 0; i--)
                    result[i] = result[i-1];
                result[0] = 0;
            }

            //Вычитание
            int number_of_zero = subtraction(dividend, result, *size_of_divider_mantisa + lack);

            for (int i = 0; i < *size_of_dividend_mantisa - number_of_zero; i++)
                dividend->mantisa_field[i] =  dividend->mantisa_field[number_of_zero + i];
            *size_of_dividend_mantisa -= number_of_zero;

            for (int i = *size_of_dividend_mantisa; i < 31; i++)
                dividend->mantisa_field[i] = 0;

            division_result->mantisa_field[*size_of_result_mantisa] = multiplier;
            *size_of_result_mantisa+=1;


            //Уничтожение лидирующих нулей
            int num_of_zero = 0;
            while (division_result->mantisa_field[num_of_zero] == 0)
                num_of_zero++;

            int num_of_other_numbers = *size_of_result_mantisa - num_of_zero;

            if (division_result->mantisa_field[0] == 0)
            {
                for (int i = 0; i < num_of_other_numbers; i++)
                    division_result->mantisa_field[i] = division_result->mantisa_field[num_of_zero + i];

                *size_of_result_mantisa = num_of_other_numbers;
                division_result->order -= num_of_zero;
            }

        }
    }


    //Проверка на переполнение
    if (*size_of_result_mantisa == 31 || *size_of_result_mantisa == 30)
    {
    
        if (division_result->mantisa_field[*size_of_result_mantisa - 1] >= 5)
        {
            int excess = (division_result->mantisa_field[*size_of_result_mantisa - 2] + 1) / 10;
            division_result->mantisa_field[*size_of_result_mantisa - 2] = (division_result->mantisa_field[*size_of_result_mantisa - 2] + 1) %10;


            int i = *size_of_result_mantisa  - 3;
            while (excess != 0 && i >= 0)
            {
                int l = division_result->mantisa_field[i];
                division_result->mantisa_field[i] = (division_result->mantisa_field[i] + excess) % 10;
                excess = (l + excess) / 10;
                i--;
            }


            if (i == -1 && excess > 0)
            {
                code = overflow;
                return code;
                /*
                for (int i = *size_of_result_mantisa - 1;  i > 0; i--)
                    division_result->mantisa_field[i] = division_result->mantisa_field[i - 1];
                division_result->mantisa_field[0] = excess;
                *size_of_result_mantisa += 1;
                */
            }
        *size_of_result_mantisa-=1;
        }
    }


    //Проверка на переполнение порядка
    if (division_result->order >99999 || division_result->order < -99999 )
    {
        code = overflow;
        return code;
    }


    //Определение знака мантиссы
    division_result->mantisa_sign = dividend->mantisa_sign * divider->mantisa_sign;
    return 0;

}
