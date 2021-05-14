//
// Created by David Bors on 13.05.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *filename = "test.in";
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
    return 0;
}
