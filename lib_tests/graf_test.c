//
// Created by David Bors on 14.05.2021.
//
#include <stdio.h>
#include "../libs/graf.h"
#include "../libs/util.h"

int main()
{
    graf *g = init_graf();
    g = add_node(g, "actor1");
    g = add_node(g, "actor2");
    g = add_node(g, "actor3");
    g = add_node(g, "actor4");
    g = add_node(g, "actor5");
    g = add_node(g, "actor6");
    g = add_node(g, "actor7");
    g = add_node(g, "actor8");
    g = add_node(g, "actor9");
    g = add_node(g, "actor10");
//    g = add_edge(g, 0, 1);
//    g = add_edge(g, 0, 2);
//    g = add_edge(g, 0, 3);
//    g = add_edge(g, 1, 3);
//    g = add_edge(g, 1, 5);
//    g = add_edge(g, 4, 5);
    g = add_edge(g, 0, 1);
    g = add_edge(g, 0, 2);
    g = add_edge(g, 1, 3);
    g = add_edge(g, 1, 4);
    g = add_edge(g, 2, 5);
    g = add_edge(g, 2, 6);
    g = add_edge(g, 7, 8);
    g = add_edge(g, 7, 9);
    g = add_edge(g, 8, 9);
//    list_print(g->muchii);
//    printf("\n");
//    printf("%d\n", is_edge(g, 0,2));
//    printf("%d %d\n", g->n, g->m);
    int i, nr;
    int *visited = (int*) calloc(g->n, sizeof (int));
    vector *productie = NULL;
    for(i = 0; i < g->n; i++)
    {
        if(!visited[i])
        {
            productie = bfs(g, i, visited, &nr);
            printf("%d\n", nr);
            vector_print(productie);
            printf("\n");
        }
    }

    destroy_graf(g);
    return 0;
}