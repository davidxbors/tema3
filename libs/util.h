//
// Created by David Bors on 21.05.2021.
//

#ifndef TEMA3_UTIL_H
#define TEMA3_UTIL_H
#include "queue.h"
#include "strvector.h"

vector *bfs(graf *g, int root, int *visited, int *counter)
{
    *counter = 0;
    Queue *q = NULL;
    vector *productie = NULL;
    q = enqueue(q, root);
    while (!is_empty(q))
    {
        int l = q->data;
        q = dequeue(q);
        if(!visited[l]) {
            ++(*counter);
            productie = append_string(productie, v_string(g->noduri, l));
            // marcheaza nodul ca vizitat
            visited[l] = 1;
            // gaseste toate legaturile nevizitate deja
            int i = 0;
            for (; i < l; i++)
                if (is_edge(g, l, i) && !visited[i]) {
                    q = enqueue(q, i);
                }
            i++;
            for (; i < g->n; i++)
                if (is_edge(g, l, i) && !visited[i]) {
                    q = enqueue(q, i);
                }
        }
    }
    return productie;
}

#endif //TEMA3_UTIL_H
