#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    //creaate new node and allocate memory
    Queue_t *new = malloc(sizeof(Queue_t));

    //check if node created successfully
    if (new == NULL)
    {
        return FAILURE;
    }

    //update values of data and link of new node
    new->data = data;
    new->link = NULL;

    //if queue is empty update front and rear to point to new node
    if (*front == NULL)
    {
        *front = new;
        *rear = new;
        return SUCCESS;
    }

    //declare local pointer
    Queue_t *temp = *front;

    //if queue is not empty traverse till last element and add new element after it
    while (temp != *rear)
    {
        temp = temp->link;
    }

    temp->link = new;
    *rear = new;

    //return success if done adding new element in queue
    return SUCCESS;
}