#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

#include "../inc/queue_as_linked_list.h"
#include "../inc/queue_as_array.h"
#include "../inc/errors.h"
#include "../inc/data_input.h"

#define T (float)rand()/RAND_MAX
#define P (float)rand()/RAND_MAX

//Обновление времени
void time_refresh(float *time, float t1, float t2)
{
    *time = (t2 - t1) * (float)(T) + t1;
}

//Выполнение задания для связного списка
void task_execution()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List list;
    init_queue_ll(&list);

    //Время поступления заявки
    float t1_in = 0.0;
    float t2_in = 6.0;
    float time_in = 0.0;

    //Время обработки заявки
    float t1_ser = 0.0;
    float t2_ser = 3.0;
    float time_ser = 0.0;

    //Начальный рассчёт
    time_in = (t2_in - t1_in) * (float)(T) + t1_in;
    time_ser = (t2_ser - t1_ser) * (float)(T) + t1_ser;

    int count_in = 0; //Вошедшие заявки
    int count_in_return  = 0; //Вошедшия заявки, которые уже были в ОА
    int count_out = 0; //Вышедшие заявки
    int count_out_forever = 0; //Вышедшие заявки, которые уже не вернулись

    double time_wait = 0; //Время простоя

    double time = 0; //Общее время

    int count_app = 0; //Счётчик циклов

    int flag_print = 0; //Для печати

    int sum_len = 0; //Длина очереди

    while (count_out_forever < 1000)
    {
        if ((count_out_forever) % 100 == 0 && count_out_forever != 0 && flag_print == 0)
        {
            printf("Количество обработанных заявок: %d\n", count_out_forever);
            printf("Текущая длина очереди: %d\n", list.size);
            printf("Средняя длина очереди: %f\n\n", (float)sum_len / count_app);
            flag_print = 1;
        }

        //Добавление быстрее
        if (time_ser - time_in > 0)
        {
            time_ser -= time_in;
            push_back_ll(&list, 1);

            //Поступила новая заявка
            count_in++;

            //Общее время моделирования
            time+= time_in;

            //Обновление времени
            time_refresh(&time_in, t1_in, t2_in);


        }

        //Обработка быстрее и очередь непустая
        else if (is_empty(&list) == 0)
        {
            time_in-= time_ser;
            pop_front_ll(&list);

            //Прибавились вышедшие заявки
            count_out++;

            //Заявка возвращается
            if (P < 0.8 + 0.00001)
            {
                push_back_ll(&list, 1);

                count_in++;
                count_in_return++;


            }
            //Заявка ушла навсегда
            else
            {
                count_out_forever++;
                flag_print = 0;

            }
            time+= time_ser;
            time_refresh(&time_ser, t1_ser, t2_ser);
        }

        //Обработка быстрее, но очередь пустая
        else
        {
            time_in -= time_ser;
            time_wait += time_ser;
            time_refresh(&time_ser, t1_ser, t2_ser);

        }
        sum_len += list.size;
        count_app++;

    }
    time+=time_wait;

    printf("------------------------------------------\n");
    printf("Ожидаемое время моделирования: 3000 е.в.\n");
    printf("Общее время моделирования: %f е.в.\n\n", time);

    printf("Ожидаемое время простоя: 500 е.в\n");
    printf("Время простоя аппарата: %f е.в.\n\n", time_wait);

    printf("Количество вошедших заявок: %d, из них повторно возвращенные заявки: %d\n", count_in, count_in_return);
    printf("Количество вышедших заявок: %d, из них не вернувшихся обратно: %d\n\n", count_out, count_out_forever);

    printf("Средняя длина очереди: %f\n", (float)sum_len / count_app);
    printf("Время среднего пребывания заявки в очереди: %f е.в.\n", time/count_out * (float)sum_len / count_app);

    printf("Количество cрабатываний ОА: %d\n\n", count_out);

    printf("Проверка работы:\n");
    printf("Погрешность по вошедшим заявкам: %f%%\n", 100*fabs(((count_in-count_in_return - time/3)/(time/3))));
    printf("Погрешность по вышедшим заявкам: %f%%\n\n", 100*fabs((time - 3000)/3000));
}

