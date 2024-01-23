#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
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

    //if list not empty insert node at first
    new->next = *head;
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}