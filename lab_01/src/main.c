#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#include "typedefs_and_struct.h"
#include "adding_number_to_structure.h"
#include "division.h"
#include "number_normallization.h"

void output_number(struct number *output_number, int size_of_output_number)
{
    if (output_number->mantisa_sign == 1) printf("+");
    else printf("-");

    printf("0.");
    for (int i = 0; i < size_of_output_number; i++)
        printf("%d", output_number->mantisa_field[i]);

    printf("e");
    if (output_number->order > 0) printf("+");
    printf("%d", output_number->order);
}

int main()
{
    setbuf(stdout, NULL);
    printf("This program divides an integer by a real number.\n\n");
    printf("The divisible is entered in the format (+/-)m, where m<=30. \nThe divisor is entered in the format (+/-)w.n(e/E)k, where w + n < = 30, k < = 5\n");
    printf("The division result is output in the format (+/-)d.f(e/E)q, where d + f < = 31, q < = 6\n\n");
    printf("                            +123451234512345123451234512345e+12345\n");
    printf("   Enter a divisible value: ");

    //Ввод делимого
    struct number dividend;
    int size_of_dividend_mantisa = 0;
    int error = adding_dividend_to_structere(&dividend, &size_of_dividend_mantisa);

    //Уничтожение лидируцующих нулей
    if (error == ok)
    {
        int number_of_zero = 0;
        while (dividend.mantisa_field[number_of_zero] == 0)
            number_of_zero++;

        int number_of_other_numbers = size_of_dividend_mantisa - number_of_zero;

        if (dividend.mantisa_field[0] == 0)
        {
            for (int i = 0; i < number_of_other_numbers; i++)
                dividend.mantisa_field[i] = dividend.mantisa_field[number_of_zero + i];

            size_of_dividend_mantisa = number_of_other_numbers;
            dividend.order -= number_of_zero;
        }
    }



    //Ввод делителя
    struct number divider;
    int size_of_divider_mantisa = 0, size_of_divider_order = 0;
    if (error == ok )
    {
        printf("         Enter the divisor: ");
        error = adding_divider_to_structere(&divider, &size_of_divider_mantisa, &size_of_divider_order);
        //Нормализация делмого
        shift_point(&divider, &size_of_divider_mantisa);
        number_normalization(&divider, &size_of_divider_order);
    }



    //Проверка деления на 0
    if (error == ok)
    {
        if (dividend.mantisa_field[0] == 0 && size_of_dividend_mantisa <= 0)
        {
            if (divider.mantisa_field[0] == 0 && size_of_divider_mantisa <= 0)
            {
                printf("       Division cannot be made.");
                error = division_by_zero;
            }
            else
            {
                printf("The result of the division: +0.0e0");
                error = stop_the_division;
            }
        }
        else if (divider.mantisa_field[0] == 0 && size_of_divider_mantisa <= 0)
        {
            printf("   Division cannot be made.");
            error = division_by_zero;
        }

    }

    //Вывод нормализованного делимого и делителя
    if (error == ok)
    {      
        printf("\n  The normalized divisible: ");
        output_number(&dividend, size_of_dividend_mantisa);

        printf("\n    The normalized divisor: ");
        output_number(&divider, size_of_divider_mantisa);
    }
    else if (error != division_by_zero && error!= stop_the_division)
        printf("           Incorrect input.");


    if (error == ok)
    {
        //Поиск результата деления
        struct number result;
        int size_of_result_mantisa = 0;
        error = division(&dividend, &divider, &result, &size_of_dividend_mantisa, &size_of_divider_mantisa, &size_of_result_mantisa);

        if (error == ok)
        {
            //Вывод результата деления
            printf("\nThe result of the division: ");
            output_number(&result, size_of_result_mantisa);
        }
        else
            printf("\n                  Overflow. ");
    }

    return 0;
}
