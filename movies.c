//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mc
{
  int i, j;
}mc;

typedef struct graf
{
   int n, m;
   char **noduri;
   mc *muchii;
} graf;

graf *init(int);
void free_graf(graf*);
graf *add_node(graf*, char*);
graf *add_edge(graf*, int, int);

void citire1(char*);

int main()
{
    graf *g = init(5);
    g = add_node(g, "actor1");
    g = add_node(g, "actor2");
    g = add_node(g, "actor3");
    g = add_node(g, "actor4");
    g = add_node(g, "actor5");
    g = add_edge(g, 0, 2);
    g = add_edge(g, 0, 3);
    g = add_edge(g, 1, 2);
    g = add_edge(g, 4, 5);
    free(g);
//    citire1("test.in");
    return 0;
}

void citire1(char *filename)
{
    FILE *in = fopen(filename, "r");
    int nr_filme;
    fscanf(in, "%d\n", &nr_filme);
    while(nr_filme)
    {
        char *nume_film = (char*) malloc(256);
        int nr_actori, i;
        fscanf(in, "%255[^\n]", nume_film);
        fscanf(in, "%d\n", &nr_actori);
        for(i = 0; i < nr_actori; i++){
            char *buffer = (char*) malloc(256);
            fscanf(in, "%255[^\n]\n", buffer);
            // adauga in graf
            printf("%s\n", buffer);
            // elibereaza memorie odata ce nu mai am nevoie de ea
            free(buffer);
        }
        --nr_filme;
        // elibereaza memorie odata ce nu mai am nevoie de ea
        free(nume_film);
    }
    fclose(in);
}

graf *init(int n)
{
    int i;
    graf *new = (graf*)malloc(sizeof (graf));
    new->n = n;
    new->m = 0;
    new->noduri = (char**) malloc(sizeof (char*) * n);
    for(i = 0; i < n; i++)
        new->noduri[i] = (char*) malloc(255);
    new->muchii = (mc*)malloc(sizeof (mc));
    return new;
}

void free_graf(graf *g)
{
    int i;
    free(g->muchii);
    g->muchii = NULL;
    for(i = 0; i < g->n; i++)
    {
        free(g->noduri[i]);
        g->noduri[i] = NULL;
    }
    free(g->noduri);
    g->noduri = NULL;
    free(g);
    g = NULL;
}

graf *add_node(graf *g, char *node_name)
{
    g->n++;
    g->noduri = realloc(g->noduri, g->n * sizeof (char*));
    g->noduri[g->n-1] = malloc(255);
    strcpy(g->noduri[g->n-1], node_name);
    return g;
}

graf *add_edge(graf *g, int i, int j)
{
    if(i > g->n || j > g->n)
    {
        printf("eroare: nu exista atatea noduri.\n");
        return g;
    }
    g->m++;
    g->muchii = realloc(g->muchii, g->m * sizeof (mc));
    g->muchii[g->m-1].i = i;
    g->muchii[g->m-1].j = j;
    return g;
}