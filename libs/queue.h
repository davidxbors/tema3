//
// Created by David Bors on 21.05.2021.
//

#ifndef TEMA3_QUEUE_H
#define TEMA3_QUEUE_H

#ifndef STDLIB_H
#define STBLIB_H
#include <stdlib.h>
#endif

typedef struct cell
{
    int data;
    struct cell *next;
} Queue;

int is_empty(Queue *q)
{
    if (q == NULL)
        return 1;
    return 0;
}

Queue *new_element(int data)
{
    Queue *new = (Queue *)malloc(sizeof(Queue));
    new->data = data;
    new->next = NULL;
    return new;
}

Queue *enqueue(Queue *q, int data)
{
    if (is_empty(q))
        return new_element(data);

    Queue *tmp = q;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new_element(data);

    return q;
}

Queue *dequeue(Queue *q)
{
    if (is_empty(q))
        return NULL;

    Queue *tmp = q;
    q = q->next;
    free(tmp);

    return q;
}

void queue_print(Queue *q)
{
    if (q == NULL)
        return;
    printf("%d ", q->data);
    queue_print(q->next);
}

void destroy_queue(Queue *q)
{
    while(!is_empty(q))
        q = dequeue(q);
}
#endif //TEMA3_QUEUE_H
