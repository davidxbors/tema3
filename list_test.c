//
// Created by David Bors on 14.05.2021.
//
#include <stdio.h>
#include "list.h"

int main()
{
    mc *muchii = NULL;
    mc last;
    muchii = append_list(muchii, 1, 2);
    muchii = append_list(muchii, 1, 3);
    muchii = append_list(muchii, 1, 4);
    muchii = append_list(muchii, 2, 3);
    muchii = append_list(muchii, 3, 5);
    muchii = append_list(muchii, 2, 5);
    list_print(muchii);
    destroy_list(muchii);
    return 0;
}
