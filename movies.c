//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/graf.h"
#include "libs/queue.h"
#include "libs/util.h"

void citire1(graf*, char*);

int main(int argc, char *argv[])
{
    graf *g = init_graf();
    citire1(g, argv[2]);
    /// rezolva cerinta
    int i, nr;
    int *visited = (int*) calloc(g->n, sizeof (int));
    for(i = 0; i < g->n; i++)
    {
        if(!visited[i])
        {
            vector *productie = bfs(g, i, visited, &nr);
            printf("%d\n", nr);
            vector_print(productie);
            printf("\n");
        }
    }
    /// debug
//    vector_print(g->noduri);
//    printf("\n");
//    list_print(g->muchii);
//    printf("\n");

    // elibereaza memorie
    destroy_graf(g);
    free(visited);
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
        vector *aux = NULL;

        fscanf(in, "%255[^\n]", nume_film);
        fscanf(in, "%d\n", &nr_actori);


        for(i = 0; i < nr_actori; i++){
            char *buffer = (char*) malloc(256);
            fscanf(in, "%255[^\n]\n", buffer);

            // adauga intr-un tablou auxiliar
            aux = append_string(aux, buffer);

            // elibereaza memorie odata ce nu mai am nevoie de ea
            free(buffer);
        }
        --nr_filme;

        // adauga in graf muchii si noduri
        // adauga noile noduri citite
        vector *vix = aux;
        int *ix = (int*)malloc(nr_actori * sizeof (int));
        int k = 0;
        while(vix)
        {
            int ret = is_in_vector(g->noduri, vix->data);
            if(ret != -1)
            {
                ix[k++] = ret;
            } else
            {
                g = add_node(g, vix->data);
                ret = is_in_vector(g->noduri, vix->data);
                ix[k++] = ret;
            }
            vix = vix->next;
        }

        // adauga noile muchii citite
        for(i = 0; i < nr_actori-1; i++)
        {
            for(j = i+1; j < nr_actori; j++)
                if(!is_in_list(g->muchii, ix[i], ix[j]))
                    g = add_edge(g, ix[i], ix[j]);
        }

       // elibereaza memorie odata ce nu mai am nevoie de ea
        free(nume_film);
        destroy_vector(aux);
        free(ix);
    }
    // inchide fisierul din care am citit
    fclose(in);
}
