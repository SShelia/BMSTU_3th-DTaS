#include <stdio.h>

#include "../inc/input_size_and_command.h"
#include "../inc/errors.h"
#include <Windows.h>

int number_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];

    int sign = 1;
    if ((c = getchar()) == 45)
        sign = -1;
    else if (c == 43)
        sign = 1;
    else if (c <= 57 && c>= 48)
    {
        sign = 1;
        array[i] = c - 48;
        i++;
    }
    else
        code= input_error;

    while (code == ok && (c = getchar()) <= 57 && c >= 48 )
    {
        array[i] = c - 48;
        i++;
    }


    if (c == '\n' && i == 0)
        code= input_error;
    else if (c != '\n')
    {
        while ((c = getchar()) != '\n');
        code= input_error;
    }
    else
    {
        i--;
        int pow = 1;
        for (; i >=0; i--)
        {
            *number+=array[i] * pow;
            pow*=10;
        }
        *number*=sign;

    }
    return code;
}



int number_input(int *number)
{
    int code = ok;
    *number = 0;

    code = number_read(number);
    if (code != ok)
    {
         code = input_error;
         fflush(stdin);
    }
    return code;
}

int other_number_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];


    while ((c = getchar()) <= 57 && c >= 48 )
    {
        array[i] = c - 48;
        i++;
    }


    if (c == '\n' && i == 0)
        code= input_error;
    else if (c != '\n')
    {
        while ((c = getchar()) != '\n');
        code= input_error;
    }
    else
    {
        i--;
        int pow = 1;
        for (; i >=0; i--)
        {
            *number+=array[i] * pow;
            pow*=10;
        }
    }
    return code;
}

int other_number_input(int *number)
{
    int code = ok;
    *number = 0;

    code = other_number_read(number);
    if (code != ok)
    {
         code = input_error;
         fflush(stdin);
    }
    return code;
}


void input_size(int *lines, int *columns)
{
    int code = ok;
    printf("Введите количество строк: ");
    code = other_number_input(lines);

    if (code ==ok && *lines == 0)
        code = input_error;

    while (code != ok)
    {
        printf("\nНекорреткный ввод.Введите количество строк: ");
        code = other_number_input(lines);
        if (code ==ok && *lines == 0)
            code = input_error;

    }
    printf("Введите количество столбцов: ");
    code = other_number_input(columns);
    if (code ==ok && *columns == 0)
        code = input_error;
    while (code != ok)
    {
        printf("\nНекорреткный ввод.Введите количество столбцов: ");
        code = other_number_input(columns);
        if (code == ok && *columns == 0)
            code = input_error;
    }
}
