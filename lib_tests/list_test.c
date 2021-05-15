//
// Created by David Bors on 14.05.2021.
//
#include <stdio.h>
#include "../libs/list.h"
#include "../libs/strvector.h"

int main()
{
    mc *muchii = NULL;
    muchii = append_list(muchii, 1, 2);
    muchii = append_list(muchii, 1, 3);
    muchii = append_list(muchii, 1, 4);
    muchii = append_list(muchii, 2, 3);
    muchii = append_list(muchii, 3, 5);
    muchii = append_list(muchii, 2, 5);
    list_print(muchii);
    printf("muchia 1,2 : %d; muchia 2,3: %d; muchia 2,5: %d; muchia 2,4: %d\n",
           is_in_list(muchii, 1, 2), is_in_list(muchii, 2, 3), is_in_list(muchii, 2, 5),
           is_in_list(muchii, 2, 4));
    destroy_list(muchii);
    vector *noduri = NULL;
    noduri = append_string(noduri, "actor1");
    noduri = append_string(noduri, "actor2");
    noduri = append_string(noduri, "actor3");
    noduri = append_string(noduri, "actor4");
    noduri = append_string(noduri, "actor5");
    printf("actor2: %d;\n actor1: %d;\n actor5: %d;\n actor6: %d\n",
           is_in_vector(noduri, "actor2"), is_in_vector(noduri, "actor1"),
           is_in_vector(noduri, "actor5"), is_in_vector(noduri, "actor6"));
    vector_print(noduri);
    destroy_vector(noduri);
    return 0;
}
