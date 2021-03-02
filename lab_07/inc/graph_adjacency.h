#ifndef GRAPH_ADJACENCY_H
#define GRAPH_ADJACENCY_H

typedef struct list_graph
{
    int value;
    int path_length;
    struct list_graph *next;
}list_graph;

void push_back(list_graph **list, int set_path_length, int value);
void graph_adj_init(list_graph **list, int size);
void destruct(list_graph **head);

#endif // GRAPH_ADJACENCY_H
