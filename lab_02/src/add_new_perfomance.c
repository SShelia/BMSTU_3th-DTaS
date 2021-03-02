#include <Windows.h>
#include "../inc/add_new_perfomance.h"

void str_normallization(char *str)
{
    int n = strlen(str);
    if (str[n - 1] == '\n' || str[n - 1] == '\r')
        str[n - 1] = '\0';
}


int str_read(char *str, int len_of_str)
{
    int code = ok;
    int i = 0, c;
    while (i < len_of_str && (c = getchar()) !='\n')
    {
        str[i] = c;
        i++;
    }

    if (i == 0)
        code = empty_input;
    else if ((int)str[0] == 32)
        code = input_error;
    else if (c != '\n')
    {
        code = input_error;
        while ((c = getchar()) != '\n');
    }
    else if (c == '\n')
    {
        str[i] = '\0';
    }

    return code;

}


int number_read(int *number)
{
    int code = ok;
    int c;
    int i = 0;
    int array[20];
    while ((c = getchar()) <= 57 && c >= 48)
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

int str_input(char *new_str, int len)
{
    int code = ok;
    code = str_read(new_str, len);
    if (code == ok)
        str_normallization(new_str);
    else
        printf("\nНекорректный ввод!\n");
    return code;
}

int number_input(int *number)
{
    int code = ok;
    *number = 0;

    code = number_read(number);
    if (code != ok)
    {
         printf("\nНекорреткный ввод.\n");
         fflush(stdin);
    }
    return code;
}

int add_new_theatre(struct repertoire_of_theatres *theatres, int *number_of_perfomance)
{
    int code = ok;
    setbuf(stdin, NULL);

    printf("\nВведите название театра (до 50 знаков): ");
    code = str_input(theatres[*number_of_perfomance].theatre_name, LEN_THEATRE_NAME);
    while (code != ok)
    {
        printf("\nВведите название театра (до 50 знаков): ");
        code = str_input(theatres[*number_of_perfomance].theatre_name, LEN_THEATRE_NAME);

    }


    printf("Введите название спектакля(до 40 знаков): ");
    code = str_input(theatres[*number_of_perfomance].perfomance,LEN_PERFOMANCE_NAME);
    while (code != ok)
    {
        printf("\nВведите название спектакля(до 40 знаков): ");
        code = str_input(theatres[*number_of_perfomance].perfomance,LEN_PERFOMANCE_NAME);
    }


    printf("Введите имя режиссера(до 25 знаков): ");
    code = str_input(theatres[*number_of_perfomance].producer, LEN_PRODUCER_NAME);
    while (code != ok)
    {
        printf("\nВведите имя режиссера(до 25 знаков): ");
        code = str_input(theatres[*number_of_perfomance].producer, LEN_PRODUCER_NAME);

    }


    printf("Введите минимальную цену за билет (целое неотрицательное число): ");
    code = number_input(&theatres[*number_of_perfomance].min_ticket_price);
    while (code != ok)
    {
        printf("\nВведите минимальную цену за билет (целое неотрицательное число): ");
        code = number_input(&theatres[*number_of_perfomance].min_ticket_price);

    }


    printf("Введите максмальную цену за билет (целое неотрицательное число): ");
    code = number_input(&theatres[*number_of_perfomance].max_ticket_price);
    if (code == ok && theatres[*number_of_perfomance].max_ticket_price < theatres[*number_of_perfomance].min_ticket_price)
    {
       printf("\nНекорреткный ввод.\n\n");
       code = input_error;
    }
    while (code != ok)
    {
       printf("\nВведите максимальную цену за билет (целое неотрицательное число): ");
       code = number_input(&theatres[*number_of_perfomance].max_ticket_price);
       if (code == ok && theatres[*number_of_perfomance].max_ticket_price < theatres[*number_of_perfomance].min_ticket_price)
       {
          printf("\nНекорреткный ввод.\n");
          code = input_error;
       }

    }


    printf("\n0 - Детский\n1 - Взрослый\n2 - Музыкальный\n\nКакой тип спектакля?: ");
    int k = 0;
    code = number_read(&k);
    if (code != ok || k < 0 || k > 2)
    {
        printf("\nНекорректный ввод.\n");
        code = answer_error;
    }
    else
        theatres[*number_of_perfomance].type = k;
    fflush(stdin);

    while (code != ok)
    {
        printf("\n0 - Детский\n1 - Взрослый\n2 - Музыкальный\n\nКакой тип спектакля?: ");
        k = 0;
        code = number_read(&k);
        if (code != ok || k < 0 || k > 2)
        {
            printf("\nНеправильный ввод варианта ответа.\n");
            code = answer_error;
        }
        else
            theatres[*number_of_perfomance].type = k;
        fflush(stdin);
    }

    switch(theatres[*number_of_perfomance].type)
    {

        case childlike:
    {
            printf("\nВведите минимальный возраст(целое неотрицательное число <18): ");
            code = number_input(&theatres[*number_of_perfomance].choice.childlike.age);

            if (code == ok && theatres[*number_of_perfomance].choice.childlike.age >= 18)
            {
                printf("\nНекорректный ввод.\n");
                code = input_error;
            }

            while (code != ok)
            {
               printf("\nВведите минимальный возраст(целое неотрицательное число <18): ");
               code = number_input(&theatres[*number_of_perfomance].choice.childlike.age);
               if (code == ok && theatres[*number_of_perfomance].choice.childlike.age >= 18)
               {
                   printf("\nНекорректный ввод.\n");
                   code = input_error;
               }
            }


            printf("\n0 - сказка\n1 - пьеса\n\nКакого жанра спектакль?: ");
            int k = 0;
            code = number_read(&k);
            if (k > 1 || code != ok)
            {
                printf("\nНеправильный ввод варианта ответа.\n");
                code = answer_error;
            }
            else
            {
                *number_of_perfomance+=1;
                theatres[*number_of_perfomance - 1].choice.childlike.type = k;
            }

            while (code != ok)
            {
                printf("\n0 - сказка\n1 - пьеса\n\nКакого жанра спектакль?: ");
                k = 0;
                code = number_read(&k);
                if (k > 1 || code != ok)
                {
                    printf("\nНеправильный ввод варианта ответа.\n");
                    code = answer_error;
                }
                else
                {
                    *number_of_perfomance+=1;
                    theatres[*number_of_perfomance - 1].choice.childlike.type = k;
                }
            }


            break;
    }
        case adult:
        {
            printf("\n0 - Пьеса\n1 - Драма\n2 - Комедия\n\nКакого жанра спектакль?: ");

            int k = 0;
            code = number_read(&k);
            if (k > 2 || code != ok)
            {
                printf("\nНеправильный ввод варианта ответа.\n");
                code = answer_error;
            }
            else
            {
                *number_of_perfomance+=1;
                theatres[*number_of_perfomance - 1].choice.adult.type = k;

            }

            while (code != ok)
            {
                printf("\n0 - Пьеса\n1 - Драма\n2 - Комедия\n\nКакого жанра спектакль?: ");

                k = 0;
                code = number_read(&k);
                if (k > 2 || code != ok)
                {
                    printf("\nНеправильный ввод варианта ответа.\n");
                    code = answer_error;
                }
                else
                {

                    theatres[*number_of_perfomance].choice.adult.type = (int)k;
                    *number_of_perfomance+=1;
                }

            }


            break;
        }

        case musical:
            setbuf(stdin, NULL);

            printf("Введите имя композитора (до 25 символов): ");
            code = str_input(theatres[*number_of_perfomance].choice.musical.composer, LEN_COMPOSER_NAME);
            while (code != ok)
            {
                printf("\nВведите имя композитора (до 25 символов): ");
                code = str_input(theatres[*number_of_perfomance].choice.musical.composer, LEN_COMPOSER_NAME);
            }


            printf("Введите страну (до 15 символов): ");
            code = str_input(theatres[*number_of_perfomance].choice.musical.country,LEN_COUNTRY_NAME);
            while (code != ok)
            {
                printf("\nВведите страну (до 15 символов): ");
                code = str_input(theatres[*number_of_perfomance].choice.musical.country,LEN_COUNTRY_NAME);
            }


            printf("Введите возраст(целое неотрицательное число): ");
            code = number_input(&theatres[*number_of_perfomance].choice.musical.min_age);

            while (code != ok)
            {
               printf("\nВведите возраст(целое неотрицательное число): ");
               code = number_input(&theatres[*number_of_perfomance].choice.musical.min_age);
            }


            printf("Введите длительность(целое положительное число): ");
            code = number_input(&theatres[*number_of_perfomance].choice.musical.duration);
            if (code == ok && theatres[*number_of_perfomance].choice.musical.duration == 0)
            {
                printf("\nНекорреткный ввод!\n");
                code = input_error;
            }

            while (code != ok)
            {
               printf("\nВведите длительность(целое положительное число): ");
               code = number_input(&theatres[*number_of_perfomance].choice.musical.duration);
               if (code == ok && theatres[*number_of_perfomance].choice.musical.duration == 0)
               {
                   printf("\nНекорреткный ввод!\n");
                   code = input_error;
               }
            }

            *number_of_perfomance+=1;
            break;

        }

    fflush(stdin);
    return code;
}
