//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libs/graf.h"
#include "libs/queue.h"
#include "libs/util.h"

void citire1(graf*, char*);

int compare (const void * a, const void * b ) {
  return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[])
{
    graf *g = init_graf();
    citire1(g, argv[2]);
    /// rezolva cerinta
    int i, nr;
    int *visited = (int*) calloc(g->n, sizeof (int));
    vector *productie = NULL;
    vector *productie_max = NULL;
    int max = INT_MIN;

    for(i = 0; i < g->n; i++)
    {
        if(!visited[i])
        {
            productie = bfs(g, i, visited, &nr, productie);
            /*
	    printf("%d\n", nr);
            vector_print(productie);
            printf("\n");
	    */
            if(nr > max)
	    {
		    max = nr;
		    destroy_vector(productie_max);
		    productie_max = productie;
	    } else 
	    {
//	    	destroy_vector(productie);
		productie = NULL;
	    }
        }
    }

    char **prod = (char**) malloc(max * sizeof(char*));
    vector *counter = productie_max;
    for(i = 0; i < max; i++)
    {
	    prod[i] = (char*) malloc(250 * sizeof(char));
	    strcpy(prod[i], counter->data);
	    counter = counter->next;
    }
    qsort(prod, max, sizeof(char*), compare);


    FILE *out = fopen(argv[3], "w");
    if(out == NULL)
    {
	    perror("file open gives err\n");
	    return 2;
    }
    fprintf(out, "%d\n", max);
    for(i = 0; i < max; i++)
	    fprintf(out, "%s\n", prod[i]);
    fclose(out);
    
    /// debug
//    vector_print(g->noduri);
//    printf("\n");
//    list_print(g->muchii);
//    printf("\n");

    // elibereaza memorie
    //destroy_graf(g);
    //free(visited);
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
        //free(nume_film);
        //destroy_vector(aux);
        //free(ix);
    }
    // inchide fisierul din care am citit
    fclose(in);
}
