#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{

    // if list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    //create new node
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return FAILURE;
    }

    //assign data to new node
    new->data = ndata;
    new->next = NULL;
    new->prev = NULL;

    // declare local pointers
    Dlist *temp = NULL;
    Dlist *previous = NULL;

    // if list is not empty

    // if data found at first node
    if ((*head)->data == gdata)
    {
        temp = *head;
        new->next = temp;
        temp->prev = new;
        *head = new;
        return SUCCESS;
    }
    // if data found at last node
    else if ((*tail)->data == gdata)
    {
        temp = (*tail)->prev;
        new->prev = temp;
        new->next = *tail;
        temp->next = new;
        (*tail)->prev = new;
        return SUCCESS;
    }
    // if data found in between nodes
    else
    {
        temp = *head;
        while (temp != *tail)
        {
            previous = temp;
            temp = temp->next;

            if (temp->data == gdata)
            {
                new->next = temp;
                new->prev = previous;
                temp->prev = new;
                previous->next = new;
                return SUCCESS;
            }
        }

        return DATA_NOT_FOUND;
    }
}