//Выполнение задания для кольцевого массива
void task_execution_sa()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    queue_sa array;
    init_queue_sa(&array);

    //Время поступления заявки
    float t1_in = 0.0;
    float t2_in = 6.0;
    float time_in = 0.0;

    //Время обработки заявки
    float t1_ser = 0.0;
    float t2_ser = 1.0;
    float time_ser = 0.0;

    //Начальный рассчёт
    time_in = (t2_in - t1_in) * (float)(T) + t1_in;
    time_ser = (t2_ser - t1_ser) * (float)(T) + t1_ser;

    int count_in = 0;
    int count_in_return  = 0;
    int count_out = 0;
    int count_out_forever = 0;

    double time_wait = 0;

    double time = 0;
    int flag_print = 0;

    int sum_len = 0;

    int count_app = 0;
    while (count_out_forever < 1000)
    {
        if ((count_out_forever) % 100 == 0 && count_out_forever != 0 && flag_print == 0)
        {
            printf("Количество обработанных заявок: %d\n", count_out_forever);
            printf("Текущая длина очереди: %d\n", array.size);
            printf("Средняя длина очереди: %f\n\n", (float)sum_len / count_app);
            //count_app = 0;
            //sum_len = 0;
            flag_print = 1;
        }

        //Добавление быстрее
        if (time_ser - time_in > 0)
        {
            time_ser -= time_in;
            push_back_sa(&array, 1);

            //Поступила новая заявка
            count_in++;

            //Общее время моделирования
            time+= time_in;

            //Обновление времени
            time_refresh(&time_in, t1_in, t2_in);


        }

        //Обработка быстрее и очередь непустая
        else if (is_empty_sa(&array) == 0)
        {
            time_in-= time_ser;
            pop_front_sa(&array);

            //Прибавились вышедшие заявки
            count_out++;

            //Заявка возвращается
            if (P < 0.8 + 0.00001)
            {
                push_back_sa(&array, 1);

                count_in++;
                count_in_return++;


            }
            //Заявка ушла навсегда
            else
            {
                count_out_forever++;
                flag_print = 0;

            }
            time+= time_ser;
            time_refresh(&time_ser, t1_ser, t2_ser);
        }

        //Обработка быстрее, но очередь пустая
        else
        {
            time_in -= time_ser;
            time_wait += time_ser;
            time_refresh(&time_ser, t1_ser, t2_ser);

        }
        sum_len += array.size;
        count_app++;

    }
    time+=time_wait;

    printf("------------------------------------------\n");
    printf("Ожидаемое время моделирования: 3000 е.в.\n");
    printf("Общее время моделирования: %f е.в.\n\n", time);

    printf("Ожидаемое время простоя: 500 е.в\n");
    printf("Время простоя аппарата: %f е.в.\n\n", time_wait);

    printf("Количество вошедших заявок: %d, из них повторно возвращенные заявки: %d\n", count_in, count_in_return);
    printf("Количество вышедших заявок: %d, из них не вернувшихся обратно: %d\n\n", count_out, count_out_forever);

    printf("Средняя длина очереди: %f\n", (float)sum_len / count_app);
    printf("Время среднего пребывания заявки в очереди: %f е.в.\n", time/count_out * (float)sum_len / count_app);

    printf("Количество cрабатываний ОА: %d\n\n", count_out);

    printf("Проверка работы:\n");
    printf("Погрешность по вошедшим заявкам: %f%%\n", 100*fabs(((count_in-count_in_return - time/3)/(time/3))));
    printf("Погрешность по вышедшим заявкам: %f%%\n\n", 100*fabs((time - 3000)/3000));
}

