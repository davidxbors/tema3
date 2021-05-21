//
// Created by David Bors on 14.05.2021.
//

#ifndef TEMA3_GRAF_H
#define TEMA3_GRAF_H

#include "list.h"
#include "strvector.h"

#ifndef STDLIB_H
#define STBLIB_H
#include <stdlib.h>
#endif

typedef struct graf {
    int n, m;
    vector *noduri;
    mc *muchii;
} graf;

graf *init_graf()
{
    graf *g = (graf*)malloc(sizeof (graf));
    g->n = 0;
    g->m = 0;
    g->noduri = NULL;
    g->muchii = NULL;
    return g;
}

graf *add_node(graf *g, char *node_name)
{
    g->n++;
    g->noduri = append_string(g->noduri, node_name);
    return g;
}

graf *add_edge(graf *g, int i, int j)
{
    g->m++;
    g->muchii = append_list(g->muchii, i, j);
    return g;
}

void bfs(graf *g, int i, int j)
{
    bfs(g->)
}

void destroy_graf(graf *g)
{
    destroy_vector(g->noduri);
    destroy_list(g->muchii);
    free(g);
    g = NULL;
}

#endif //TEMA3_GRAF_H
