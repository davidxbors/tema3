//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct graf {
    int n;
    int **mat;
} graf;

graf *init(int n)
{
    graf *new = (graf*)malloc(sizeof(graf));
    new->n = n;
    new->mat = (int**)calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++)
        new->mat[i] = (int*)calloc(n, sizeof(int));
    return new;
}

void free_graf(graf *g)
{
    for(int i = 0; i < g->n; i++)
    {
        free(g->mat[i]);
        g->mat[i] = NULL;
    }
    free(g->mat);
    g->mat = NULL;
    free(g);
    g = NULL;
}

void add_edge(graf *g, int i, int j)
{
    g->mat[i-1][j-1] = 0;
}

void del_edge(graf *g, int i, int j)
{
    g->mat[i-1][j-1] = 0;
}

int in_degree(graf *g, int i)
{
    i--;
    int counter = 0;
    for(int j = 0; j < g->n; j++)
        counter += g->mat[j][i];
    return counter;

}

int ext_degree(graf *g, int i)
{
    i--;
    int counter = 0;
    for(int j = 0; j < g->n; j++)
        counter += g->mat[i][j];
    return counter;
}

int arc(graf *g, int i, int j)
{
    if(g->mat[i][j])    return 1;
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

int main()
{
    graf *g = init(5);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 2, 5);
    add_edge(g, 4, 5);
    add_edge(g, 4, 1);
    free_graf(g);
    return 0;
}
