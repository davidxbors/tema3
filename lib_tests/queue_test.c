//
// Created by David Bors on 21.05.2021.
//
#include <stdio.h>
#include "../libs/queue.h"

int main()
{
    Queue *q = NULL;
    q = enqueue(q, 1);
    q = enqueue(q, 2);
    q = enqueue(q, 3);
    queue_print(q);
    q = dequeue(q);
    queue_print(q);
    destroy_queue(q);
    return 0;
}