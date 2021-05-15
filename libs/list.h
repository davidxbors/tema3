//
// Created by David Bors on 14.05.2021.
//

#ifndef TEMA3_LIST_H
#define TEMA3_LIST_H

#ifndef STDLIB_H
#define STBLIB_H
#include <stdlib.h>
#endif

// structura listei de muchii
typedef struct list
{
    // data
    int i;
    int j;
    // list util
    struct list *next;
    struct list *back;
}mc;

// initializeaza un nod al listei de muchii
mc *init_node(int i, int j)
{
    mc *new = (mc *)malloc(sizeof(mc));
    new->i = i;
    new->j = j;
    new->next = NULL;
    new->back = NULL;
    return new;
}

// adauga o muchiei in lista
mc *append_list(mc *head, int i, int j)
{
    mc *new = init_node(i, j);
    mc *counter;
    if(head == NULL)
    {
        return new;
    }
    else
    {
        counter = head;
        while(counter->next != NULL)
            counter = counter->next;
        counter->next = new;
        new->back = counter;
        return head;
    }
}

// afiseaza toate muchiile din lista
void list_print(mc *head)
{
    while(head)
    {
        printf("(%d, %d); ", head->i, head->j);
        head = head->next;
    }
}

short int is_in_list(mc *head, int i, int j)
{
    mc *ix = head;
    while(ix)
    {
        if(ix->i == i && ix->j == j)
            return 1;
        ix = ix->next;
    }
    return 0;
}

// elibereaza memoria ocupata de lista
void destroy_list(mc *head)
{
    while(head)
    {
        mc *to_destroy = head;
        head = head->next;
        to_destroy->back = NULL;
        to_destroy->next = NULL;
        free(to_destroy);
        to_destroy = NULL;
    }
}
#endif //TEMA3_LIST_H
