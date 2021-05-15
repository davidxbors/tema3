//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/graf.h"

void citire1(graf*, char*);

int main()
{
    graf *g = init_graf();
    citire1(g, "test.in");
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
//            printf("%s\n", buffer);
            aux = append_string(aux, buffer);

            // elibereaza memorie odata ce nu mai am nevoie de ea
            free(buffer);
        }
        --nr_filme;

        // adauga in graf
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
        vector_print(g->noduri);
        printf("\n");
        destroy_vector(aux);
        free(ix);

       // elibereaza memorie odata ce nu mai am nevoie de ea
        free(nume_film);
    }
    fclose(in);
}