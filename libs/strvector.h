//
// Created by David Bors on 14.05.2021.
//

#ifndef TEMA3_STRVECTOR_H
#define TEMA3_STRVECTOR_H

#ifndef STDLIB_H
#define STBLIB_H
#include <stdlib.h>
#endif

#include <string.h>

typedef struct vector
{
    // data
    char *data;
    //list util
    struct vector *next;
    struct vector *back;
} vector;

// initializeaza un nod al listei
vector *init_vector(char *data)
{
    vector *new = (vector *)malloc(sizeof(vector));
    new->data = (char*)malloc(sizeof(data));
    strcpy(new->data, data);
    new->next = NULL;
    new->back = NULL;
    return new;
}

// adauga o muchie in lista
vector *append_string(vector *head, char *data)
{
    vector *new = init_vector(data);
    vector *counter;
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

// afiseaza toate stringurile din vector
void vector_print(vector *head)
{
    while(head)
    {
        printf("%s ", head->data);
        head = head->next;
    }
}

int is_in_vector(vector *head, char *data)
{
    int counter = 0;
    vector *i = head;
    while(i)
    {
        if(!strcmp(i->data, data))
            return counter;
        counter++;
        i = i->next;
    }
    return -1;
}

// elibereaza memoria ocupata de vector
void destroy_vector(vector *head)
{
    while(head)
    {
        vector *to_destroy = head;
        head = head->next;
        to_destroy->back = NULL;
        to_destroy->next = NULL;
        free(to_destroy->data);
        to_destroy->data = NULL;
        free(to_destroy);
        to_destroy = NULL;
    }
}

#endif //TEMA3_STRVECTOR_H
