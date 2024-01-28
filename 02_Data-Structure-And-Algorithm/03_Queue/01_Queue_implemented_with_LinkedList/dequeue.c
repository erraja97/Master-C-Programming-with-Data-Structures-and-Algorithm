#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    //check if queue is empty then return failure
    if (*front == NULL)
    {
        return FAILURE;
    }

    //declare local pointer
    Queue_t *temp = *front;

    //check if there is only one element left in queue, if no point front to second element as first element will be removed
    if (temp != *rear)
    {
        *front = temp->link;
    }
    //if there is only one element left in queue, after dequeue operation, front and rear must point to NULL
    else
    {
        *front = NULL;
        *rear = NULL;
    }

    //free first element memory to remove it from queue
    free(temp);

    //return success if done
    return SUCCESS;
}