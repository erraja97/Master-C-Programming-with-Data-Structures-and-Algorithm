#include "queue.h"

int IsQueueFull(Queue_t *q)
{
    if (q->count == q->capacity)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}

int IsQueueEmpty(Queue_t *q)
{
    if (q->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}