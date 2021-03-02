#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#include "../inc/errors.h"

//������ ����� ��� ��������
int number_read(int *number)
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

//���� ��������
int command_input(int min_size, int max_size)
{
    int code = ok;
    int command = 0;
    code = number_read(&command);

    if (command > max_size || command < min_size)
        code = input_error;

    while (code != ok)
    {
        printf("\n������������ ����.\n�����: ");
        command = 0;
        code = number_read(&command);
        if (command > max_size || command < min_size)
            code = input_error;;
    }

    return command;
}


//������ ����� ��� �����
int number_for_stack_read(int *number)
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

//���� ����� ��� �����
int number_for_stack_input()
{
    int code = ok;
    int number = 0;
    code = number_for_stack_read(&number);
    while (code != ok)
    {
        number = 0;
        printf("\n������������ ����. ������� ����� �����: ");
        code = number_read(&number);
    }

    return number;
}
