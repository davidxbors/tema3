//
// Created by David Bors on 14.05.2021.
//
#include <stdio.h>
#include "../libs/graf.h"

int main()
{
    graf *g = init_graf();
    g = add_node(g, "actor1");
    g = add_node(g, "actor2");
    g = add_node(g, "actor3");
    g = add_node(g, "actor4");
    g = add_node(g, "actor5");
    g = add_edge(g, 0, 1);
    g = add_edge(g, 0, 2);
    g = add_edge(g, 0, 3);
    g = add_edge(g, 1, 3);
    g = add_edge(g, 1, 5);
    g = add_edge(g, 4, 5);
    destroy_graf(g);
    return 0;
}