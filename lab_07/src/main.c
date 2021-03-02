#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "../inc/data_input.h"
#include "../inc/graph_adjacency.h"
#include "../inc/graph_matrix.h"
#include "../inc/find_cities.h"
#include "../inc/errors.h"
#include "../inc/output.h"
#include "../inc/time_measurement.h"

int main()
{
    setbuf(stdin, NULL);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int code = ok;
    int graph_size;

    list_graph **adj_graph;
    int **matrix_graph;

    printf("�������� ������ ������������� �����:\n"
           "1 - ������� ���� �� �����\n"
           "2 - ������ ����\n"
           "�����: ");
    int first_command = command_input(1, 2);

    if (first_command == 1)
    {
        FILE *f_in;
        f_in = fopen("in_01.txt", "r");

        code = matrix_graph_read_size(f_in, &graph_size);

        adj_graph = malloc(graph_size * sizeof(list_graph));
        graph_adj_init(adj_graph, graph_size);
        matrix_graph = allocate_matrix(graph_size, graph_size);

        graph_file_read(f_in, adj_graph, matrix_graph,  graph_size);
        fclose(f_in);


    }
    else
    {
        printf("\n������� ���������� ������ � �����(����� ������������� ����� < 100)): ");
        graph_size = command_input(1, 100);


        adj_graph = malloc(graph_size * sizeof(list_graph));
        graph_adj_init(adj_graph, graph_size);
        matrix_graph = allocate_matrix(graph_size, graph_size);


        printf("������� ������� ���������: \n");
        graph_user_read(adj_graph, matrix_graph, &graph_size);

        while (!check_matrix_symmetry(matrix_graph, graph_size))
        {
            printf("������������ ���� �������! ��������� ����!\n");
            for (int i = 0; i < graph_size; i++)
                destruct(&adj_graph[i]);

            free_matrix(matrix_graph, graph_size);
            graph_adj_init(adj_graph, graph_size);
            matrix_graph = allocate_matrix(graph_size, graph_size);

            graph_user_read(adj_graph, matrix_graph, &graph_size);

        }
        fflush(stdin);

    }

    printf("\n��������  ��������:\n"
           "1 - ������� ������������� ���������� ������\n"
           "2 - ��������� ������ � ������� ������� � ��������� ��������\n"
           "3 - ��������� ������ � ������� ������� � ��������� ��������\n"
           "4 - ��������� ������ � ������� ������ ��������� � ��������� ��������\n"
           "5 - ��������� ������ � ������� ������ ��������� � ��������� ��������\n"
           "6 - ������� ������� ����\n"
           "0 - �����\n"
           "�����: ");

   int command = command_input(0, 6);
    while (command != 0)
       {
           switch(command){

           case 1:
           {
               check_efficience();
               break;
           }

           case 2:
           {
               printf("\n������� �������, ������� ����� �������� ��������(<= %d): ", graph_size);
               int capital = command_input(1, graph_size);

               printf("������� T - ���������� ������ �������� ������ ���� ���� �� ������� (����� ��������������� ����� <= 100): ");
               int max_distance = command_input(1, 100);

               int *dextra_array = dextra_function_with_matrix(matrix_graph, capital, graph_size);
               search_suitable_cities(dextra_array, capital, graph_size, max_distance);

               FILE *f_result = fopen("result_graph.gv", "w");
               result_graph_file_print(f_result, matrix_graph, dextra_array, capital, graph_size, "result_graph");
               fclose(f_result);

               free(dextra_array);

               break;
           }

           case 3:
           {
               printf("\n������� �������, ������� ����� �������� ��������(<= %d): ", graph_size);
               int capital = command_input(1, graph_size);

               printf("������� T - ���������� ������ �������� ������ ���� ���� �� ������� (����� ��������������� ����� <= 100): ");
               int max_distance = command_input(1, 100);

               int *dextra_array =  bellman_function_with_matrix(matrix_graph, capital, graph_size);
               search_suitable_cities(dextra_array, capital, graph_size, max_distance);
               free(dextra_array);

               break;
           }

           case 4:
           {
               printf("\n������� �������, ������� ����� �������� ��������(<= %d): ", graph_size);
               int capital = command_input(1, graph_size);

               printf("������� T - ���������� ������ �������� ������ ���� ���� �� ������� (����� ��������������� ����� <= 100): ");
               int max_distance = command_input(1, 100);

               int *dextra_array = dextra_function_with_list(adj_graph, capital, graph_size);
               search_suitable_cities(dextra_array, capital, graph_size, max_distance);
               free(dextra_array);

               break;
           }

           case 5:
           {

               printf("\n������� �������, ������� ����� �������� ��������(<= %d): ", graph_size);
               int capital = command_input(1, graph_size);

               printf("������� T - ���������� ������ �������� ������ ���� ���� �� ������� (����� ��������������� ����� <= 100): ");
               int max_distance = command_input(1, 100);

               int *dextra_array =  bellman_function_with_list(adj_graph, capital, graph_size);
               search_suitable_cities(dextra_array, capital, graph_size, max_distance);
               free(dextra_array);

               break;
           }

           case 6:
           {
               matrix_output(matrix_graph, graph_size);
               list_output(adj_graph, graph_size);
               output(matrix_graph, graph_size);

               FILE *f_out = fopen("matrix_graph.gv", "w");
               matrix_graph_file_print(f_out, matrix_graph, graph_size, "matrix_graph");

               fclose(f_out);
               break;
           }

       }
       printf("\n��������  ��������:\n"
              "1 - ������� ������������� ���������� ������\n"
              "2 - ��������� ������ � ������� ������� � ��������� ��������\n"
              "3 - ��������� ������ � ������� ������� � ��������� ��������\n"
              "4 - ��������� ������ � ������� ������ ��������� � ��������� ��������\n"
              "5 - ��������� ������ � ������� ������ ��������� � ��������� ��������\n"
              "6 - ������� ������� ����\n"
              "0 - �����\n"
              "�����: ");

      command = command_input(0, 6);
    }

    return code;
}
