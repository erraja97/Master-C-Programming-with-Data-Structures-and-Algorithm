#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    // create new node
    Dlist *new = malloc(sizeof(Dlist));

    // check if node created or not
    if (new == NULL)
    {
        return FAILURE;
    }

    // assign value
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    // check if list is empty or not
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return SUCCESS;
}