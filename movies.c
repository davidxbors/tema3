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
   int nsize, msize;
   char **noduri;
   mc *muchii;
} graf;

graf *init(int);
void free_graf(graf*);
graf *add_node(graf*, char*);
graf *add_edge(graf*, int, int);

void citire1(graf*, char*);

int main()
{
//    graf *g = init(5);
//    g = add_node(g, "actor1");
//    g = add_node(g, "actor2");
//    g = add_node(g, "actor3");
//    g = add_node(g, "actor4");
//    g = add_node(g, "actor5");
//    g = add_edge(g, 0, 2);
//    g = add_edge(g, 0, 3);
//    g = add_edge(g, 1, 2);
//    g = add_edge(g, 4, 5);
//    free(g);
      graf *g = init(0);
    citire1(g, "test.in");
//    citire1("test.in");
    return 0;
}

void citire1(graf *g, char *filename)
{
    FILE *in = fopen(filename, "r");
    int nr_filme;
    fscanf(in, "%d\n", &nr_filme);
    while(nr_filme)
    {
        char *nume_film = (char*) malloc(256);
        int nr_actori, i, j;

        fscanf(in, "%255[^\n]", nume_film);
        fscanf(in, "%d\n", &nr_actori);

        // toti actorii dintr-un film vor fii salvati aici si ii voi adauga in graf pe toti la final
        int *actori_film = (int*) calloc(nr_actori, sizeof (int));
        int acounter = 0;

        for(i = 0; i < nr_actori; i++){
            char *buffer = (char*) malloc(256);
            fscanf(in, "%255[^\n]\n", buffer);

            // adauga in graf
            printf("%s\n", buffer);
//            printf("nsize = %d; msize = %d\n", g->nsize, g->msize);
            g = add_node(g, buffer);
            actori_film[acounter++] = g->n - 1;

            // elibereaza memorie odata ce nu mai am nevoie de ea
            free(buffer);
        }
        --nr_filme;
        printf("In filmul %s joaca: ", nume_film);
        for(i = 0; i < nr_actori; i++)
            printf("%d ", actori_film[i]);
        printf("\n");
        // elibereaza memorie odata ce nu mai am nevoie de ea
        free(nume_film);
        free(actori_film);
    }
    fclose(in);
}

graf *init(int n)
{
    int i;
    graf *new = (graf*)malloc(sizeof (graf));
    new->n = n;
    new->m = 0;
    new->nsize = 1000;
    if(n > 1000)
        new->nsize = 2000;
    new->noduri = (char**) malloc(sizeof (char*) * new->nsize);
    for(i = 0; i < new->nsize; i++)
        new->noduri[i] = (char*) malloc(255);
    new->msize = 1000;
    new->muchii = (mc*)malloc(sizeof (mc) * new->msize);
    return new;
}

void free_graf(graf *g)
{
    int i;
    free(g->muchii);
    g->muchii = NULL;
    for(i = 0; i < g->nsize; i++)
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
    if(g->n == g->nsize)
    {
        g->nsize *= 2;
        g->noduri = realloc(g->noduri, g->nsize * sizeof(char *));
        int i;
        for(i = g->n; i < g->nsize; i++)
            g->noduri[i] = (char*)malloc(255);
    }
    if(!g->noduri)
        exit(2);
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
    if(g->m == g->msize)
    {
        g->msize *= 2;
        g->muchii = realloc(g->muchii, g->msize * sizeof (mc));
    }
    if(!g->muchii)
        exit(2);
    g->muchii[g->m-1].i = i;
    g->muchii[g->m-1].j = j;
    return g;
}